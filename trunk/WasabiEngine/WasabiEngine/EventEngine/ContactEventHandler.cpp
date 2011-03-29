/* 
 * File:   ContactEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 12 de marzo de 2011, 19:51
 */

#include "ContactEventHandler.h"

using namespace WasabiEngine;

const char ContactEventHandler::EVENT_NAME[] = "ContactEvent";

ContactEventHandler::ContactEventHandler(unsigned int objectId) : EventHandler(objectId, EVENT_NAME) {
}

unsigned int ContactEventHandler::getContactedObjectId(const Event* event) {
    return (unsigned int) event->getIntegerProperty("contactedObjectId");
}

float ContactEventHandler::getNormalImpulse(const Event* event) {
    return event->getFloatProperty("normalImpulse");
}

float ContactEventHandler::getTangentImpulse(const Event* event) {
    return event->getFloatProperty("tangentImpulse");
}
