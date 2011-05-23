/* 
 * File:   Light.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:49
 */

#include "Light.h"

using namespace WasabiEngine;

Light::Light(int index) {
    this->index = GL_LIGHT0 + index;
    attenuation = 0;
    ambient = NULL;
    diffuse = NULL;
    specular = NULL;
    glEnable(this->index);
}

Light::Light(const Light& orig) {
    //Not allowed
}

Light::~Light() {
    glDisable(this->index);
    if(ambient != NULL)
        delete ambient;
    if(diffuse != NULL)
        delete diffuse;
    if(specular != NULL)
        delete specular;
}

float Light::getAttenuation() const{
    return attenuation;
}

void Light::setAttenuation(float attenuation){
    this->attenuation = attenuation;
}

ColourValue const * const Light::getAmbient() const {
    return ambient;
}

void Light::setAmbient(const ColourValue& ambient) {
    if (!this->ambient)
        this->ambient = new ColourValue(ambient);
    else
        *this->ambient = ambient;
}

ColourValue const * const Light::getDiffuse() const {
    return diffuse;
}

void Light::setDiffuse(const ColourValue& diffuse) {
    if (!this->diffuse)
        this->diffuse = new ColourValue(diffuse);
    else
        *this->diffuse = diffuse;
}

ColourValue const * const Light::getSpecular() const {
    return specular;
}

void Light::setSpecular(const ColourValue& specular) {
    if (!this->specular)
        this->specular = new ColourValue(specular);
    else
        *this->specular = specular;
}

int Light::getIndex() const {
    return index;
}

WasVec3d Light::getPosition() const {
    return position;
}

void Light::setPosition(const WasVec3d& position) {
    this->position = position;
}
