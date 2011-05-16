/* 
 * File:   MeshPrototype.h
 * Author: fran
 *
 * Created on 1 de marzo de 2011, 14:02
 */

#ifndef MESHPROTOTYPE_H
#define	MESHPROTOTYPE_H

#include <vector>
#include <assert.h>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/GraphicEngine/Mesh.h>

namespace WasabiEngine {

    class Face {
    private:
        std::vector<Vertex> vertices;
        std::vector<TexCoord> texCoords;
    public:

        void addVertex(const Vertex& v) {
            vertices.push_back(v);
        }
        void addTexCoord(const TexCoord& tv) {
            texCoords.push_back(tv);
        }

        friend class MeshPrototype;
    };

    class MeshPrototype {
        std::vector<Vertex> vertices;
        std::vector<Normal> normals;
        std::vector<TexCoord> texCoords;
        PolygonType polygonType;
        int verticesPerFace;
        Material* material;
        unsigned int textureId;
    public:
        MeshPrototype(PolygonType type);
        void setPolygonsType(PolygonType type);
        void addFace(const Face& face);
        void setTextureId(unsigned int id);
        void setMaterial(const Material& material);
        static MeshPrototype create(PrefabType type);

        friend class Mesh;
    };
}

#endif	/* MESHPROTOTYPE_H */

