/* 
 * File:   SensorContactListener.cpp
 * Author: Fran_2
 * 
 * Created on 9 de enero de 2011, 21:05
 */

#include "SensorContactListener.h"
#include <WasabiEngine/GameEngine/Sensor.h>

using namespace WasabiEngine;

SensorContactListener::SensorContactListener(Sensor* sensor) : ObjectContactListener(sensor->getId()){
    this->sensor = sensor;
}

SensorContactListener::~SensorContactListener()
{
    sensor = NULL;
}

void SensorContactListener::beginContact(PhysicObject* contactedObj) {
    int contactId = contactedObj->getId();
    Event* event = EventFactory::getInstance()->create(sensor->getName());
    event->addProperty("contactId", contactId);
    EventEngine::getInstance()->sendEvent(event, sensor->getId());
}
