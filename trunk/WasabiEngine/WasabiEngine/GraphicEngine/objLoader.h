#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <cstdio>
#include <WasabiEngine/GraphicEngine/ObjParser.h>

namespace WasabiEngine {

    /* Wavefront (obj) loader
     * This is a basic .obj loader. It can parse vertices, texture coordinates,
     * normals, 3 or 4 vertex faces, and .mtl files. There is also support for
     * non-standard object types that are relevant to raytracing.
     * http://kixor.net/dev/objloader/
     */
    class objLoader {
    private:
        obj_scene_data data;
    public:

        objLoader() {
            vertexList = NULL;
            normalList = NULL;
            textureList = NULL;

            faceList = NULL;
            sphereList = NULL;
            planeList = NULL;

            lightPointList = NULL;
            lightQuadList = NULL;
            lightDiscList = NULL;

            materialList = NULL;

            vertexCount = 0;
            normalCount = 0;
            textureCount = 0;

            faceCount = 0;
            sphereCount = 0;
            planeCount = 0;

            lightPointCount = 0;
            lightQuadCount = 0;
            lightDiscCount = 0;

            materialCount = 0;
        }

        ~objLoader() {
            ObjParser::delete_obj_data(&data);
        }

        int load(const char *filename);

        obj_vector **vertexList;
        obj_vector **normalList;
        obj_vector **textureList;

        obj_face **faceList;
        obj_sphere **sphereList;
        obj_plane **planeList;

        obj_light_point **lightPointList;
        obj_light_quad **lightQuadList;
        obj_light_disc **lightDiscList;

        obj_material **materialList;

        int vertexCount;
        int normalCount;
        int textureCount;

        int faceCount;
        int sphereCount;
        int planeCount;

        int lightPointCount;
        int lightQuadCount;
        int lightDiscCount;

        int materialCount;

        obj_camera *camera;
    };
}
#endif
