/* 
 * File:   Material.cpp
 * Author: Roberto
 * 
 * Created on 3 de marzo de 2011, 0:12
 */

#include "Material.h"

using namespace WasabiEngine;

Material::Material() {
    amb[0] = 0.2;
    amb[1] = 0.2;
    amb[2] = 0.2;
    amb[3] = 1.0;
    diff[0] = 0.4;
    diff[1] = 0.4;
    diff[2] = 0.4;
    diff[3] = 1.0;
    spec[0] = 0.2;
    spec[1] = 0.2;
    spec[2] = 0.2;
    spec[3] = 1.0;
    shiny = 90;
}

Material::Material(const Material& orig) {
    amb[0] = orig.amb[0];
    amb[1] = orig.amb[1];
    amb[2] = orig.amb[2];
    amb[3] = orig.amb[3];
    diff[0] = orig.diff[0];
    diff[1] = orig.diff[1];
    diff[2] = orig.diff[2];
    diff[3] = orig.diff[3];
    spec[0] = orig.spec[0];
    spec[1] = orig.spec[1];
    spec[2] = orig.spec[2];
    spec[3] = orig.spec[3];
    shiny = orig.shiny;
}
