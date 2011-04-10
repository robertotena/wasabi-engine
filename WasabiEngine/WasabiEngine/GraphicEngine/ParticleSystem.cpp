/* 
 * File:   ParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:23
 */

#include "ParticleSystem.h"

using namespace WasabiEngine;

ParticleSystem::ParticleSystem(const ParticleSystemDef& def){
    int i, nVertices;
    systemDefinition = def;
    nVertices = def.maxParticles * 4;
    vertices = new Vertex[nVertices]; // 4 vertex per particle
    texCoords = new TexCoord[nVertices]; // 4 texture coords per particle
    colors = new float[nVertices * 4]; // r,g,b,a for each vertex, for each particle
    for(i = 0; i < def.maxParticles; i++)
        deadParticles.push_back(i);
    for(i = 0; i < nVertices; i++)
    {
        switch (i%4)
        {
            case 0:
                texCoords[i].u = 0.0;
                texCoords[i].v = 0.0;
                break;
            case 1:
                texCoords[i].u = 0.0;
                texCoords[i].v = 1.0;
                break;
            case 2:
                texCoords[i].u = 1.0;
                texCoords[i].v = 1.0;
                break;
            case 3:
                texCoords[i].u = 0.0;
                texCoords[i].v = 1.0;
                break;
        }
    }
    particles.reserve(def.maxParticles);
}

ParticleSystem::ParticleSystem(const ParticleSystem& orig) {
    // not allowed
}

ParticleSystem::~ParticleSystem() {
    // FIXME: destroy particles?
}

void ParticleSystem::renderObject()
{
    glPushMatrix();

    SceneNode* parent = getParentSceneNode();
    Camera* activeCamera = GraphicEngine::getInstance()->getActiveCamera();
    Radian radRotation;
    WasVec3d axis;
    // invert previous rotations
    while(parent != NULL)
    {    
        parent->getOrientation().inverse().toAngleAxis(radRotation, axis);
        glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
        parent = parent->getParentSceneNode();
    }
    // same rotation as camera
    if(activeCamera != NULL)
    {
        activeCamera->getOrientation().toAngleAxis(radRotation, axis);
        glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
    }

    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_COLOR_MATERIAL);

    // particle materials
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, systemDefinition.color.ptr());
    glMaterialfv(GL_FRONT, GL_SPECULAR, systemDefinition.color.ptr());
    glMaterialf(GL_FRONT, GL_SHININESS, 80);

    glBindTexture(GL_TEXTURE_2D, systemDefinition.texture);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    // FIXME: no estoy seguro del stride, yo diria que es 0, pero no me convence el sizeof(Vertex)
    glColorPointer(4, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, sizeof (Vertex), vertices);
    glDrawArrays(4, 0, systemDefinition.maxParticles * 4);

    // disabling states
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);

//        // rendering the mesh
//        glEnableClientState(GL_NORMAL_ARRAY);
//        glEnableClientState(GL_VERTEX_ARRAY);
//        if (mesh->hasTexture() && mesh->getTexCoordsArray() != NULL) {
//            glEnable(GL_TEXTURE_2D);
//            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//            glBindTexture(GL_TEXTURE_2D, mesh->getTextureId());
//            glTexCoordPointer(2, GL_FLOAT, 0, mesh->getTexCoordsArray()); // Set the vertex pointer to our texCoord data
//        }
//        glVertexPointer(3, GL_FLOAT, sizeof (Vertex), mesh->getVertexArray()); // Set the vertex pointer to our vertex data
//        glNormalPointer(GL_FLOAT, sizeof (Normal), mesh->getNormalArray()); // Set the vertex pointer to our normal data
//        glDrawArrays(mesh->getPolygonType(), 0, mesh->getVertexCount()); // Draw All Of The Triangles At Once
//        glDisableClientState(GL_VERTEX_ARRAY);
//        glDisableClientState(GL_NORMAL_ARRAY);
//        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}
