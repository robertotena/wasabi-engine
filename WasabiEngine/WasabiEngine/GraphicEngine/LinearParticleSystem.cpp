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
        particle.velocity.x = systemDefinition.chaos ? (rand() % systemDefinition.chaos - systemDefinition.chaos / 2 + systemDefinition.emissionVelocity.x) : systemDefinition.emissionVelocity.x;
        particle.velocity.y = systemDefinition.chaos ? (rand() % systemDefinition.chaos - systemDefinition.chaos / 2 + systemDefinition.emissionVelocity.y) : systemDefinition.emissionVelocity.y;
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
        // Quad update
        vertices[*currentParticle * 4].x = particle.position.x - particle.size / 2;
        vertices[*currentParticle * 4].y = particle.position.y - particle.size / 2;
        vertices[*currentParticle * 4 + 1].x = particle.position.x + particle.size / 2;
        vertices[*currentParticle * 4 + 1].y = particle.position.y - particle.size / 2;
        vertices[*currentParticle * 4 + 2].x = particle.position.x + particle.size / 2;
        vertices[*currentParticle * 4 + 2].y = particle.position.y + particle.size / 2;
        vertices[*currentParticle * 4 + 3].x = particle.position.x - particle.size / 2;
        vertices[*currentParticle * 4 + 3].y = particle.position.y + particle.size / 2;
        //Alpha channel update
        colors[*currentParticle * 16 + 3] = particle.energy;
        colors[*currentParticle * 16 + 7] = particle.energy;
        colors[*currentParticle * 16 + 11] = particle.energy;
        colors[*currentParticle * 16 + 15] = particle.energy;

        currentParticle = nextParticle;
    }
}
