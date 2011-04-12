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
        //FIXME falta chaos para la velocidad
        particle.velocity.x = rand() % (int) emissionVelocity; //FIXME: La inicializacion de la velocidad es lo unico que cambia. Despues vemos que se hace con esto.
        particle.velocity.y = sqrt(emissionVelocity - particle.velocity.x * particle.velocity.x); //Pythagoras
        if (rand() % 2 - 1 < 0)
            particle.velocity.x = -particle.velocity.x;
        if (rand() % 2 - 1 < 0)
            particle.velocity.y = -particle.velocity.y;
        particle.size = systemDefinition.baseSize;
        particle.sizeDelta = systemDefinition.chaos ? (((rand() % (systemDefinition.chaos)) - systemDefinition.chaos / 2) / 10 + systemDefinition.growRate) : systemDefinition.growRate;
    }
    if(particlesToEmmit > 0)
            lastEmissionTimestamp = now;
    
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
        currentParticle = nextParticle;
        nextParticle++;

        float tInterval = (now - particle.timestamp) / 1000.0;
        // Position
        particle.position.x = particle.velocity.x * tInterval + 0.5 * systemDefinition.acceleration * tInterval * tInterval; // x = vx * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        particle.position.y = particle.velocity.y * tInterval + 0.5 * (systemDefinition.acceleration - systemDefinition.gravity) * tInterval * tInterval; // y = vy * (t1 - t0) + 1/2 * a * (t1 - t0) ^ 2
        // Size
        particle.size = systemDefinition.baseSize + systemDefinition.baseSize * (particle.sizeDelta - 1 ) * tInterval;
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
        nextParticle++;
    }
}
