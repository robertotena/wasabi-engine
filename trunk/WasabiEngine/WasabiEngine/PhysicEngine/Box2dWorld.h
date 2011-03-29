/* 
 * File:   Box2dWorld.h
 * Author: Fran_2
 *
 * Created on 5 de diciembre de 2010, 19:51
 */

#ifndef BOX2DWORLD_H
#define	BOX2DWORLD_H

#include <list>
#include <Box2D/Box2D.h>
#include <WasabiEngine/PhysicEngine/WorldContactListener.h>

namespace WasabiEngine {

    class Box2dWorld {
    private:
        b2World* world;
        WorldContactListener worldContactListener;
        float32 timeStep;
        int32 velocityIterations;
        int32 positionIterations;
    public:
        Box2dWorld();
        Box2dWorld(const Box2dWorld& orig);
        ~Box2dWorld();
        void step();
        void setGravity(float x, float y);
        b2Body* createBody(PhysicObject* object, const PhysicBodyDef& definition);
        b2Joint* createJoint(const PhysicJointDef& definition);
        void destroyBody(b2Body* body);
        void destroyJoint(b2Joint* joint);

        b2World* getB2World() {
            return world;
        }

        void setTimeStep(float timeStep) {
            this->timeStep = timeStep;
        }

        float32 getTimeStep() {
            return timeStep;
        }

        void setVelocityIterations(int velocityIterations) {
            this->velocityIterations = velocityIterations;
        }

        int32 getVelocityIterations() {
            return velocityIterations;
        }

        void setPositionIterations(int positionIterations) {
            this->positionIterations = positionIterations;
        }

        int32 getPositionIterations() {
            return positionIterations;
        }

        std::list<PhysicObject*> queryAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound);
        bool queryIsZoneEmptyAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound);

        friend class PhysicObject;
    };
}

#endif	/* BOX2DWORLD_H */

