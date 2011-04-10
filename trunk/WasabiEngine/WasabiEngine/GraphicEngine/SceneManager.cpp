/* 
 * File:   SceneManager.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:32
 */

#include "SceneManager.h"

using namespace WasabiEngine;

SceneManager::SceneManager() : cameraFactory(5) {
    worldGeometry = NULL;
    activeCamera = NULL;
}

SceneManager::SceneManager(const SceneManager& orig) {
    // not allowed
}

SceneManager::~SceneManager() {
    if(worldGeometry)
        destroyEntity(worldGeometry);
    if(activeCamera)
        destroyCamera(activeCamera);
}

Camera* SceneManager::createCamera(const std::string& name) {
    Camera* camera = cameraFactory.createResource();
    cameras.set(name, camera);
    camera->name = name;
    if(activeCamera == NULL)
        setActiveCamera(camera);
    return camera;
}

void SceneManager::destroyCamera(Camera* camera) {
    cameras.remove(camera->getName());
    cameraFactory.returnResource(camera);
}

void SceneManager::destroyCamera(const std::string& name) {
    Camera** camera = cameras.get(name);
    cameras.remove(name);
    if(camera != NULL)
        cameraFactory.returnResource(*camera);
}

Camera* SceneManager::getActiveCamera()
{
    return activeCamera;
}

void SceneManager::setActiveCamera(Camera* camera)
{
    activeCamera = camera;
}

void SceneManager::setActiveCamera(const std::string& name)
{
    Camera** camera = cameras.get(name);
    if(camera != NULL)
    {
        setActiveCamera(*camera);
    }
}

Camera* SceneManager::getCamera(const std::string& name)
{
    Camera** camera = cameras.get(name);
    if(camera != NULL)
        return *camera;
    return NULL;
}

Light* SceneManager::createLight() {
    //FIXME
    return NULL;
}

void SceneManager::destroyLight(Light* light) {
    //FIXME
}

Entity* SceneManager::createEntity(const std::string& meshName) {
    Entity* entity = entityFactory.createResource();
    entity->setMesh(MeshLoader::load(meshName));
    return entity;
}

Entity* SceneManager::createEntity(PrefabType type) {
    Entity* entity = entityFactory.createResource();
    entity->setMesh(MeshLoader::load(type));
    return entity;
}

void SceneManager::destroyEntity(Entity* entity) {
    entityFactory.returnResource(entity);
}

ParticleSystem* SceneManager::createParticleSystem(const ParticleSystemDef& def)
{
    if(def.getType() == PARTICLES_LINEAR)
        particleSystems.push_back(new LinearParticleSystem(def));
    else if(def.getType() == PARTICLES_RADIAL)
        particleSystems.push_back(new RadialParticleSystem(def));
}

void SceneManager::destroyParticleSystem(ParticleSystem* system)
{
    std::list<ParticleSystem*>::iterator it = std::find(particleSystems.begin(), particleSystems.end(), system);
    if(it != particleSystems.end())
    {
        particleSystems.erase(it);
        delete(*it);
    }
}

void SceneManager::setAmbientLight(const ColourValue& colour, const WasVec3d& position) {
    renderSystem.setAmbientLight(colour, position);
}

void SceneManager::setFog(FogMode mode, const ColourValue& colour, float density, float linearStart, float linearEnd) {
    renderSystem.setFog(mode,colour,density,linearStart,linearEnd);
}

void SceneManager::setWorldGeometry(const std::string& filePath){
    if(worldGeometry != NULL)
        rootNode.detachObject(worldGeometry);
    worldGeometry = createEntity(filePath);
    rootNode.attachObject(worldGeometry);
}

SceneNode* SceneManager::getRootSceneNode() {
    return &rootNode;
}

void SceneManager::render() {
    renderSystem.render(&rootNode, activeCamera);
}
