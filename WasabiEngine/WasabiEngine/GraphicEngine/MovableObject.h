/* 
 * File:   MovableObject.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:27
 */

#ifndef MOVABLEOBJECT_H
#define	MOVABLEOBJECT_H

#include <string>
#include <GL/gl.h>

namespace WasabiEngine {
    
    class MovableObject {
    public:
        virtual ~MovableObject() {}
        virtual void renderObject() = 0;
    };
}
#endif	/* MOVABLEOBJECT_H */

