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
#include <vector>
#include <WasabiEngine/GraphicEngine/ParticleSystemDefinitions.h>
#include <WasabiEngine/GraphicEngine/Particle.h>
#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <WasabiEngine/GraphicEngine/GraphicDefinitions.h>

namespace WasabiEngine
{

class ParticleSystem : public MovableObject {
private:
    int nVertices;
    ParticleSystem(const ParticleSystem& orig);
protected:
    Vertex* vertices;
    TexCoord* texCoords;
    float* colors;
    unsigned int textureId;
    std::list<int> aliveParticles;
    std::list<int> deadParticles;
    std::vector<Particle> particles;
    ColourValue color;
public:
    ParticleSystem(const ParticleSystemDef* definition);
    virtual ~ParticleSystem();
    virtual void updateParticles() = 0;
    void renderObject();
    void print();
};

}

#endif	/* PARTICLESYSTEM_H */

