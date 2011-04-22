/* 
 * File:   PhysicObject.cpp
 * Author: Roberto
 * 
 * Created on 4 de enero de 2011, 0:14
 */

#include "PhysicObject.h"
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>

using namespace WasabiEngine;

b2World* PhysicObject::world = NULL;

PhysicObject::PhysicObject() {
    id = -1;
    mainBody = NULL;
    contactListener = NULL;
    generateContacts = false;
}

PhysicObject::PhysicObject(const PhysicObject& object) {
    //Not allowed
    mainBody = NULL;
    contactListener = NULL;
}

PhysicObject::~PhysicObject() {
    clear();
}

b2Body* PhysicObject::createBody(const std::string& name, const PhysicBodyDef& definition) {
    b2Body* body = PhysicEngine::getInstance()->world.createBody(this, definition);
    if (mainBody == NULL)
        mainBody = body;
    bodies[name] = body;

    return body;
}

b2Joint* PhysicObject::createJoint(const std::string& name, const PhysicJointDef& definition) {
    b2Joint* joint = PhysicEngine::getInstance()->world.createJoint(definition);

    PhysicObject* bodyAnchor = (PhysicObject*) (definition.body1->GetUserData());
    if (bodyAnchor != this)
        bodyAnchor->joints[name] = joint;
    bodyAnchor = (PhysicObject*) (definition.body2->GetUserData());
    if (bodyAnchor != this)
        bodyAnchor->joints[name] = joint;
    joints[name] = joint;

    return joint;
}

void PhysicObject::destroyBody(const std::string& name) {
    std::map<std::string, b2Body*>::iterator i = bodies.find(name);
    if (i != bodies.end()) {
        bodies.erase(i);
        PhysicEngine::getInstance()->world.destroyBody(i->second);
    }
}

void PhysicObject::destroyJoint(const std::string& name) {
    std::map<std::string, b2Joint*>::iterator i = joints.find(name);
    if (i != joints.end()) {
        if (i->second->GetBodyA() && (PhysicObject*) i->second->GetBodyA()->GetUserData() != this)
            ((PhysicObject*) i->second->GetBodyA()->GetUserData())->joints.erase(i->first);
        if (i->second->GetBodyB() && (PhysicObject*) i->second->GetBodyB()->GetUserData() != this)
            ((PhysicObject*) i->second->GetBodyB()->GetUserData())->joints.erase(i->first);
        joints.erase(i);
        PhysicEngine::getInstance()->world.destroyJoint(i->second);
    }
}

b2Body* PhysicObject::getBody(const std::string& name) {
    std::map<std::string, b2Body*>::iterator i = bodies.find(name);
    if (i != bodies.end()) {
        return i->second;
    }
    return NULL;
}

b2Joint* PhysicObject::getJoint(const std::string& name) {
    std::map<std::string, b2Joint*>::iterator i = joints.find(name);
    if (i != joints.end()) {
        return i->second;
    }
    return NULL;
}

namespace {

    class VisibleRayCastCallback : public b2RayCastCallback {
    public:
        bool visible;

        VisibleRayCastCallback() {
            visible = true;
        }

        float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) {
            visible = false;
            return fraction;
        }
    };
}

bool PhysicObject::isVisible(const WasVec2d& worldPoint) {
    VisibleRayCastCallback callback;
    //Condicion para evitar el fallo de asercion de box2d.
    WasVec2d v = mainBody->GetPosition() - worldPoint;
    float lenghtSquared = v.x * v.x + v.y * v.y;
    if (lenghtSquared > 0.5f) {
        world->RayCast(&callback, mainBody->GetPosition(), (b2Vec2) worldPoint);
        return callback.visible;
    } else
        return true;
}

void PhysicObject::clear() {
    for (std::map<std::string, b2Joint*>::iterator i = joints.begin(); i != joints.end(); i++) {
        if (i->second->GetBodyA() && (PhysicObject*) i->second->GetBodyA()->GetUserData() != this)
            ((PhysicObject*) i->second->GetBodyA()->GetUserData())->joints.erase(i->first);
        if (i->second->GetBodyB() && (PhysicObject*) i->second->GetBodyB()->GetUserData() != this)
            ((PhysicObject*) i->second->GetBodyB()->GetUserData())->joints.erase(i->first);
        PhysicEngine::getInstance()->world.destroyJoint(i->second);
    }
    joints.clear();

    for (std::map<std::string, b2Body*>::iterator i = bodies.begin(); i != bodies.end(); i++)
        PhysicEngine::getInstance()->world.destroyBody(i->second);
    bodies.clear();

    mainBody = NULL;
//    generateContactEvents(false);
}

void PhysicObject::generateContactEvents(bool value) {
    generateContacts = value;
    if (generateContacts == true) {
        if (contactListener == NULL) {
            contactListener = new ObjectContactListener(id);
        }
    } else if (contactListener != NULL) {
        delete contactListener;
        contactListener = NULL;
    }
}
