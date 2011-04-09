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

LinearParticleSystem::LinearParticleSystem(const ParticleSystemDef& definition, const WasVec2d& emissionVelocity) {
    this->emissionVelocity = emissionVelocity;
}

LinearParticleSystem::LinearParticleSystem(const LinearParticleSystem& orig) {
    //Not allowed
}

LinearParticleSystem::~LinearParticleSystem() {
}

void LinearParticleSystem::updateParticles() {
    int freeParticles = deadParticles.size();

    static unsigned int lastEmissionTimestamp = 0;
    unsigned int now = WasabiTime::getTicks();
    int particlesToEmmit = (now - lastEmissionTimestamp) / systemDefinition.emissionRate;
    particlesToEmmit = WasabiMath::max(particlesToEmmit, freeParticles);

    for (int i = 0; i < particlesToEmmit; i++) {
        int particleIndex = deadParticles.back();
        deadParticles.pop_back();
        aliveParticles.push_back(particleIndex);

        //Init particle
        Particle& particle = particles[particleIndex];
        particle.position = WasVec2d.ZERO;
        particle.energy = 1;
        particle.velocity = emissionVelocity;
        particle.velocityDelta.x = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0;
        particle.velocityDelta.y = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0;
        particle.size = systemDefinition.baseSize;
        particle.sizeDelta = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0;
    }

    std::list<int>::iterator currentParticle = aliveParticles.begin();
    std::list<int>::iterator nextParticle = aliveParticles.begin();
    nextParticle++;
    for (int i = 0; i < aliveParticles.size(); i++) {
        Particle& particle = particles[*currentParticle];
        //Remove dead particles
        if (particle.energy == 0) {
            deadParticles.push_back(*currentParticle);
            aliveParticles.erase(currentParticle);
            currentParticle = nextParticle;
            nextParticle++;
            continue;
        }
        currentParticle = nextParticle;
        nextParticle++;

        float tInterval = (now - lastEmissionTimestamp) * 1000;
        // Particle acceleration
        particle.velocity = particle.velocity * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Gravity
        particle.velocity.y = particle.velocity.y * tInterval + 0.5 * systemDefinition.gravity * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Chaos
        particle.velocity += particle.velocityDelta * tInterval;
        // Final position
        particle.position += particle.velocity + tInterval;
        // Size
        particle.size += particle.sizeDelta * tInterval;
        // Energy (alpha)
        particle.energy = WasabiMath.max(0, particle.energy - tInterval / systemDefinition.particleLifeSpan);
        // Quad update
        vertices[*i * 4] = particle.position.x;
        vertices[*i * 4 + 1] = particle.position.x * particle.size;
        vertices[*i * 4 + 2] = particle.position.y;
        vertices[*i * 4 + 3] = particle.position.y * particle.size;
    }

    lastEmissionTimestamp = now;
}