/* 
 * File:   Light.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:49
 */

#ifndef LIGHT_H
#define	LIGHT_H

#include <WasabiEngine/GraphicEngine/MovableObject.h>

namespace WasabiEngine {

    class Light : public MovableObject {
    public:
        Light();
        Light(const Light& orig);
        ~Light();
        void renderObject();
    };
}

#endif	/* LIGHT_H */

