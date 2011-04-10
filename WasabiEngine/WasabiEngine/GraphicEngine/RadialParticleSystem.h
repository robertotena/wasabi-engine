/* 
 * File:   RadialParticleSystem.h
 * Author: Fran_2
 *
 * Created on 10 de abril de 2011, 18:53
 */

#ifndef RADIALPARTICLESYSTEM_H
#define	RADIALPARTICLESYSTEM_H

#include <math.h>
#include <WasabiEngine/GraphicEngine/ParticleSystem.h>
#include <WasabiEngine/Utils/WasabiTime.h>
#include <WasabiEngine/Utils/MathUtil.h>

namespace WasabiEngine {

    class RadialParticleSystem : public ParticleSystem {
    private:
        float emissionVelocity;
        RadialParticleSystem(const RadialParticleSystem& orig);
    public:
        RadialParticleSystem(const ParticleSystemDef& definition, float emissionVelocity);
        virtual ~RadialParticleSystem();
        void updateParticles();
    };
}
#endif	/* RADIALPARTICLESYSTEM_H */

