/* 
 * File:   SpotLight.h
 * Author: Fran_2
 *
 * Created on 16 de mayo de 2011, 11:41
 */

#ifndef SPOTLIGHT_H
#define	SPOTLIGHT_H

#include <WasabiEngine/GraphicEngine/Light.h>

namespace WasabiEngine {

    class SpotLight : public Light {
    private:
        float cutoff;
        WasVec3d direction;
    public:
        SpotLight(int index);
        SpotLight(const SpotLight& orig);
        virtual ~SpotLight();
        float getCutoff() const;
        void setCutoff(float cutoff);
        WasVec3d getDirection() const;
        void setDirection(const WasVec3d& direction);        
        void renderObject();
    };
}

#endif	/* SPOTLIGHT_H */

