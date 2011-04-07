/* 
 * File:   LinearParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:31
 */

#include "LinearParticleSystem.h"
#include "WasabiEngine/Utils/WasabiTime.h"
#include "WasabiEngine/Utils/MathUtil.h"

using namespace WasabiEngine;

LinearParticleSystem::LinearParticleSystem(const ParticleSystemDef& definition) {
}

LinearParticleSystem::LinearParticleSystem(const LinearParticleSystem& orig) {
    //Not allowed
}

LinearParticleSystem::~LinearParticleSystem() {
}

void LinearParticleSystem::update(unsigned int timeElapsed) {
    int freeParticles = deadParticles.size();

    static unsigned int lastEmissionTimestamp = 0;
    unsigned int now = WasabiTime::getTicks();
    int particlesToEmmit = (now - lastEmissionTimestamp) / systemDefinition.emissionRate;
    particlesToEmmit = WasabiMath::max(particlesToEmmit, freeParticles);

    for(int i = 0; i < particlesToEmmit; i++){
        Particle* p = deadParticles.back();
        //init particle
        deadParticles.pop_back();
        aliveParticles.push_back(p);

    }
}