/*
 * File:   Mesh.cpp
 * Author: Fran_2
 *
 * Created on 25 de noviembre de 2010, 20:06
 */

#include "Mesh.h"
#include <WasabiEngine/GraphicEngine/MeshPrototype.h>

using namespace WasabiEngine;

Mesh::Mesh() {
    vertices = NULL;
    normals = NULL;
    texCoords = NULL;
    textureId = GL_INVALID_VALUE;
    vertexCount = 0;
    normalCount = 0;
    polygonType = WASABI_TRIANGLES;
    material = NULL;
    glVBOIndex = 0;
}

Mesh::~Mesh() {
    clear();
}

void Mesh::applyPrototype(const MeshPrototype& prototype) {
    //Vertices
    if (vertices != NULL)
        delete [] vertices;
    vertexCount = prototype.vertices.size();
    vertices = new Vertex[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        vertices[i].x = prototype.vertices[i].x;
        vertices[i].y = prototype.vertices[i].y;
        vertices[i].z = prototype.vertices[i].z;
    }
    //Normals
    if (normals != NULL)
        delete [] normals;
    normalCount = prototype.normals.size();
    normals = new Normal[normalCount];
    for (int i = 0; i < normalCount; i++) {
        normals[i].x = prototype.normals[i].x;
        normals[i].y = prototype.normals[i].y;
        normals[i].z = prototype.normals[i].z;
    }
    polygonType = prototype.polygonType;

    // texture coords
    int texCoordsCount = prototype.texCoords.size();
    if (texCoordsCount > 0) {
        if (texCoords != NULL)
            delete [] texCoords;
        texCoords = new TexCoord[texCoordsCount];
        for (int i = 0; i < texCoordsCount; i++) {
            /* FIXME: No he tenido mas remedio que invertir la coordenada v de la
             * textura. El parser carga los valores bien, y los datos que llegan hasta
             * este punto son correctos. Sin embargo durante el renderizado las
             * texturas estan invertidas verticalmente por algun motivo que desconozco.
             * De momento este parche funciona, pero solamente esta enmascarando un
             * error que hay en otro sitio, y me molesta.
             */
            texCoords[i].u = prototype.texCoords[i].u;
            texCoords[i].v = 1 - prototype.texCoords[i].v;
        }
    } else {
        if (texCoords != NULL) {
            delete [] texCoords;
            texCoords = NULL;
        }
    }

    textureId = prototype.textureId;
    material = prototype.material;

    /* We could use VBO to improve the render speed
     * http://www.songho.ca/opengl/gl_vbo.html
     * http://elf-stone.com/glee.php
     */
}

void Mesh::setVertices(const Vertex* vertices, int count) {
    if (this->vertices != NULL) {
        delete [] this->vertices;
    }
    this->vertices = new Vertex[count];
    memcpy(this->vertices, vertices, count * sizeof (Vertex));
    vertexCount = count;
}

void Mesh::setNormals(const Normal* normals, int count) {
    if (this->normals != NULL) {
        delete [] this->normals;
    }
    this->normals = new Normal[count];
    memcpy(this->normals, normals, count * sizeof (Normal));
}

void Mesh::setTexCoords(const TexCoord* texCoords, int count) {
    if (this->texCoords != NULL) {
        delete [] this->texCoords;
    }
    this->texCoords = new TexCoord[count];
    memcpy(this->texCoords, texCoords, count * sizeof (TexCoord));
}

void Mesh::clear() {
    if (vertices != NULL) {
        delete [] vertices;
        vertices = NULL;
    }
    if (normals != NULL) {
        delete [] normals;
        normals = NULL;
    }
    if (texCoords != NULL) {
        delete [] texCoords;
        texCoords = NULL;
    }
    if (material != NULL) {
        delete material;
        material = NULL;
    }
}