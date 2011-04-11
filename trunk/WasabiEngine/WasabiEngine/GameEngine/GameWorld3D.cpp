/* 
 * File:   GameWorld3D.cpp
 * Author: Franco Gotusso <gotusso@gmail.com>
 * 
 * Created on 16 de enero de 2011, 20:07
 */

#include "GameWorld3D.h"
#include <WasabiEngine/GameEngine/GameSystemManager.h>

using namespace WasabiEngine;

GameWorld3D::GameWorld3D(GameSystemManager* systemManager) {
    this->systemManager = systemManager;
    frictionCoefficient = 0.9;
    ground = NULL;
    setWorldSize(100,100);
}

GameWorld3D::GameWorld3D(const GameWorld3D& orig) {
    //Not allowed
}

GameWorld3D::~GameWorld3D() {
    clear();
}

void GameWorld3D::attachWorld(GameObject* gameObject) {
    //Add friction
    PhysicObject* object = PhysicEngine::getInstance()->getItem(gameObject->getId());
    if (object != NULL) {
        PhysicJointDef jointDef;
        jointDef.type = PHYSIC_FRICTION_JOINT;
        jointDef.collideConnected = true;
        jointDef.body1 = ground->getMainBody();
        jointDef.body2 = object->getMainBody();

        float normalForce = jointDef.body2->GetMass() * 9.8f; // mass * gravity
        float frictionForce = frictionCoefficient * normalForce;
        jointDef.frictionInfo.maxForce = frictionForce;

        // For a circle: I = 0.5 * m * r * r ==> r = sqrt(2 * I / m)
        float radius = b2Sqrt(2.0f * jointDef.body2->GetInertia() / jointDef.body2->GetMass());
        jointDef.frictionInfo.maxTorque = frictionForce * radius; // Friccion * Distancia entre los puntos de aplicacion

        ground->createJoint(gameObject->getName(), jointDef);
    }
}

void GameWorld3D::detachWorld(GameObject* gameObject) {
    b2Joint* joint = ground->getJoint(gameObject->getName());
    if (joint != NULL) {
        ground->destroyJoint(gameObject->getName());
    }
}

void GameWorld3D::attach(Actor* actor) {
    actors.insert(actor);
    attachWorld(actor);
}

bool GameWorld3D::detach(Actor* actor) {
    if (actors.erase(actor) > 0) {
        detachWorld(actor);
        return true;
    }
    return false;
}

void GameWorld3D::attach(Scenery* scenery) {
    this->scenery.insert(scenery);
    attachWorld(scenery);
}

bool GameWorld3D::detach(Scenery* scenery) {
    if (this->scenery.erase(scenery) > 0) {
        detachWorld(scenery);
        return true;
    }
    return false;
}

void GameWorld3D::clear() {
    while (scenery.size() > 0)
        detach((*scenery.begin()));
    while (actors.size() > 0)
        detach((*actors.begin()));
}

void GameWorld3D::update() {
    GraphicObject* graphicObj;
    PhysicObject* physicObj;

    unsigned int objectID;
    std::set<Actor*>::iterator currentActor = actors.begin();
    std::set<Actor*>::iterator nextActor = actors.begin();
    nextActor++;

    for (unsigned int i = 0; i < actors.size(); i++) {
        //Update graphic info
        objectID = (*currentActor)->getId();
        physicObj = PhysicEngine::getInstance()->getItem(objectID);
        graphicObj = GraphicEngine::getInstance()->getItem(objectID);

        if (physicObj && graphicObj) {
            WasVec2d position = physicObj->getPosition();
            graphicObj->setPosition(WasVec3d(position.x, 0, -position.y));
            graphicObj->setOrientation(Quaternion(physicObj->getRotation().valueRadians(), WasVec3d::Y_UNIT));
        }

        //Update actor logic
        (*currentActor)->update();

        //The current actor can be deleted during the update
        currentActor = nextActor;
        nextActor++;
    }

    std::set<Scenery*>::iterator sceneryIt;

    for (sceneryIt = scenery.begin(); sceneryIt != scenery.end(); sceneryIt++) {
        // updating graphic info
        objectID = (*sceneryIt)->getId();
        physicObj = PhysicEngine::getInstance()->getItem(objectID);
        graphicObj = GraphicEngine::getInstance()->getItem(objectID);

        if (physicObj && graphicObj) {
            WasVec2d position = physicObj->getPosition();
            graphicObj->setPosition(WasVec3d(position.x, 0, -position.y));
            graphicObj->setOrientation(Quaternion(physicObj->getRotation().valueRadians(), WasVec3d::Y_UNIT));
        }
    }
}

void GameWorld3D::setWorldSize(float width, float length) {
    this->width = width;
    this->length = length;
    
    //Make world ground and walls
    PhysicBodyDef bodyDef;
    bodyDef.bodyType = PHYSIC_STATIC_BODY;
    bodyDef.shapeType = PHYSIC_EDGE_SHAPE;
    bodyDef.friction = 0.2f;

    if (ground != NULL)
        PhysicEngine::getInstance()->destroyObject(ground);
    ground = PhysicEngine::getInstance()->createObject(id);

    /* FIXME: Esto es un "parche" para que un cuerpo tenga mas de un fixture. Puede
     * que debamos incluirlo en el motor de fisica */

    // Wall 1
    bodyDef.edge.v1 = WasVec2d(-width / 2, length / 2);
    bodyDef.edge.v2 = WasVec2d(width / 2, length / 2);
    ground->createBody("Walls", bodyDef);

    // Wall 2
    b2PolygonShape shape;
    b2FixtureDef fixDef;
    fixDef.shape = &shape;
    shape.SetAsEdge(WasVec2d(-width / 2, -length / 2), WasVec2d(width / 2, -length / 2));
    ground->getMainBody()->CreateFixture(&fixDef);

    // Wall 3
    shape.SetAsEdge(WasVec2d(-width / 2, length / 2), WasVec2d(-width / 2, -length / 2));
    ground->getMainBody()->CreateFixture(&fixDef);

    // Wall 4
    shape.SetAsEdge(WasVec2d(width / 2, length / 2), WasVec2d(width / 2, -length / 2));
    ground->getMainBody()->CreateFixture(&fixDef);
}

void GameWorld3D::setFrictionCoefficient(float frictionCoefficient) {
    //FIXME: Update world joints!!
}