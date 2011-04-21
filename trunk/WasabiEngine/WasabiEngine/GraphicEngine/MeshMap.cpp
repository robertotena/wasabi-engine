/* 
 * File:   MeshFactory.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 20:03
 */

#include "MeshMap.h"

using namespace WasabiEngine;

PropertyMap<Mesh*, std::string> MeshMap::meshMap;
ResourceFactory<Mesh> MeshMap::meshFactory;

MeshMap::MeshMap() {
}

MeshMap::MeshMap(const MeshMap& orig) {
}

MeshMap::~MeshMap() {
}

Mesh* MeshMap::get(const std::string& meshName) {
    Mesh** mapPtr = NULL;
    mapPtr = meshMap.get(meshName);
    if (mapPtr == NULL) {
        return NULL;
    } else {
        return *mapPtr;
    }
}

Mesh* MeshMap::get(PrefabType type) {
    Mesh* mesh = NULL;
    Mesh** mapPtr = NULL;
    switch (type) {
        case PT_PLANE:
            mapPtr = meshMap.get("__WASABI_PT_PLANE");
            if (mapPtr == NULL) {
                mesh = meshFactory.createResource();
                mesh->applyPrototype(MeshPrototype::create(type));
                meshMap.set("__WASABI_PT_PLANE", mesh);
            } else {
                mesh = *mapPtr;
            }
            break;
        case PT_CUBE:
            mapPtr = meshMap.get("__WASABI_PT_CUBE");
            if (mapPtr == NULL) {
                mesh = meshFactory.createResource();
                mesh->applyPrototype(MeshPrototype::create(type));
                meshMap.set("__WASABI_PT_CUBE", mesh);
            } else {
                mesh = *mapPtr;
            }
        case PT_SPHERE:
            mapPtr = meshMap.get("__WASABI_PT_SPHERE");
            if (mapPtr == NULL) {
                mesh = meshFactory.createResource();
                mesh->applyPrototype(MeshPrototype::create(type));
                meshMap.set("__WASABI_PT_SPHERE", mesh);
            } else {
                mesh = *mapPtr;
            }
            break;
    }
    return mesh;
}

Mesh* MeshMap::set(const std::string meshName, const MeshPrototype& meshPrototype) {
    Mesh* mesh = NULL;
    mesh = meshFactory.createResource();
    mesh->applyPrototype(meshPrototype);
    meshMap.set(meshName, mesh);

    return mesh;
}

void MeshMap::unloadAll(){
    std::list<Mesh*> meshes = meshMap.getItems();
    for(std::list<Mesh*>::iterator i = 0; i != meshes.end(); i++ ){
        *i->clear();
    }
    meshMap.clear();
}
