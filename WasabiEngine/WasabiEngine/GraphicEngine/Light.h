/* 
 * File:   Light.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:49
 */

#ifndef LIGHT_H
#define	LIGHT_H

#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <WasabiEngine/GraphicEngine/ColourValue.h>
#include <WasabiEngine/Utils/Vectors.h>

namespace WasabiEngine {

    class Light : public MovableObject {
    private:
        GLuint index;
        WasVec3d position;
        float attenuation;
        ColourValue* ambient;
        ColourValue* diffuse;
        ColourValue* specular;
        Light(const Light& orig);
    public:
        Light(int index);
        ~Light();
        int getIndex() const;
        WasVec3d getPosition() const;
        void setPosition(const WasVec3d& position);
        float getAttenuation() const;
        void setAttenuation(float attenuation);
        ColourValue const * const getAmbient() const;
        void setAmbient(const ColourValue& ambient);
        ColourValue const * const getDiffuse() const;
        void setDiffuse(const ColourValue& diffuse);
        ColourValue const * const getSpecular() const;
        void setSpecular(const ColourValue& specular);
        void renderObject() = 0;

    };
}

#endif	/* LIGHT_H */

