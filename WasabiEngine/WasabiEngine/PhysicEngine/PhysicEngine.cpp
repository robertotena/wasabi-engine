/* 
 * File:   PhysicEngine.cpp
 * Author: Roberto
 * 
 * Created on 4 de enero de 2011, 0:43
 */

#include "PhysicEngine.h"
#include "PhysicDefinitions.h"


using namespace WasabiEngine;

PhysicEngine::PhysicEngine() {
    PhysicObject::world = world.getB2World();
}

PhysicEngine::~PhysicEngine() {
    clear();
}

PhysicEngine* PhysicEngine::getInstance() {
    static PhysicEngine instance;
    return &instance;
}

void PhysicEngine::step() {
    world.step();
}

PhysicObject* PhysicEngine::getItem(const int& id) {
    PhysicObject** obj = objects.get(id);
    if (obj != NULL)
        return *obj;
    return NULL;
}

PhysicObject* PhysicEngine::createObject(const int& id) {
    PhysicObject* obj;

    obj = factory.createResource();
    obj->setId(id);
    objects.set(id, obj);

    return obj;
}

void PhysicEngine::destroyObject(PhysicObject* object) {
    if (objects.get(object->getId())) {
        objects.remove(object->getId());
        factory.returnResource(object);
    }
}

void PhysicEngine::clear(){
    objects.clear();
}