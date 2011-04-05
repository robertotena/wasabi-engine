/* 
 * File:   ParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:23
 */

#include "ParticleSystem.h"

using namespace WasabiEngine;

ParticleSystem::ParticleSystem(const ParticleSystemDef& def){
    systemDefinition = def;
    for(int i = 0; i < def.maxParticles; i++)
        deadParticles.push_back(new Particle());
}

ParticleSystem::ParticleSystem(const ParticleSystem& orig) {
    // not allowed
}

ParticleSystem::~ParticleSystem() {
    // FIXME: destruir particulas?
}
