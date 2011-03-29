/* 
 * File:   Sensor.cpp
 * Author: Fran_2
 * 
 * Created on 8 de enero de 2011, 19:38
 */

#include "Sensor.h"

using namespace WasabiEngine;

Sensor::Sensor() : contactListener(this) {
}

Sensor::Sensor(const Sensor& sensor) : contactListener(this){
    //Copy not allowed
}

Sensor::~Sensor() {
    clear();
}

void Sensor::prepare(const WasVec2d& position, const float& radius) {
    //Event registration
    //The event is needed to manage the SensorHandler in user time
    eventHandler = new SensorEventHandler(this);
    handlerRegistration = EventEngine::getInstance()->addHandler(eventHandler);
    //Physic registration
    PhysicObject* physic = PhysicEngine::getInstance()->createObject(id);
    PhysicBodyDef def;
    def.isSensor = true;
    def.position = position;
    def.shapeType = PHYSIC_CIRCLE_SHAPE;
    def.circle.radius = radius;
    physic->createBody("sensor", def);
    physic->setContactListener(&contactListener);
}

void Sensor::clear() {
    PhysicEngine::getInstance()->destroyObject(PhysicEngine::getInstance()->getItem(id));
    if(eventHandler)
        delete eventHandler;
    eventHandler = NULL;
    if(handlerRegistration)
        handlerRegistration->removeHandler();
    handlersMap.clear();
}

void Sensor::addHandler(int monitoredObjectId, SensorHandler* handler) {
    handlersMap.set(monitoredObjectId, handler);
}

void Sensor::removeHandler(int monitoredObjectId) {
    handlersMap.remove(monitoredObjectId);
}
