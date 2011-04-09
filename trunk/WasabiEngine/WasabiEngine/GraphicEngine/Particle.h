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

#ifndef PARTICLE_H
#define	PARTICLE_H

#include <WasabiEngine/Utils/Vectors.h>

namespace WasabiEngine {

    /**
     * A particle is the simpliest element in any particle system. It can represent
     * any small object, like a snowflake or a raindrop.
     */
    typedef struct {
        /**
         * Position of the particle
         */
        WasVec2d position;
        /**
         * Remaining particle energy (life)
         */
        float energy;
        /**
         * Current velocity vector
         */
        WasVec2d velocity;
        /**
         * Current velocity variation
         */
        WasVec2d velocityDelta;
        /**
         * Size of the particle
         */
        float size;
        /**
         * Current variation of the particle
         */
        float sizeDelta;
    } Particle;
}

#endif	/* PARTICLE_H */

