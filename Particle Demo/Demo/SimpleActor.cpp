/* 
 * File:   SimpleActor.cpp
 * Author: Fran_2
 * 
 * Created on 21 de marzo de 2011, 11:38
 */

#include "SimpleActor.h"

SimpleActor::SimpleActor() : controlHandler(this) {
    /* Create a Graphic Object and attach it a particle system */
    rootGraphicObject = GraphicEngine::getInstance()->createObject(getId());
    GraphicObject* smokeNode = rootGraphicObject->createChild();


    LinearParticleSystemDef smokeDef;
    smokeDef.acceleration = 0;
    smokeDef.baseSize = 1;
    smokeDef.chaos = 2;
    smokeDef.color = ColourValue::GREY;
    smokeDef.emissionRate = 10;
    smokeDef.emissionVelocity = WasVec2d(0, 5);
    smokeDef.gravity = -1;
    smokeDef.growRate = 3;
    smokeDef.maxParticles = 50;
    smokeDef.particleLifeSpan = 3;
    smokeDef.systemLifeSpan = -1;
    smokeDef.texturePath = "./Resources/Textures/particle10.png";
    smokeNode->createParticleSystem(&smokeDef);

    LinearParticleSystemDef sparkDef;
    sparkDef.acceleration = 0;
    sparkDef.baseSize = 0.2;
    sparkDef.chaos = 5;
    sparkDef.color = ColourValue::RED;
    sparkDef.emissionRate = 30;
    sparkDef.emissionVelocity = WasVec2d(0,2);
    sparkDef.gravity = 9.8;
    sparkDef.growRate = 0.1;
    sparkDef.maxParticles = 50;
    sparkDef.particleLifeSpan = 1;
    sparkDef.systemLifeSpan = -1;
    sparkDef.texturePath = "./Resources/Textures/particle10.png";
    smokeNode->createParticleSystem(&sparkDef);
    sparkDef.color = ColourValue(0.8,0.3,0);
    smokeNode->createParticleSystem(&sparkDef);

    /* Create a physic for the object */
    physicObject = PhysicEngine::getInstance()->createObject(getId());
    PhysicBodyDef physicDefinition;
    physicDefinition.bodyType = PHYSIC_DYNAMIC_BODY;
    physicDefinition.awake = true;
    physicDefinition.shapeType = PHYSIC_BOX_SHAPE;
    physicDefinition.box.height = 1;
    physicDefinition.box.width = 1;
    physicObject->createBody("MainBody",physicDefinition);

    /* Register a handler */
    controlHR = EventEngine::getInstance()->addHandler(&controlHandler, false);
}

SimpleActor::~SimpleActor() {
    controlHR->removeHandler();

    /* Destroy the graphics and the physics */
    GraphicEngine::getInstance()->destroyObject(rootGraphicObject);
    PhysicEngine::getInstance()->destroyObject(physicObject);

    rootGraphicObject = NULL;
    physicObject = NULL;
}

void SimpleActor::update(){
    //Do nothing
}