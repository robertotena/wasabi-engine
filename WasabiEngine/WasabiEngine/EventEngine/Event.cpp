/*
 * File:   Event.cpp
 * Author: Fran_2
 *
 * Created on 9 de diciembre de 2010, 18:42
 */

#include "Event.h"

using namespace WasabiEngine;

Event::Event() {
    clear();
}

Event::~Event() {
    clear();
}

void Event::clear() {
    dispatchType = EVENT_UNDEFINED_DISPATCH;
    eventType.clear();
    port = 0;
    senderId = GameObject::INVALID_ID;
    receiverId = GameObject::INVALID_ID;
    timestamp = 0;
    delay = 0;
    systemEvent = false;
    propertiesCount = 0;
}

bool Event::addProperty(const std::string& name, const int& value) {
    if (propertiesCount >= MAX_EVENT_PROPERTIES)
        return false;
    properties[propertiesCount].name = name;
    properties[propertiesCount].type = EVENT_PROPERTY_INTEGER;
    properties[propertiesCount].value.integer_value = value;
    propertiesCount++;
    return true;
}

bool Event::addProperty(const std::string& name, const float& value) {
    if (propertiesCount >= MAX_EVENT_PROPERTIES)
        return false;
    properties[propertiesCount].name = name;
    properties[propertiesCount].type = EVENT_PROPERTY_FLOAT;
    properties[propertiesCount].value.float_value = value;
    propertiesCount++;
    return true;
}

bool Event::addProperty(const std::string& name, const bool& value) {
    if (propertiesCount >= MAX_EVENT_PROPERTIES)
        return false;
    properties[propertiesCount].name = name;
    properties[propertiesCount].type = EVENT_PROPERTY_BOOL;
    properties[propertiesCount].value.bool_value = value;
    propertiesCount++;
    return true;
}

bool Event::addProperty(const std::string& name, const std::string& value) {
    if (propertiesCount >= MAX_EVENT_PROPERTIES)
        return false;
    properties[propertiesCount].name = name;
    properties[propertiesCount].type = EVENT_PROPERTY_HASHED_STRING;
    properties[propertiesCount].value.hashed_value = WasabiHash::hash(value.c_str(), value.length());
    propertiesCount++;
    return true;
}

int Event::getIntegerProperty(const std::string& name) const {
    int value;
    for (int i = 0; i < propertiesCount; i++) {
        if (properties[i].type == EVENT_PROPERTY_INTEGER && properties[i].name == name) {
            value = properties[i].value.integer_value;
            break;
        }
    }
    return value;
}

float Event::getFloatProperty(const std::string& name) const {
    float value;
    for (int i = 0; i < propertiesCount; i++) {
        if (properties[i].type == EVENT_PROPERTY_FLOAT && properties[i].name == name) {
            value = properties[i].value.float_value;
            break;
        }
    }
    return value;
}

bool Event::getBooleanProperty(const std::string& name) const {
    bool value;
    for (int i = 0; i < propertiesCount; i++) {
        if (properties[i].type == EVENT_PROPERTY_BOOL && properties[i].name == name) {
            value = properties[i].value.bool_value;
            break;
        }
    }
    return value;
}

unsigned int Event::getHashProperty(const std::string& name) const {
    unsigned int value;
    for (int i = 0; i < propertiesCount; i++) {
        if (properties[i].type == EVENT_PROPERTY_HASHED_STRING && properties[i].name == name) {
            value = properties[i].value.hashed_value;
            break;
        }
    }
    return value;
}

bool Event::hasProperty(const std::string& name) const
{
    for(int i = 0; i < propertiesCount; i++)
        if(properties[i].name == name)
            return true;
    return false;
}
