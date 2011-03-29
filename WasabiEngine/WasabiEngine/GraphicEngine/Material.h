/* 
 * File:   Material.h
 * Author: Roberto
 *
 * Created on 3 de marzo de 2011, 0:12
 */

#ifndef MATERIAL_H
#define	MATERIAL_H

namespace WasabiEngine {

    /**
     * A material modifies the light behaviour on a entity.
     */
    class Material {
    public:
        float amb[4]; // Ambient reflectance values
        float diff[4]; // Diffuse reflectance values
        float spec[4]; // Specular reflectance values
        float shiny; // Sharpness of specular highlight
        Material();
        Material(const Material& orig);
    };

}

#endif	/* MATERIAL_H */

