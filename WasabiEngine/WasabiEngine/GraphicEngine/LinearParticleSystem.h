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

#ifndef LINEARPARTICLESYSTEM_H
#define	LINEARPARTICLESYSTEM_H

#include <WasabiEngine/GraphicEngine/ParticleSystem.h>

namespace WasabiEngine {

    class LinearParticleSystem : public ParticleSystem {
    private:
        WasVec2d emissionVelocity;
        LinearParticleSystem(const LinearParticleSystem& orig);
    public:
        LinearParticleSystem(const ParticleSystemDef& definition, const WasVec2d& emissionVelocity);
        ~LinearParticleSystem();
        void updateParticles();
    };
}

#endif	/* LINEARPARTICLESYSTEM_H */

