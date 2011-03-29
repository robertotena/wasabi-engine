/* 
 * File:   PhysicObject.h
 * Author: Roberto
 *
 * Created on 4 de enero de 2011, 0:14
 */

#ifndef PHYSICOBJECT_H
#define	PHYSICOBJECT_H

#include <map>
#include <string>
#include <Box2D/Box2D.h>
#include <WasabiEngine/Utils/MathUtil.h>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/PhysicEngine/PhysicDefinitions.h>
#include <WasabiEngine/PhysicEngine/ObjectContactListener.h>

namespace WasabiEngine {

    /**
     * Grants physic behaviour to a game object.
     */
    class PhysicObject {
    private:
        static b2World* world;
        unsigned int id;
        std::map<std::string, b2Body*> bodies;
        std::map<std::string, b2Joint*> joints;
        b2Body* mainBody;
        ObjectContactListener* contactListener;
        bool generateContacts;

        PhysicObject(const PhysicObject& object);
        ObjectContactListener* getContactListener();
        void setContactListener(ObjectContactListener* contactListener);
    public:
        PhysicObject();
        ~PhysicObject();
        // Create functions
        b2Body* createBody(const std::string& name, const PhysicBodyDef& definition);
        b2Joint* createJoint(const std::string& name, const PhysicJointDef& definition);
        void destroyBody(const std::string& name);
        void destroyJoint(const std::string& name);
        b2Body* getBody(const std::string& name);
        b2Joint* getJoint(const std::string& name);
        int getBodyCount() const;
        int getJointCount() const;
        unsigned int getId() const;
        void setId(const unsigned int& id);
        b2Body* getMainBody();
        void setMainBody(b2Body* body);
        void clear();
        
        /**
         * If active, generates contact events for each collision between bodies.
         * @param value Activate contact events
         */
        void generateContactEvents(bool value);

        // Physic functions

        /**
         * Get world position of the main body.
         * @param body
         * @return
         */
        WasVec2d getPosition();
        /**
         * Get the rotation of the main body
         * @param body
         * @return
         */
        Radian getRotation();
        /**
         * Set the linear velocity of the main body in m/s.
         * @param body
         * @return
         */
        void setLinearVelocity(const WasVec2d& velocity);
        /**
         * Set the linear velocity of a body in m/s.
         * @param body
         * @return
         */
        void setLinearVelocity(const WasVec2d& velocity, b2Body* body);
        /**
         * Get the linear velocity of the main body in m/s.
         * @param body
         * @return
         */
        WasVec2d getLinearVelocity() const;
        /**
         * Get the linear velocity of a body in m/s.
         * @param body
         * @return
         */
        WasVec2d getLinearVelocity(const b2Body* body) const;
        /**
         * Set the angular velocity of the main body in rad/s.
         * @param body
         * @return
         */
        void setAngularVelocity(float omega);
        /**
         * Set the angular velocity of a body in rad/s.
         * @param body
         * @return
         */
        void setAngularVelocity(float omega, b2Body* body);
        /**
         * Get the angular velocity of the main body in rad/s.
         * @param body
         * @return
         */
        float getAngularVelocity() const;
        /**
         * Get the angular velocity of a body in rad/s.
         * @param body
         * @return
         */
        float getAngularVelocity(const b2Body* body) const;
        /**
         * Gets de body mass
         * @return Mass in KG
         */
        float getMass() const;
        /**
         * Apply a linear force to the main body.
         * @param forceWorldVector Force vector in newtons and world coordinates.
         * @param worldPoint The world point where the force is applied.
         */
        void applyForce(const WasVec2d& forceWorldVector, const WasVec2d& worldPoint);
        /**
         * Apply a torque to the main body
         * @param torque Torque in N·m
         */
        void applyTorque(const float& torque);
        /**
         * Translate a world point to local coordinates.
         * @param worldPoint
         * @return
         */
        WasVec2d getLocalPoint(const WasVec2d& worldPoint) const;
        /**
         * Translate a local point to world coordinates.
         * @param localPoint
         * @return
         */
        WasVec2d getWorldPoint(const WasVec2d& localPoint) const;
        /**
         * Translate a world vector to local coordinates.
         * @param worldVector
         * @return
         */
        WasVec2d getLocalVector(const WasVec2d& worldVector) const;
        /**
         * Translate a local vector to world vector.
         * @param localVector
         * @return
         */
        WasVec2d getWorldVector(const WasVec2d& localVector) const;

        /**
         * Check if there is a clear line between the body and a worldPoint.
         * @param worldPoint The desired point.
         * @return true if is visible.
         */
        bool isVisible(const WasVec2d& worldPoint);

        friend class PhysicEngine;
        friend class WorldContactListener;
        friend class Sensor;
    };

    inline int PhysicObject::getBodyCount() const {
        return bodies.size();
    }

    inline int PhysicObject::getJointCount() const {
        return joints.size();
    }

    inline unsigned int PhysicObject::getId() const {
        return id;
    }

    inline void PhysicObject::setId(const unsigned int& id) {
        this->id = id;
    }

    inline void PhysicObject::setMainBody(b2Body* body) {
        mainBody = body;
    }

    inline b2Body* PhysicObject::getMainBody() {
        return mainBody;
    }

    inline ObjectContactListener* PhysicObject::getContactListener() {
        return contactListener;
    }

    inline void PhysicObject::setContactListener(ObjectContactListener* contactListener) {
        this->contactListener = contactListener;
    }

    inline WasVec2d PhysicObject::getPosition() {
        WasVec2d pos;

        if (mainBody != NULL) {
            b2Vec2 p = mainBody->GetPosition();
            pos.x = p.x;
            pos.y = p.y;
        }

        return pos;
    }

    inline Radian PhysicObject::getRotation() {
        if (mainBody != NULL)
            return Radian(mainBody->GetAngle());
        else
            return Radian(0.f);
    }

    inline void PhysicObject::setLinearVelocity(const WasVec2d& velocity) {
        setLinearVelocity(velocity, mainBody);
    }

    inline void PhysicObject::setLinearVelocity(const WasVec2d& velocity, b2Body* body) {
        body->SetLinearVelocity(velocity);
    }

    inline WasVec2d PhysicObject::getLinearVelocity() const {
        return getLinearVelocity(mainBody);
    }

    inline WasVec2d PhysicObject::getLinearVelocity(const b2Body* body) const {
        return body->GetLinearVelocity();
    }

    inline void PhysicObject::setAngularVelocity(float omega) {
        setAngularVelocity(omega, mainBody);
    }

    inline void PhysicObject::setAngularVelocity(float omega, b2Body* body) {
        body->SetAngularVelocity(omega);
    }

    inline float PhysicObject::getAngularVelocity() const {
        return getAngularVelocity(mainBody);
    }

    inline float PhysicObject::getAngularVelocity(const b2Body* body) const {
        return body->GetAngularVelocity();
    }

    inline float PhysicObject::getMass() const {
        //FIXME: Hay que tener en cuenta los otros cuerpos
        return mainBody->GetMass();
    }

    inline void PhysicObject::applyForce(const WasVec2d& forceWorldVector, const WasVec2d& worldPoint) {
        mainBody->ApplyForce(forceWorldVector, worldPoint);
    }

    inline void PhysicObject::applyTorque(const float& torque) {
        mainBody->ApplyTorque(torque);
    }

    inline WasVec2d PhysicObject::getLocalPoint(const WasVec2d& worldPoint) const {
        return mainBody->GetLocalPoint(worldPoint);
    }

    inline WasVec2d PhysicObject::getWorldPoint(const WasVec2d& localPoint) const {
        return mainBody->GetWorldPoint(localPoint);
    }

    inline WasVec2d PhysicObject::getLocalVector(const WasVec2d& worldVector) const {
        return mainBody->GetLocalVector(worldVector);
    }

    inline WasVec2d PhysicObject::getWorldVector(const WasVec2d& localVector) const {
        return mainBody->GetWorldVector(localVector);
    }
}

#endif	/* PHYSICOBJECT_H */

