/* 
 * File:   MeshLoader.h
 * Author: fran
 *
 * Created on 1 de marzo de 2011, 18:32
 */

#ifndef MESHLOADER_H
#define	MESHLOADER_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <WasabiEngine/GraphicEngine/Mesh.h>
#include <WasabiEngine/GraphicEngine/MeshMap.h>
#include <WasabiEngine/GraphicEngine/MeshPrototype.h>
#include <WasabiEngine/GraphicEngine/TextureLoader.h>
#include <WasabiEngine/GraphicEngine/objLoader.h>

namespace WasabiEngine {

    /* Wrapper sobre un cargador de mallas OBJ.
     * Voy a asumir que todas las caras de la definicion de
     * un objeto estan formadas por el mismo numero de vertices
     * (3 o 4). En otro caso, fallara.
     * Especificacion del formato:
     * http://paulbourke.net/dataformats/obj/
     */

    /**
     * OBJ File loader.
     */
    class MeshLoader {
    public:
        static Mesh* load(const std::string& file);
        static Mesh* load(PrefabType type);
        static Mesh* load(const MeshPrototype& prototype);
    };
}
#endif	/* MESHLOADER_H */

