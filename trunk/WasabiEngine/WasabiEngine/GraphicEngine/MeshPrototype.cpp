/* 
 * File:   MeshPrototype.cpp
 * Author: fran
 * 
 * Created on 1 de marzo de 2011, 14:02
 */

#include "MeshPrototype.h"

using namespace WasabiEngine;

MeshPrototype::MeshPrototype(PolygonType type) {
    polygonType = type;
    verticesPerFace = 0;
    setPolygonsType(type);
    material = NULL;
}

void MeshPrototype::setPolygonsType(PolygonType type) {
    polygonType = type;
    switch (polygonType) {
        case WASABI_TRIANGLES:
            verticesPerFace = 3;
            break;
        case WASABI_QUADS:
            verticesPerFace = 4;
            break;
    }
}

void MeshPrototype::addFace(const Face& face) {
    /* http://www.opengl.org/wiki/Calculating_a_Surface_Normal */
    WasVec3d normalVector;
    for (unsigned int i = 0; i < face.vertices.size(); i++) {
        vertices.push_back(face.vertices[i]);
        Vertex current(face.vertices[i]);
        Vertex next(face.vertices[(i + 1) % verticesPerFace]);
        normalVector = normalVector + WasVec3d(current.x, current.y, current.z).crossProduct(WasVec3d(next.x, next.y, next.z));
    }
    normalVector.normalize();
    Normal normal = {normalVector.x, normalVector.y, normalVector.z};
    for (unsigned int i = 0; i < face.vertices.size(); i++) {
        normals.push_back(normal);
    }
    for (unsigned int i = 0; i < face.texCoords.size(); i++) {
        texCoords.push_back(face.texCoords[i]);
    }
}

void MeshPrototype::setTextureId(unsigned int id)
{
    textureId = id;
}
void MeshPrototype::setMaterial(const Material& material)
{
    if(this->material != NULL)
        delete this->material;
    this->material = new Material(material);
}

MeshPrototype MeshPrototype::create(PrefabType type) {
    MeshPrototype mesh(WASABI_QUADS);
    switch (type) {
        case PT_PLANE:
        {
            Face f1;

            Vertex v1 = {0.5, -0.5, 0.5};
            Vertex v2 = {-0.5, -0.5, 0.5};
            Vertex v3 = {-0.5, -0.5, -0.5};
            Vertex v4 = {0.5, -0.5, -0.5};

            // Front Face
            f1.addVertex(v1);
            f1.addVertex(v2);
            f1.addVertex(v3);
            f1.addVertex(v4);
            mesh.addFace(f1);
            break;
        }
        case PT_CUBE:
        {
            Face f1, f2, f3, f4, f5, f6;

            Vertex v1 = {0.5, 0.5, 0.5};
            Vertex v2 = {-0.5, 0.5, 0.5};
            Vertex v3 = {-0.5, -0.5, 0.5};
            Vertex v4 = {0.5, -0.5, 0.5};
            Vertex v5 = {0.5, 0.5, -0.5};
            Vertex v6 = {-0.5, 0.5, -0.5};
            Vertex v7 = {-0.5, -0.5, -0.5};
            Vertex v8 = {0.5, -0.5, -0.5};

            // Front Face
            f1.addVertex(v1);
            f1.addVertex(v2);
            f1.addVertex(v3);
            f1.addVertex(v4);
            mesh.addFace(f1);

            // Right face
            f2.addVertex(v1);
            f2.addVertex(v4);
            f2.addVertex(v8);
            f2.addVertex(v5);
            mesh.addFace(f2);

            // Back Face
            f3.addVertex(v5);
            f3.addVertex(v8);
            f3.addVertex(v7);
            f3.addVertex(v6);
            mesh.addFace(f3);

            // Left Face
            f4.addVertex(v2);
            f4.addVertex(v6);
            f4.addVertex(v7);
            f4.addVertex(v3);
            mesh.addFace(f4);

            // Top Face
            f5.addVertex(v5);
            f5.addVertex(v6);
            f5.addVertex(v2);
            f5.addVertex(v1);
            mesh.addFace(f5);

            // Bottom Face
            f6.addVertex(v4);
            f6.addVertex(v3);
            f6.addVertex(v7);
            f6.addVertex(v8);
            mesh.addFace(f6);
        }
        case PT_SPHERE:
            //FIXME: Le toca a roberto. Si no esta, es su culpa.
            break;
    }
    return mesh;
}
