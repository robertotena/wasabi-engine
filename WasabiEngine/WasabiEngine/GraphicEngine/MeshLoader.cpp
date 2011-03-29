/* 
 * File:   MeshLoader.cpp
 * Author: fran
 * 
 * Created on 1 de marzo de 2011, 18:32
 */

#include "MeshLoader.h"

using namespace WasabiEngine;

Mesh* MeshLoader::load(const std::string& file) {
    //Check if we have the mesh loaded
    Mesh* mesh = MeshMap::get(file);
    if (mesh != NULL)
        return mesh;

    //Load file
    MeshPrototype meshPrototype(WASABI_TRIANGLES);
    objLoader parser;
    parser.load(file.c_str());
    int verticesCount = 0; //for debug
    int facesCount = 0; //for debug
    bool hasTextureCoords = parser.textureCount > 0;

    //Put vertices, normals and textures in our mesh structure
    if (parser.faceCount > 0) {
        switch (parser.faceList[0]->vertex_count) {
            case 3:
                break;
            case 4:
                meshPrototype.setPolygonsType(WASABI_QUADS);
                break;
            default:
                std::cerr << "Mesh file " << file << " not supported (Has " << parser.faceList[0]->vertex_count << " vertices per face)" << std::endl;
                exit(-1);
        }

        for (int i = 0; i < parser.faceCount; i++) {
            Face facePrototype;
            obj_face* face = parser.faceList[i];
            for (int j = 0; j < face->vertex_count; j++) {
                float x = parser.vertexList[face->vertex_index[j]]->e[0];
                float y = parser.vertexList[face->vertex_index[j]]->e[1];
                float z = parser.vertexList[face->vertex_index[j]]->e[2];

                verticesCount++;
                Vertex v = {x, y, z};
                facePrototype.addVertex(v);

                if (hasTextureCoords) {
                    float u = parser.textureList[face->texture_index[j]]->e[0];
                    float v = parser.textureList[face->texture_index[j]]->e[1];
                    TexCoord vt = {u, v};
                    facePrototype.addTexCoord(vt);
                }
            }
            facesCount++;
            meshPrototype.addFace(facePrototype);
        }
        std::cerr << file << " loaded. " << facesCount << " faces. " << parser.vertexCount << " vertices defined. " << verticesCount << " used." << std::endl;
    }
    // setting the texture id and material
    if (parser.materialCount > 0) {
        meshPrototype.setTextureId(TextureLoader::load(parser.materialList[0]->texture_filename));
        obj_material* materialDef = parser.materialList[0];
        Material mat;
        mat.amb[0] = materialDef->amb[0];
        mat.amb[1] = materialDef->amb[1];
        mat.amb[2] = materialDef->amb[2];
        mat.amb[3] = materialDef->trans;
        mat.diff[0] = materialDef->diff[0];
        mat.diff[1] = materialDef->diff[1];
        mat.diff[2] = materialDef->diff[2];
        mat.diff[3] = materialDef->trans;
        mat.spec[0] = materialDef->spec[0];
        mat.spec[1] = materialDef->spec[1];
        mat.spec[2] = materialDef->spec[2];
        mat.spec[3] = materialDef->trans;
        mat.shiny = materialDef->shiny;
        meshPrototype.setMaterial(mat);
    }

    return MeshMap::set(file, meshPrototype);
}

Mesh* MeshLoader::load(PrefabType type) {
    return MeshMap::get(type);
}
