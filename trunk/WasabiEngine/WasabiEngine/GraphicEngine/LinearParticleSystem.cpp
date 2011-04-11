/* 
 * File:   LinearParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:31
 */

#include "LinearParticleSystem.h"

using namespace WasabiEngine;

LinearParticleSystem::LinearParticleSystem(const LinearParticleSystemDef& definition) : ParticleSystem(&definition), systemDefinition(definition) {
    
}

LinearParticleSystem::LinearParticleSystem(const LinearParticleSystem& orig) : ParticleSystem(&orig.systemDefinition) {
    //Not allowed
}

LinearParticleSystem::~LinearParticleSystem() {
}

void LinearParticleSystem::updateParticles() {
    int freeParticles = deadParticles.size();

    static unsigned int lastEmissionTimestamp = WasabiTime::getTicks(); //Could be 0, but in that case the first iteration will cause an "explosion"
    unsigned int now = WasabiTime::getTicks();
    int particlesToEmmit = (now - lastEmissionTimestamp) / systemDefinition.emissionRate;
    particlesToEmmit = WasabiMath::min(particlesToEmmit, freeParticles);

    for (int i = 0; i < particlesToEmmit; i++) {
        int particleIndex = deadParticles.back();
        deadParticles.pop_back();
        aliveParticles.push_back(particleIndex);

        //Init particle
        Particle& particle = particles[particleIndex];
        particle.position = WasVec2d::ZERO;
        particle.energy = 1;
        particle.velocity = systemDefinition.emissionVelocity;
        particle.velocityDelta.x = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0.0;
        particle.velocityDelta.y = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0.0;
        particle.size = systemDefinition.baseSize;
        particle.sizeDelta = systemDefinition.chaos ? (rand() % systemDefinition.chaos) : 0.0;
    }

    std::list<int>::iterator currentParticle = aliveParticles.begin();
    std::list<int>::iterator nextParticle = aliveParticles.begin();
    nextParticle++;
    for (unsigned int i = 0; i < aliveParticles.size(); i++) {
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
        particle.velocity.x = particle.velocity.x * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        particle.velocity.y = particle.velocity.y * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Gravity
        particle.velocity.y = particle.velocity.y * tInterval + 0.5 * systemDefinition.gravity * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Chaos
        particle.velocity += particle.velocityDelta * tInterval;
        // Final position
        particle.position += particle.velocity * tInterval;
        // Size
        particle.size += particle.sizeDelta * tInterval;
        // Energy (alpha)
        particle.energy = WasabiMath::max(0, particle.energy - tInterval / systemDefinition.particleLifeSpan);
        // Quad update
        vertices[i * 4].x = particle.position.x;
        vertices[i * 4 + 1].x = particle.position.x * particle.size;
        vertices[i * 4 + 2].y = particle.position.y;
        vertices[i * 4 + 3].y = particle.position.y * particle.size;
        colors[i * 4 + 3] = particle.energy;
    }

    lastEmissionTimestamp = now;
}
