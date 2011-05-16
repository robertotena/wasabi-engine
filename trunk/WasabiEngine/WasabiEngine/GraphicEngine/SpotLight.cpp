/* 
 * File:   SpotLight.cpp
 * Author: Fran_2
 * 
 * Created on 16 de mayo de 2011, 11:41
 */

#include "SpotLight.h"

using namespace WasabiEngine;

SpotLight::SpotLight(int index) : Light(index) {
    cutoff = 45;
}

SpotLight::SpotLight(const SpotLight& orig) : Light(0) {
    //Not allowed
}

SpotLight::~SpotLight() {
}

float SpotLight::getCutoff() const {
    return cutoff;
}

void SpotLight::setCutoff(float cutoff) {
    this->cutoff = cutoff;
}

WasVec3d SpotLight::getDirection() const {
    return direction;
}

void SpotLight::setDirection(const WasVec3d& direction) {
    this->direction = direction;
}

void SpotLight::renderObject() {
    glEnable(GL_COLOR_MATERIAL);
    if (getAmbient() != NULL) {
        glMaterialfv(GL_FRONT, GL_AMBIENT, getAmbient()->ptr());
        glLightfv(getIndex(), GL_AMBIENT, getAmbient()->ptr());
    }
    if (getDiffuse() != NULL) {
        glMaterialfv(GL_FRONT, GL_DIFFUSE, getDiffuse()->ptr());
        glLightfv(getIndex(), GL_AMBIENT, getDiffuse()->ptr());
    }
    if (getSpecular() != NULL) {
        glMaterialfv(GL_FRONT, GL_SPECULAR, getSpecular()->ptr());
        glLightfv(getIndex(), GL_SPECULAR, getSpecular()->ptr());
    }
    float p[4] = {getPosition().x, getPosition().y, getPosition().z, 1}; //w -> 0: Directional, 1: Positional
    glLightfv(getIndex(), GL_POSITION, p);
    glLightf(getIndex(), GL_LINEAR_ATTENUATION, getAttenuation());
    glLightf(getIndex(), GL_SPOT_CUTOFF, cutoff);
    glLightfv(getIndex(), GL_SPOT_DIRECTION, direction.ptr());
    glEnable(getIndex());
}