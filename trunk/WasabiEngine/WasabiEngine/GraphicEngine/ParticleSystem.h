/* Wasabi Engine - An academic purpose C++ game engine.
 * Copyright (c) 2011 Authors:
 * Roberto Tena <robertotg@gmail.com>
 * Franco Gotusso <gotusso@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
*/

#ifndef PARTICLESYSTEM_H
#define	PARTICLESYSTEM_H

#include <list>
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>
#include <WasabiEngine/GraphicEngine/Particle.h>
#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <vector>

namespace WasabiEngine
{
    typedef struct
    {
        /**
         * The maximum particles amount the system can emmit.
         */
        int maxParticles;
        unsigned int texture;
        float systemLifeSpan;
        /**
         * The general life span of each particle (in ms).
         */
        float particleLifeSpan;
        /**
         * The maximum particles amount the system can emmit per second.
         */
        float emissionRate;
        /**
         * A randomness factor, which is used to initialize the particles's
         * lifeSpan, growRate and acceleration in a different way.
         */
        float chaos;
        /**
         * The gravity which will vary the particles' movement.
         */
        WasVec3d gravity;
        WasVec3d acceleration;
        /**
         * The particle's base size. All the particles will have this size.
         */
        float baseSize;
        /**
         * The speed the baseSize will be changed at.
         */
        float growRate;
        /**
         * The color the particles will have. It's the same color for all of them.
         */
        ColourValue color;
    } ParticleSystemDef;

class ParticleSystem : public MovableObject {
private:
    ParticleSystem(const ParticleSystem& orig);
protected:
    Vertex* vertices;
    float* colors;
    std::list<int> aliveParticles;
    std::list<int> deadParticles;
    std::vector<Particle> particles;
    ParticleSystemDef systemDefinition;
public:
    ParticleSystem(const ParticleSystemDef& definition);
    virtual ~ParticleSystem();
    virtual void updateParticles(unsigned int timeElapsed) = 0;
    void renderObject();
};

}

#endif	/* PARTICLESYSTEM_H */

