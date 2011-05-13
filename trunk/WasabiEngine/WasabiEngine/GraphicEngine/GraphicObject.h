/* 
 * File:   GraphicObject.h
 * Author: Fran_2
 *
 * Created on 3 de enero de 2011, 18:50
 */

#ifndef GRAPHICOBJECT_H
#define	GRAPHICOBJECT_H

#include <list>
#include <algorithm>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/GraphicEngine/SceneManager.h>
#include <WasabiEngine/GraphicEngine/SceneNode.h>
#include <WasabiEngine/GraphicEngine/Quaternion.h>

namespace WasabiEngine {

    class Camera;
    class Light;
    class Entity;
    class ParticleSystem;
    
    /**
     * A graphic object is a renderable object that can contain more objects or
     * lights, cameras and entities. His position and orientation is updated every
     * frame.
     */
    class GraphicObject {
    private:
        unsigned int id;
        std::list<GraphicObject*> children;
        std::list<Camera*> cameras;
        std::list<Light*> lights;
        std::list<Entity*> entities;
        std::list<ParticleSystem*> particleSystems;
        SceneNode* sceneNode;

        GraphicObject();
        GraphicObject(const GraphicObject& orig);
    public:
        ~GraphicObject();
        int getId();
        void setId(const int& id);
        Camera* createCamera(const std::string& name);
        void destroyCamera(Camera* camera);
        //LightPoint* createLightPoint();
        //void destroyLight(Light* light);
        Entity* createEntity(const std::string& meshName);
        Entity* createEntity(PrefabType type);
        void destroyEntity(Entity* entity);
        ParticleSystem* createParticleSystem(const ParticleSystemDef* def);
        void destroyParticleSystem(ParticleSystem* particleSystem);
        WasVec3d getPosition();
        void setPosition(const WasVec3d& positionRelativeToParent);
        const Quaternion& getOrientation();
        void setOrientation(const Quaternion& q);
        void scale(const WasVec3d& scale);
        GraphicObject* createChild(const WasVec3d& positionRelativeToParent = WasVec3d::ZERO);
        void removeChild(GraphicObject* child);
        void removeAllChildren();
        void showBoundingBox(bool show);
        void setVisible(bool visible);
        bool isVisible() const;
        void prepare();
        void clear();

        friend class ResourceFactory<GraphicObject>;
    };

    inline int GraphicObject::getId() {
        return id;
    }

    inline void GraphicObject::setId(const int& id) {
        this->id = id;
    }

    inline WasVec3d GraphicObject::getPosition() {
        return sceneNode->getPosition();
    }

    inline void GraphicObject::setPosition(const WasVec3d& positionRelativeToParent) {
        sceneNode->setPosition(positionRelativeToParent);
    }

    inline const Quaternion& GraphicObject::getOrientation() {
        return sceneNode->getOrientation();
    }

    inline void GraphicObject::setOrientation(const Quaternion& q) {
        sceneNode->setOrientation(q);
    }

    inline void GraphicObject::scale(const WasVec3d& scale){
        sceneNode->scale(scale);
    }
    
    inline void GraphicObject::showBoundingBox(bool show) {
        sceneNode->showBoundingBox(show);
    }

    inline void GraphicObject::setVisible(bool visible) {
        sceneNode->setVisible(visible);
    }

    inline bool GraphicObject::isVisible() const {
        return sceneNode->isVisible();
    }
}
#endif	/* GRAPHICOBJECT_H */
