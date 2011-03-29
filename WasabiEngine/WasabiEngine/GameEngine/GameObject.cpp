/*
 * File:   GameObject.h
 * Author: Fran
 *
 * Created on 13 de enero de 2011, 20:17
 */

#include "GameObject.h"
#include "GameObjectManager.h"

using namespace WasabiEngine;

unsigned int GameObject::objectsCount = 0;

GameObject::GameObject() {
    objectsCount++;
    std::stringstream count;
    count << objectsCount;
    this->name = "WasabiObject" + count.str();
    id = WasabiHash::hash(name.c_str(), name.size());
    GameObjectManager::getInstance()->attach(this);
    
    typeName = "Undefined";
    typeHashCode = UNDEFINED_TYPE_CODE;
}

GameObject::~GameObject(){
    GameObjectManager::getInstance()->detach(this);
}

bool GameObject::setName(const std::string& name) {
    unsigned int tmpId = WasabiHash::hash(name.c_str(), name.size());
    if (tmpId != INVALID_ID) {
        GameObjectManager::getInstance()->detach(this);
        id = tmpId;
        this->name = name;
        GameObjectManager::getInstance()->attach(this);
        return true;
    }
    return false;
}

void GameObject::setTypeName(const std::string& typeName) {
    this->typeName = typeName;
    typeHashCode = WasabiHash::hash(typeName.c_str(), typeName.size());
}
