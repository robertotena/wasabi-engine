/* 
 * File:   SensorFactory.cpp
 * Author: Fran_2
 * 
 * Created on 8 de enero de 2011, 20:58
 */

#include "SensorFactory.h"

using namespace WasabiEngine;

SensorFactory::SensorFactory() {
}

SensorFactory::SensorFactory(const SensorFactory& factory){
    //Copy not allowed
}

SensorFactory::~SensorFactory() {
}

Sensor* SensorFactory::create(const WasVec2d& position, const float& radius){
    Sensor* sensor = factory.createResource();
    sensor->prepare(position, radius);
    return sensor;
}

void SensorFactory::destroy(Sensor* sensor){
    factory.returnResource(sensor);
}