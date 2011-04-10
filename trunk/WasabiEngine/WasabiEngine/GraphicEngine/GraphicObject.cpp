/* 
 * File:   GraphicObject.cpp
 * Author: Fran_2
 * 
 * Created on 3 de enero de 2011, 18:50
 */

#include "GraphicObject.h"
#include "GraphicEngine.h"
#include "SceneNode.h"

using namespace WasabiEngine;

GraphicObject::GraphicObject() {
    sceneNode = NULL;
}

GraphicObject::GraphicObject(const GraphicObject& orig) {
    // Not allowed
}

GraphicObject::~GraphicObject() {
    clear();
}

Camera* GraphicObject::createCamera(const std::string& name) {
    Camera* camera = GraphicEngine::getInstance()->sceneManager.createCamera(name);
    cameras.push_back(camera);
    sceneNode->attachObject(camera);
    return camera;
}

void GraphicObject::destroyCamera(Camera* camera) {
    std::list<Camera*>::iterator i = std::find(cameras.begin(), cameras.end(), camera);
    if (i != cameras.end()) {
        cameras.erase(i);
        sceneNode->detachObject(camera);
        GraphicEngine::getInstance()->sceneManager.destroyCamera(camera);
    }
}

Light* GraphicObject::createLight() {
    Light* light = GraphicEngine::getInstance()->sceneManager.createLight();
    lights.push_back(light);
    sceneNode->attachObject(light);
    return light;
}

void GraphicObject::destroyLight(Light* light) {
    std::list<Light*>::iterator i = std::find(lights.begin(), lights.end(), light);
    if (i != lights.end()) {
        lights.erase(i);
        sceneNode->detachObject(light);
        GraphicEngine::getInstance()->sceneManager.destroyLight(light);
    }
}

Entity* GraphicObject::createEntity(const std::string& meshName) {
    Entity* entity = GraphicEngine::getInstance()->sceneManager.createEntity(meshName);
    entities.push_back(entity);
    sceneNode->attachObject(entity);
    return entity;
}

Entity* GraphicObject::createEntity(PrefabType type) {
    Entity* entity = GraphicEngine::getInstance()->sceneManager.createEntity(type);
    entities.push_back(entity);
    sceneNode->attachObject(entity);
    return entity;
}

void GraphicObject::destroyEntity(Entity* entity) {
    std::list<Entity*>::iterator i = std::find(entities.begin(), entities.end(), entity);
    if (i != entities.end()) {
        entities.erase(i);
        sceneNode->detachObject(entity);
        GraphicEngine::getInstance()->sceneManager.destroyEntity(entity);
    }
}

ParticleSystem* GraphicObject::createParticleSystem(const ParticleSystemDef& def)
{
    ParticleSystem* system = GraphicEngine::getInstance()->sceneManager.createParticleSystem(def);
    particleSystems.push_back(system);
    sceneNode->attachObject(system);
    return system;
}

void GraphicObject::destroyParticleSystem(ParticleSystem* system)
{
    std::list<ParticleSystem*>::iterator i = std::find(particleSystems.begin(), particleSystems.end(), system);
    if (i != particleSystems.end()) {
        particleSystems.erase(i);
        sceneNode->detachObject(system);
        GraphicEngine::getInstance()->sceneManager.destroyParticleSystem(system);
    }
}

GraphicObject* GraphicObject::createChild(const WasVec3d& positionRelativeToParent) {
    GraphicObject* object = GraphicEngine::getInstance()->objectFactory.createResource();
    object->setId(id);
    object->sceneNode = sceneNode->createChild(positionRelativeToParent);
    object->setPosition(positionRelativeToParent);
    children.push_back(object);
    return object;
}

void GraphicObject::removeChild(GraphicObject* child) {
    std::list<GraphicObject*>::iterator i = std::find(children.begin(), children.end(), child);
    if (i != children.end()) {
        sceneNode->removeChild(child->sceneNode);
        GraphicEngine::getInstance()->objectFactory.returnResource(child);
        children.erase(i);
    }
}

void GraphicObject::removeAllChildren() {
    for (std::list<GraphicObject*>::iterator i = children.begin(); i != children.end(); i++) {
        removeChild(*i);
    }
}

void GraphicObject::prepare() {
    //prepare is called only by GraphicEngine::createObject()
    sceneNode = GraphicEngine::getInstance()->sceneManager.getRootSceneNode()->createChild();
}

void GraphicObject::clear() {
    std::list<Camera*>::iterator currentCamera = cameras.begin();
    std::list<Camera*>::iterator nextCamera = currentCamera++;
    for (unsigned int i = 0; i < cameras.size(); i++) {
        destroyCamera(*currentCamera);
        currentCamera = nextCamera;
        nextCamera++;
    }
    cameras.clear();

    std::list<Light*>::iterator currentLight = lights.begin();
    std::list<Light*>::iterator nextLight = currentLight++;
    for (unsigned int i = 0; i < lights.size(); i++) {
        destroyLight(*currentLight);
        currentLight = nextLight;
        nextLight++;
    }
    lights.clear();

    std::list<Entity*>::iterator currentEntity = entities.begin();
    std::list<Entity*>::iterator nextEntity = currentEntity++;
    for (unsigned int i = 0; i < entities.size(); i++) {
        destroyEntity(*currentEntity);
        currentEntity = nextEntity;
        nextEntity++;
    }
    entities.clear();

    std::list<ParticleSystem*>::iterator currentSystem = particleSystems.begin();
    std::list<ParticleSystem*>::iterator nextSystem = currentSystem++;
    for (unsigned int i = 0; i < entities.size(); i++) {
        destroyParticleSystem(*currentSystem);
        currentSystem = nextSystem;
        nextSystem++;
    }
    particleSystems.clear();

    removeAllChildren();
    if (sceneNode) {
        sceneNode->getParentSceneNode()->removeChild(sceneNode);
        sceneNode = NULL;
    }
}
