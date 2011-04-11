/* 
 * File:   SimpleActor.cpp
 * Author: Fran_2
 * 
 * Created on 21 de marzo de 2011, 11:38
 */

#include "SimpleActor.h"

SimpleActor::SimpleActor() : controlHandler(this) {
    /* Create a Graphic Object and attach it a particle system */
    graphicObject = GraphicEngine::getInstance()->createObject(getId());
    LinearParticleSystemDef particlesDef;
    particlesDef.acceleration = 0;
    particlesDef.baseSize = 1;
    particlesDef.chaos = 10;
    particlesDef.color = ColourValue::WHITE;
    particlesDef.emissionRate = 100;
    particlesDef.emissionVelocity = WasVec2d(0, 10);
    particlesDef.gravity = 9.8;
    particlesDef.growRate = 1.5;
    particlesDef.maxParticles = 500;
    particlesDef.particleLifeSpan = 3;
    particlesDef.systemLifeSpan = -1;
    particlesDef.texturePath = "./Resources/Textures/crate.jpg";
    graphicObject->createParticleSystem(&particlesDef);

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
    GraphicEngine::getInstance()->destroyObject(graphicObject);
    PhysicEngine::getInstance()->destroyObject(physicObject);

    graphicObject = NULL;
    physicObject = NULL;
}

void SimpleActor::update(){
    //Do nothing
}