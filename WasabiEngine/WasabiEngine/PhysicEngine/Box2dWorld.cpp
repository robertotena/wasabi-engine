/* 
 * File:   Box2dWorld.cpp
 * Author: Fran_2
 * 
 * Created on 5 de diciembre de 2010, 19:51
 */

#include "Box2dWorld.h"
#include "PhysicEngine.h"

using namespace WasabiEngine;

Box2dWorld::Box2dWorld() {
    b2Vec2 gravity(0.0f, 0.0f); //No gravity
    bool doSleep = true;
    world = new b2World(gravity, doSleep);
    world->SetContactListener(&worldContactListener);

    timeStep = 1.0f / 60.0f;
    velocityIterations = 10;
    positionIterations = 10;
}

Box2dWorld::Box2dWorld(const Box2dWorld& orig) {
}

Box2dWorld::~Box2dWorld() {
    delete world;
}

void Box2dWorld::step() {
    world->Step(timeStep, velocityIterations, positionIterations);
}

void Box2dWorld::setGravity(float x, float y) {
    world->SetGravity(b2Vec2(x, y));
}

b2Body* Box2dWorld::createBody(PhysicObject* object, const PhysicBodyDef& definition) {
    b2Body* body = NULL;

    // creating the body
    b2BodyDef bodyDefinition;
    if (definition.bodyType == PHYSIC_STATIC_BODY)
        bodyDefinition.type = b2_staticBody;
    else if (definition.bodyType == PHYSIC_KINEMATIC_BODY)
        bodyDefinition.type = b2_kinematicBody;
    else if (definition.bodyType == PHYSIC_DYNAMIC_BODY)
        bodyDefinition.type = b2_dynamicBody;
    bodyDefinition.position = (b2Vec2) definition.position;
    bodyDefinition.angle = definition.rotation.valueRadians();
    bodyDefinition.linearVelocity = (b2Vec2) definition.linearVelocity;
    bodyDefinition.angularVelocity = definition.angularVelocity;
    bodyDefinition.bullet = definition.bullet;
    bodyDefinition.awake = definition.awake;

    body = world->CreateBody(&bodyDefinition);

    //Set a physic object pointer as the body user data
    body->SetUserData(object);

    // creating the body's shape and fixture
    b2FixtureDef fixtureDef;
    b2PolygonShape pShape;
    b2CircleShape cShape;
    float volume;
    if (definition.shapeType == PHYSIC_BOX_SHAPE) {
        volume = definition.box.width * definition.box.height; //Actually this is the area, but we dont care
        pShape.SetAsBox(definition.box.width / 2, definition.box.height / 2, b2Vec2(0, 0), 0.f);
        fixtureDef.shape = &pShape;
        fixtureDef.density = definition.mass / volume;
    } else if (definition.shapeType == PHYSIC_CIRCLE_SHAPE) {
        cShape.m_radius = definition.circle.radius;
        volume = 3.141592 * cShape.m_radius * cShape.m_radius;
        fixtureDef.shape = &cShape;
        fixtureDef.density = definition.mass / volume;
    } else if (definition.shapeType == PHYSIC_EDGE_SHAPE) {
        pShape.SetAsEdge(definition.edge.v1, definition.edge.v2);
        fixtureDef.shape = &pShape;
    }
    fixtureDef.friction = definition.friction;
    fixtureDef.restitution = definition.restitution;
    fixtureDef.isSensor = definition.isSensor;
    body->CreateFixture(&fixtureDef);

    return body;
}

b2Joint* Box2dWorld::createJoint(const PhysicJointDef& definition) {
    b2Joint* joint = NULL;
    b2DistanceJointDef distanceDef;
    b2LineJointDef lineDef;
    b2RevoluteJointDef revoluteDef;
    b2FrictionJointDef frictionDef;

    switch (definition.type) {
        case PHYSIC_DISTANCE_JOINT:
            distanceDef.bodyA = definition.body1;
            distanceDef.bodyB = definition.body2;
            distanceDef.localAnchorA = definition.distanceInfo.localAnchor1;
            distanceDef.localAnchorB = definition.distanceInfo.localAnchor2;
            distanceDef.collideConnected = definition.collideConnected;
            distanceDef.length = definition.distanceInfo.length;
            distanceDef.frequencyHz = definition.distanceInfo.frequency;
            distanceDef.dampingRatio = definition.distanceInfo.dampingRatio;
            joint = world->CreateJoint(&distanceDef);
            break;
        case PHYSIC_LINE_JOINT:
            lineDef.Initialize(definition.body1, definition.body2, definition.lineInfo.worldAnchor, definition.lineInfo.localAxis1);
            lineDef.collideConnected = definition.collideConnected;
            lineDef.enableLimit = definition.lineInfo.enableLimit;
            lineDef.lowerTranslation = definition.lineInfo.lowerTranslation;
            lineDef.upperTranslation = definition.lineInfo.upperTranslation;
            lineDef.enableMotor = definition.lineInfo.enableMotor;
            lineDef.maxMotorForce = definition.lineInfo.maxMotorForce;
            lineDef.motorSpeed = definition.lineInfo.motorSpeed;
            joint = world->CreateJoint(&lineDef);
            break;
        case PHYSIC_REVOLUTE_JOINT:
            revoluteDef.Initialize(definition.body1, definition.body2, definition.revoluteInfo.worldAnchor);
            revoluteDef.collideConnected = definition.collideConnected;
            revoluteDef.enableLimit = definition.revoluteInfo.enableLimit;
            revoluteDef.lowerAngle = definition.revoluteInfo.lowerAngle;
            revoluteDef.upperAngle = definition.revoluteInfo.upperAngle;
            revoluteDef.enableMotor = definition.revoluteInfo.enableMotor;
            revoluteDef.motorSpeed = definition.revoluteInfo.motorSpeed;
            revoluteDef.maxMotorTorque = definition.revoluteInfo.maxMotorTorque;
            joint = world->CreateJoint(&revoluteDef);
            break;
        case PHYSIC_FRICTION_JOINT:
            frictionDef.bodyA = definition.body1;
            frictionDef.bodyB = definition.body2;
            frictionDef.localAnchorA = definition.frictionInfo.localAnchor1;
            frictionDef.localAnchorB = definition.frictionInfo.localAnchor2;
            frictionDef.collideConnected = definition.collideConnected;
            frictionDef.maxForce = definition.frictionInfo.maxForce;
            frictionDef.maxTorque = definition.frictionInfo.maxTorque;
            joint = world->CreateJoint(&frictionDef);
            break;
    }

    return joint;
}

void Box2dWorld::destroyBody(b2Body* body) {
    world->DestroyBody(body);
}

void Box2dWorld::destroyJoint(b2Joint* joint) {
    world->DestroyJoint(joint);
}

namespace {

    class GetAllObjectsQueryCallback : public b2QueryCallback {
    public:
        std::list<PhysicObject*> reportedAABB;

        bool ReportFixture(b2Fixture* fixture) {

            void* userData = fixture->GetBody()->GetUserData();
            if (userData) {
                reportedAABB.push_back((PhysicObject*) userData);
            }

            // Return true to continue the query.
            return true;
        }

    };

    class ZoneIsEmptyQueryCallback : public b2QueryCallback {
    public:
        bool isEmpty;

        ZoneIsEmptyQueryCallback() {
            isEmpty = true;
        }

        bool ReportFixture(b2Fixture* fixture) {
            isEmpty = false;
            return false;
        }

    };
}

std::list<PhysicObject*> Box2dWorld::queryAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound) {
    b2AABB aabb;
    aabb.lowerBound = lowerBound;
    aabb.upperBound = upperBound;

    GetAllObjectsQueryCallback query;
    world->QueryAABB(&query, aabb);

    return query.reportedAABB;
}

bool Box2dWorld::queryIsZoneEmptyAABB(const WasVec2d& lowerBound, const WasVec2d& upperBound) {
    b2AABB aabb;
    aabb.lowerBound = lowerBound;
    aabb.upperBound = upperBound;

    ZoneIsEmptyQueryCallback query;
    world->QueryAABB(&query, aabb);

    return query.isEmpty;
}
