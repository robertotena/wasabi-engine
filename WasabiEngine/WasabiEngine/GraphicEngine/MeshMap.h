/* 
 * File:   MeshFactory.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 20:03
 */

#ifndef MESHFACTORY_H
#define	MESHFACTORY_H

#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/GraphicEngine/Mesh.h>
#include <WasabiEngine/GraphicEngine/MeshPrototype.h>

namespace WasabiEngine {

    class MeshMap {
    private:
        static PropertyMap<Mesh*, std::string> meshMap;
        static ResourceFactory<Mesh> meshFactory;
        MeshMap();
        MeshMap(const MeshMap& orig);
        virtual ~MeshMap();
    public:
        static Mesh* get(const std::string& meshName);
        static Mesh* get(PrefabType type);
        static Mesh* set(const std::string meshName, const MeshPrototype& meshPrototype);
        static Mesh* set(const MeshPrototype& meshPrototype); //Non-Cacheable
        /* Las mallas en principio no las sacamos de memoria automaticamente
         * hasta que cerremos el juego, por el costo que tiene cargarlas.
         * Aun asi, metemos un metodo manual por si acaso.
         */
        static void unloadAll();
    };
}

#endif	/* MESHFACTORY_H */
