/* 
 * File:   LightPoint.h
 * Author: Fran_2
 *
 * Created on 11 de mayo de 2011, 18:25
 */

#ifndef LIGHTPOINT_H
#define	LIGHTPOINT_H

#include <WasabiEngine/GraphicEngine/Light.h>

namespace WasabiEngine {

    class LightPoint : public Light {
    public:
        LightPoint(int index);
        LightPoint(const LightPoint& orig);
        virtual ~LightPoint();
        void renderObject();
    };
}

#endif	/* LIGHTPOINT_H */

