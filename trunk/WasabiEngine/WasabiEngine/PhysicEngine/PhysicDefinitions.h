/* 
 * File:   PhysicDefinitions.h
 * Author: Roberto
 *
 * Created on 4 de enero de 2011, 20:23
 */

#ifndef PHYSICDEFINITIONS_H
#define	PHYSICDEFINITIONS_H

#include <WasabiEngine/Utils/Vectors.h>
#include <Box2D/Box2D.h>

namespace WasabiEngine {

    // Body definitions

    enum BodyType {
        PHYSIC_STATIC_BODY, PHYSIC_KINEMATIC_BODY, PHYSIC_DYNAMIC_BODY
    };

    enum ShapeType {
        PHYSIC_CIRCLE_SHAPE, PHYSIC_BOX_SHAPE, PHYSIC_EDGE_SHAPE
    };

    typedef struct {
        float radius;
    } CircleShape;

    typedef struct {
        float width;
        float height;
    } BoxShape;

    typedef struct {
        WasVec2d v1;
        WasVec2d v2;
    } EdgeShape;

    class PhysicBodyDef {
    public:
        BodyType bodyType;
        WasVec2d position;
        Degree rotation;
        WasVec2d linearVelocity;
        float angularVelocity;
        float linearDamping;
        float angularDamping;
        bool bullet;
        bool awake;

        ShapeType shapeType;
        CircleShape circle;
        BoxShape box;
        EdgeShape edge;

        float restitution;
        float friction;
        float mass;
        bool isSensor;

        PhysicBodyDef() {
            bodyType = PHYSIC_STATIC_BODY;
            shapeType = PHYSIC_CIRCLE_SHAPE;
            rotation = 0.0;
            angularVelocity = 0.0;
            linearDamping = 1.0;
            angularDamping = 1.0;
            restitution = 0.1;
            friction = 1.0;
            mass = 1.0;
            awake = false;
            bullet = false;
            isSensor = false;
        }
    };

    // Joint definitions

    enum JointType {
        PHYSIC_DISTANCE_JOINT, PHYSIC_LINE_JOINT, PHYSIC_REVOLUTE_JOINT, PHYSIC_FRICTION_JOINT
    };

    typedef struct {
        WasVec2d localAnchor1;
        WasVec2d localAnchor2;
        float length;
        float frequency;
        float dampingRatio;
    } DistanceJointDef;

    typedef struct {
        WasVec2d worldAnchor;
        WasVec2d localAxis1;
        bool enableLimit;
        float lowerTranslation;
        float upperTranslation;
        bool enableMotor;
        float maxMotorForce;
        float motorSpeed;
    } LineJointDef;

    typedef struct {
        WasVec2d worldAnchor;
        bool enableLimit;
        float lowerAngle;
        float upperAngle;
        bool enableMotor;
        float motorSpeed;
        float maxMotorTorque;
    } RevoluteJointDef;

    typedef struct {
        WasVec2d localAnchor1;
        WasVec2d localAnchor2;
        float maxForce;
        float maxTorque;
    } FrictionJointDef;

    class PhysicJointDef {
    public:
        JointType type;
        b2Body* body1;
        b2Body* body2;
        bool collideConnected;

        DistanceJointDef distanceInfo;
        RevoluteJointDef revoluteInfo;
        FrictionJointDef frictionInfo;
        LineJointDef lineInfo;

        PhysicJointDef() {
            type = PHYSIC_DISTANCE_JOINT;
            body1 = NULL;
            body2 = NULL;
            collideConnected = false;
        }
    };
}

#endif	/* PHYSICDEFINITIONS_H */

