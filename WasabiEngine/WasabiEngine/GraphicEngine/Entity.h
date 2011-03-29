/* 
 * File:   Entity.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:49
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <SDL/SDL_opengl.h>
#include <WasabiEngine/GraphicEngine/ColourValue.h>
#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <WasabiEngine/GraphicEngine/Mesh.h>

namespace WasabiEngine {

    /**
     * An entity is a 3D object with or without textures.
     */
    class Entity : public MovableObject {
    private:
        Mesh* mesh;
        unsigned int glListId;
        float color[4];
    public:
        Entity();
        ~Entity();
        void setMesh(Mesh* mesh);
        void setColor(const ColourValue& color);
        void setColor(const float& r, const float& g, const float &b, const float &a = 1.f);
        ColourValue getColor() const;
        void clear();
        void renderObject();
    };
}

#endif	/* ENTITY_H */

