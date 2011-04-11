/* 
 * File:   ParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:23
 */

#include "ParticleSystem.h"
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>

using namespace WasabiEngine;

ParticleSystem::ParticleSystem(const ParticleSystemDef* def) {
    int i;
    color = def->color;
    nVertices = def->maxParticles * 4;
    vertices = new Vertex[nVertices]; // 4 vertex per particle
    for (int i = 0; i < nVertices; i++) {
        vertices[i].x = 0;
        vertices[i].y = 0;
        vertices[i].z = 0;
    }
    colors = new float[nVertices * 4]; // r,g,b,a for each vertex, for each particle
    for (int i = 0; i < nVertices * 4; i++) {
        colors[i] = 0;
    }
    texCoords = new TexCoord[nVertices]; // 4 texture coords per particle
    for (i = 0; i < nVertices; i++) {
        switch (i % 4) {
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
    textureId = TextureLoader::load(def->texturePath);
    for (i = 0; i < def->maxParticles; i++)
        deadParticles.push_back(i);
    particles.reserve(def->maxParticles);
}

ParticleSystem::ParticleSystem(const ParticleSystem& orig) {
    // not allowed
}

ParticleSystem::~ParticleSystem() {
    // FIXME: destroy particles?
}

void ParticleSystem::renderObject() {
    updateParticles();
    
    glPushMatrix();

    SceneNode* parent = getParentSceneNode();
    Camera* activeCamera = GraphicEngine::getInstance()->getActiveCamera();
    Radian radRotation;
    WasVec3d axis;
    // invert previous rotations
    while (parent != NULL) {
        parent->getOrientation().inverse().toAngleAxis(radRotation, axis);
        glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
        parent = parent->getParentSceneNode();
    }
    // same rotation as camera
    if (activeCamera != NULL) {
        activeCamera->getOrientation().toAngleAxis(radRotation, axis);
        glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
    }

    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_COLOR_MATERIAL);

    // particle materials
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color.ptr());
    glMaterialfv(GL_FRONT, GL_SPECULAR, color.ptr());
    glMaterialf(GL_FRONT, GL_SHININESS, 80);

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    // FIXME: no estoy seguro del stride, yo diria que es 0, pero no me convence el sizeof(Vertex)
    glColorPointer(4, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, sizeof (Vertex), vertices);
    glDrawArrays(4, 0, nVertices);

    // disabling states
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);

    glPopMatrix();
}
