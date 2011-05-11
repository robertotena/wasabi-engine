/* 
 * File:   RadialParticleSystem.cpp
 * Author: Fran_2
 * 
 * Created on 10 de abril de 2011, 18:53
 */

#include "RadialParticleSystem.h"

using namespace WasabiEngine;

RadialParticleSystem::RadialParticleSystem(const RadialParticleSystemDef& definition) : ParticleSystem(&definition), systemDefinition(definition) {

}

RadialParticleSystem::RadialParticleSystem(const RadialParticleSystem& orig) : ParticleSystem(&orig.systemDefinition) {
    //Not allowed
}

RadialParticleSystem::~RadialParticleSystem() {
}

void RadialParticleSystem::updateParticles() {
    int freeParticles = deadParticles.size();
    float emissionVelocity = systemDefinition.emissionVelocity;
    unsigned int now = WasabiTime::getTicks();
    int particlesToEmmit = (now - lastEmissionTimestamp) * systemDefinition.emissionRate / 1000;
    particlesToEmmit = WasabiMath::min(particlesToEmmit, freeParticles);

    for (int i = 0; i < particlesToEmmit; i++) {
        int particleIndex = deadParticles.back();
        deadParticles.pop_back();
        aliveParticles.push_back(particleIndex);

        //Init particle
        Particle& particle = particles[particleIndex];
        particle.position = WasVec2d::ZERO;
        particle.timestamp = now;
        particle.energy = 1;
        particle.velocity.x = emissionVelocity ? rand() % (int) emissionVelocity : 0; //FIXME: La inicializacion de la velocidad es lo unico que cambia. Despues vemos que se hace con esto.
        particle.velocity.y = emissionVelocity ? sqrt(emissionVelocity * emissionVelocity - particle.velocity.x * particle.velocity.x) : 0; //Pythagoras
        if (rand() % 2 - 1 < 0)
            particle.velocity.x = -particle.velocity.x;
        if (rand() % 2 - 1 < 0)
            particle.velocity.y = -particle.velocity.y;
        particle.size = systemDefinition.baseSize;
        particle.sizeDelta = systemDefinition.chaos ? abs((rand() % systemDefinition.chaos - systemDefinition.chaos / 2) / 10 + systemDefinition.growRate) : systemDefinition.growRate;
    }
    if (particlesToEmmit > 0)
        lastEmissionTimestamp = now;

    std::list<int>::iterator currentParticle = aliveParticles.begin();
    std::list<int>::iterator nextParticle = aliveParticles.begin();
    while (currentParticle != aliveParticles.end()) {
        nextParticle++;
        Particle& particle = particles[*currentParticle];
        //Remove dead particles
        if (particle.energy == 0 || particle.size == 0) {
            deadParticles.push_back(*currentParticle);
            aliveParticles.erase(currentParticle);
            currentParticle = nextParticle;
            continue;
        }

        float tInterval = (now - particle.timestamp) / 1000.0;
        // Position
        particle.position.x = particle.velocity.x * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // x = vx * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        particle.position.y = particle.velocity.y * tInterval + 0.5 * (systemDefinition.acceleration - systemDefinition.gravity) * tInterval * tInterval; // y = vy * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Size
        particle.size = systemDefinition.baseSize + systemDefinition.baseSize * (particle.sizeDelta - 1) * tInterval;
        particle.size = WasabiMath::max(0, particle.size);
        // Energy (alpha)
        particle.energy = WasabiMath::max(0, 1 - tInterval / systemDefinition.particleLifeSpan);

        currentParticle = nextParticle;
    }
}
