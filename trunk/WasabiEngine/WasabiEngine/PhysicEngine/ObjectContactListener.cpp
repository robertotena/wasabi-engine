/*
 * File:   PhysicObject.cpp
 * Author: Fran_2
 *
 * Created on 12 de marzo de 2011, 20:54
 */


#include "ObjectContactListener.h"
#include <WasabiEngine/PhysicEngine/PhysicObject.h>

using namespace WasabiEngine;

ObjectContactListener::ObjectContactListener(unsigned int ownerId){
    this->ownerId = ownerId;
}

void ObjectContactListener::postSolve(PhysicObject* contactedObj, float normalImpulse, float tangentImpulse) {
    Event* event = EventFactory::getInstance()->create(ContactEventHandler::EVENT_NAME);
    event->addProperty("contactedObjectId", (int)contactedObj->getId());
    event->addProperty("normalImpulse", normalImpulse);
    event->addProperty("tangentImpulse", tangentImpulse);
    EventEngine::getInstance()->sendEvent(event, ownerId);
}