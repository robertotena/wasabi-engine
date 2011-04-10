/* 
 * File:   PhysicEngine.h
 * Author: Roberto
 *
 * Created on 4 de enero de 2011, 0:43
 */

#ifndef PHYSICENGINE_H
#define	PHYSICENGINE_H

#include <list>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/PhysicEngine/PhysicObject.h>
#include <WasabiEngine/PhysicEngine/Box2dWorld.h>

namespace WasabiEngine {

    class PhysicEngine {
    private:
        Box2dWorld world;
        PropertyMap<PhysicObject*> objects;
        ResourceFactory<PhysicObject> factory;
        PhysicEngine();
    public:
        ~PhysicEngine();
        static PhysicEngine* getInstance();
        void step();
        PhysicObject* getItem(const int& id);
        PhysicObject* createObject(const int& id);
        void destroyObject(PhysicObject* object);
        std::list<PhysicObject*> queryAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound);
        bool queryIsZoneEmptyAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound);
        /**
         * Initializes the engine
         */
        void init();
        /**
         * Clears the engine contents
         */
        void finish();
        
        friend class PhysicObject;
    };

    inline std::list<PhysicObject*> PhysicEngine::queryAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound) {
        return world.queryAABB(lowerBound, upperBound);
    }

    inline bool PhysicEngine::queryIsZoneEmptyAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound) {
        return world.queryIsZoneEmptyAABB(lowerBound, upperBound);
    }
}

#endif	/* PHYSICENGINE_H */

