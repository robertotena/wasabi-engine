/* 
 * File:   SceneryDefinition.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 4 de marzo de 2011, 18:49
 */

#ifndef SCENERYDEFINITION_H
#define	SCENERYDEFINITION_H

#include <string>
#include <WasabiEngine/PhysicEngine/PhysicDefinitions.h>
#include <WasabiEngine/Utils/Vectors.h>

namespace WasabiEngine {

    typedef struct SceneryDef {
        /**
         * Physic body type: #BodyType
         */
        BodyType physicBodyType;
        /**
         * Position of the body
         */
        WasVec2d position;
        /**
         * Rotation angle in degrees
         */
        float rotation;
        /**
         * Width of the body in meters
         */
        float width;
        /**
         * Length of the body in meters
         */
        float length;
        /**
         * Mass of the body in KG
         */
        float mass;
        /**
         * Path to mesh file
         */
        std::string meshFile;
        SceneryDef(){
            physicBodyType = PHYSIC_DYNAMIC_BODY;
            rotation = 0;
            width = 1;
            length = 1;
            mass = 10;
        }
    } SceneryDefinition;
}
#endif	/* SCENERYDEFINITION_H */

