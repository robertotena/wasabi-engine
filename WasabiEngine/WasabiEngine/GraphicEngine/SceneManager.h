/* 
 * File:   SceneManager.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:32
 */

#ifndef SCENEMANAGER_H
#define	SCENEMANAGER_H

#include <string>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/GraphicEngine/Mesh.h>
#include <WasabiEngine/GraphicEngine/Camera.h>
#include <WasabiEngine/GraphicEngine/ColourValue.h>
#include <WasabiEngine/GraphicEngine/Entity.h>
#include <WasabiEngine/GraphicEngine/LightPoint.h>
#include <WasabiEngine/GraphicEngine/RenderSystem.h>
#include <WasabiEngine/GraphicEngine/MeshLoader.h>
#include <WasabiEngine/GraphicEngine/SceneNode.h>
#include <WasabiEngine/GraphicEngine/ParticleSystem.h>
#include <WasabiEngine/GraphicEngine/LinearParticleSystem.h>
#include <WasabiEngine/GraphicEngine/RadialParticleSystem.h>

namespace WasabiEngine {

    /**
     * The scene manager is the charged of manage the scene tree and control the
     * life cycle of SceneNodes.
     */
    class SceneManager {
    private:
        SceneNode rootNode;
        Camera* activeCamera;
        Entity* worldGeometry;
        PropertyMap<Camera*, std::string> cameras;
        RenderSystem renderSystem;
        ResourceFactory<Entity> entityFactory;
        ResourceFactory<Camera> cameraFactory;
        std::list<ParticleSystem*> particleSystems; //Particle systems have no factories due the amount of memory requiered
        std::list<Light*> lights;
        
        SceneManager(const SceneManager& orig);
    public:
        SceneManager();
        virtual ~SceneManager();
        Camera* createCamera(const std::string& name);
        void destroyCamera(Camera* camera);
        void destroyCamera(const std::string& name);
        Camera* getActiveCamera();
        void setActiveCamera(Camera* camera);
        void setActiveCamera(const std::string& name);
        Camera* getCamera(const std::string& name);
        LightPoint* createLightPoint();
        void destroyLight(Light* light);
        Entity* createEntity(const std::string& meshName);
        Entity* createEntity(PrefabType type);
        void destroyEntity(Entity* entity);
        ParticleSystem* createParticleSystem(const ParticleSystemDef* def);
        void destroyParticleSystem(ParticleSystem* system);
        void setAmbientLight(const ColourValue& colour, const WasVec3d& position);
        void setFog(FogMode mode, const ColourValue& colour, float density, float linearStart, float linearEnd);
        void setWorldGeometry(const std::string& filePath);
        SceneNode* getRootSceneNode();
        void render();

        friend class GraphicEngine;
    };
}
#endif	/* SCENEMANAGER_H */

