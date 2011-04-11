/* 
 * File:   ParticleSystem.cpp
 * Author: Roberto
 * 
 * Created on 5 de abril de 2011, 13:23
 */

#include "ParticleSystem.h"
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>
#include <iostream>
using namespace WasabiEngine;

ParticleSystem::ParticleSystem(const ParticleSystemDef* def) {
    int i;
    color = def->color;
    nVertices = def->maxParticles * 4;
    // vertex array
    vertices = new Vertex[nVertices]; // 4 vertex per particle
    for (i = 0; i < nVertices; i++) {
        vertices[i].x = 0;
        vertices[i].y = 0;
        vertices[i].z = 0;
    }
    // the color array
    colors = new float[nVertices * 4]; // r,g,b,a for each vertex, for each particle
    for (i = 0; i < nVertices * 4; i++) {
        switch (i % 4) {
            case 0:
                colors[i] = color.getRed();
                break;
            case 1:
                colors[i] = color.getGreen();
                break;
            case 2:
                colors[i] = color.getBlue();
                break;
            case 3:
                colors[i] = color.getAlpha();
                break;
        }
    }
    // the texture coord array
    texCoords = new TexCoord[nVertices]; // 4 texture coords per particle
    for (i = 0; i < nVertices; i++) {
        switch (i % 4) {
            case 0:
                texCoords[i].u = 0.0;
                texCoords[i].v = 0.0;
                break;
            case 1:
                texCoords[i].u = 1.0;
                texCoords[i].v = 0.0;
                break;
            case 2:
                texCoords[i].u = 1.0;
                texCoords[i].v = 1.0;
                break;
            case 3:
                texCoords[i].u = 1.0;
                texCoords[i].v = 0.0;
                break;
        }
    }
    textureId = TextureLoader::load(def->texturePath);
    for (i = 0; i < def->maxParticles; i++)
        deadParticles.push_back(i);
    // creating particles
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
    print();
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

void ParticleSystem::print()
{
    std::cout << "==============SISTEMA==============" << std::endl;
    std::cout << "===================================" << std::endl;
    for(int i = 0; i < nVertices; i=i+4)
    {
        if(colors[i*4 + 3] > 0.2)
        {
            std::cout << "====PARTICULA====" << std::endl;
            std::cout << "vertices:" << "(" << vertices[i].x <<"," << vertices[i].y <<"," << vertices[i].z << "), (" << vertices[i+1].x << "," << vertices[i+1].y <<"," <<vertices[i+1].z << "), (" << vertices[i+2].x <<"," << vertices[i+2].y << "," << vertices[i+2].z << "), (" << vertices[i+3].z << "," << vertices[i+3].y <<"," << vertices[i+3].z <<")" << std::endl;
            std::cout << "colors:" << colors[i] <<"," << colors[i+1] << "," << colors[i+2] << "," << colors[i+3] << std::endl;
        }
    }
}
