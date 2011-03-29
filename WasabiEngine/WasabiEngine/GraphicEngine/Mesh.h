/*
 * File:   Mesh.h
 * Author: Fran_2
 *
 * Created on 25 de noviembre de 2010, 20:06
 */

#ifndef MESH_H
#define	MESH_H

#include <SDL/SDL_opengl.h>
#include <GL/glext.h>
#include <vector>
#include <cstring>
#include <WasabiEngine/GraphicEngine/Material.h>

namespace WasabiEngine {

    enum PrefabType {
        PT_PLANE,
        PT_CUBE,
        PT_SPHERE
    };

    enum PolygonType {
        WASABI_TRIANGLES = GL_TRIANGLES,
        WASABI_QUADS = GL_QUADS
    };

    /* Do not transform this in a class.
     * On this way is equivalent to a
     * float[3] array, because the struct
     * is packed. A single float fits a word.
     */ 
    typedef struct {
        float x;
        float y;
        float z;
    } Vertex, Normal;
    
    typedef struct {
        float u;
        float v;
    } TexCoord;

    class MeshPrototype;

    class Mesh {
    private:
        int vertexCount;
        int normalCount; //for debug
        int texCoordCount;
        Vertex* vertices;
        Normal* normals;
        TexCoord* texCoords;
        PolygonType polygonType;
        unsigned int textureId;
        unsigned int glVBOIndex;
        Material* material;
    public:
        Mesh();
        ~Mesh();
        void applyPrototype(const MeshPrototype& prototype);
        Vertex* getVertexArray();
        Normal* getNormalArray();
        TexCoord* getTexCoordsArray();
        void setVertices(const Vertex* vertices, int count);
        void setNormals(const Normal* normals, int count);
        void setTexCoords(const TexCoord* texCoords, int count);
        int getVertexCount();
        unsigned int getGlVBOIndex();
        PolygonType getPolygonType();
        unsigned int getTextureId();
        Material* getMaterial();
        bool hasTexture();
        bool hasMaterial();

        void clear();
        friend class MeshLoader;
    };

    inline Vertex* Mesh::getVertexArray() {
        return vertices;
    }

    inline Normal* Mesh::getNormalArray() {
        return normals;
    }

    inline TexCoord* Mesh::getTexCoordsArray() {
        return texCoords;
    }

    inline int Mesh::getVertexCount() {
        return vertexCount;
    }

    inline unsigned int Mesh::getGlVBOIndex(){
        return glVBOIndex;
    }
    
    inline PolygonType Mesh::getPolygonType(){
        return polygonType;
    }

    inline unsigned int Mesh::getTextureId()
    {
        return textureId;
    }

    inline Material* Mesh::getMaterial()
    {
        return material;
    }

    inline bool Mesh::hasTexture()
    {
        return textureId != GL_INVALID_VALUE;
    }

    inline bool Mesh::hasMaterial()
    {
        return material != NULL;
    }
}

#endif	/* MESH_H */
