/* 
 * File:   SensorEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 9 de enero de 2011, 20:59
 */

#include "SensorEventHandler.h"
#include <WasabiEngine/GameEngine/Sensor.h>

using namespace WasabiEngine;

SensorEventHandler::SensorEventHandler(Sensor* sensor) : EventHandler(sensor->getId(), sensor->getName()) {
    this->sensor = sensor;
}

void SensorEventHandler::handle(const Event* event) {
    int contactId = event->getIntegerProperty("contactId");
    SensorHandler** handler = sensor->handlersMap.get(contactId);
    if (handler != NULL)
        (*handler)->handle(contactId);
}
