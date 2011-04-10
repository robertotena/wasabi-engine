/* 
 * File:   GraphicDefinitions.h
 * Author: Fran_2
 *
 * Created on 10 de abril de 2011, 22:16
 */

#ifndef GRAPHICDEFINITIONS_H
#define	GRAPHICDEFINITIONS_H

#include <SDL/SDL_opengl.h>
#include <GL/glext.h>

namespace WasabiEngine {

    enum PrefabType {
        PT_PLANE,
        PT_CUBE,
        PT_SPHERE
    };

    enum PolygonType {
        WASABI_TRIANGLES = GL_TRIANGLES,
        WASABI_QUADS = GL_QUADS
    };

    /* Do not transform this in a class.
     * On this way is equivalent to a
     * float[3] array, because the struct
     * is packed. A single float fits a word.
     */
    typedef struct {
        float x;
        float y;
        float z;
    } Vertex, Normal;

    typedef struct {
        float u;
        float v;
    } TexCoord;
}

#endif	/* GRAPHICDEFINITIONS_H */

