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
        particle.velocity.x = systemDefinition.chaos ? ((rand() % systemDefinition.chaos / 2) - systemDefinition.chaos / 2 + systemDefinition.emissionVelocity.x) : systemDefinition.emissionVelocity.x;
        particle.velocity.y = systemDefinition.chaos ? ((rand() % systemDefinition.chaos / 2) - systemDefinition.chaos / 2 + systemDefinition.emissionVelocity.y) : systemDefinition.emissionVelocity.y;
        particle.size = systemDefinition.baseSize;
        particle.sizeDelta = systemDefinition.chaos ? ((rand() % systemDefinition.chaos) * systemDefinition.growRate) : systemDefinition.growRate;
    }

    std::list<int>::iterator currentParticle = aliveParticles.begin();
    std::list<int>::iterator nextParticle = aliveParticles.begin();
    nextParticle++;
    while (currentParticle != aliveParticles.end()) {
        Particle& particle = particles[*currentParticle];
        //Remove dead particles
        if (particle.energy == 0) {
            deadParticles.push_back(*currentParticle);
            aliveParticles.erase(currentParticle);
            currentParticle = nextParticle;
            nextParticle++;
            continue;
        }

        float tInterval = (now - particle.timestamp) / 1000.0;
        // Position
        particle.position.x = particle.velocity.x * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        particle.position.y = particle.velocity.y * tInterval + 0.5 * (systemDefinition.acceleration - systemDefinition.gravity) * tInterval * tInterval; // v = v * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2        // Chaos
        // Size
        particle.size += particle.sizeDelta * tInterval;
        // Energy (alpha)
        particle.energy = WasabiMath::max(0, particle.energy - tInterval / systemDefinition.particleLifeSpan);
        // Quad update
        vertices[*currentParticle * 4].x = particle.position.x;
        vertices[*currentParticle * 4].y = particle.position.y;
        vertices[*currentParticle * 4 + 1].x = particle.position.x + particle.size;
        vertices[*currentParticle * 4 + 1].y = particle.position.y;
        vertices[*currentParticle * 4 + 2].x = particle.position.x + particle.size;
        vertices[*currentParticle * 4 + 2].y = particle.position.y + particle.size;
        vertices[*currentParticle * 4 + 3].x = particle.position.x;
        vertices[*currentParticle * 4 + 3].y = particle.position.y + particle.size;
        colors[*currentParticle * 4 + 3] = particle.energy;

        currentParticle = nextParticle;
        nextParticle++;
    }

    lastEmissionTimestamp = now;
}
