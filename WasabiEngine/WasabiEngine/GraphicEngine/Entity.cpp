/* 
 * File:   Entity.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:49
 */

#include "Entity.h"

using namespace WasabiEngine;

Entity::Entity() {
    mesh = NULL;
    color[0] = 1;
    color[1] = 1;
    color[2] = 1;
    color[3] = 1;
}

Entity::~Entity() {
    clear();
}

void Entity::clear() {
    mesh = NULL;
}

void Entity::setColor(const ColourValue& color) {
    this->color[0] = color.getRed();
    this->color[1] = color.getGreen();
    this->color[2] = color.getBlue();
    this->color[3] = color.getAlpha();
}

void Entity::setColor(const float& r, const float& g, const float &b, const float& a) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
    color[3] = a;
}

ColourValue Entity::getColor() const{
    return ColourValue(color[0], color[1], color[2], color[3]);
}

void Entity::setMesh(Mesh* mesh) {
    this->mesh = mesh;
}

void Entity::renderObject() {
    if (mesh != NULL) {
        // setting the material properties       
        glEnable(GL_COLOR_MATERIAL);
        if (mesh->hasMaterial()) {
            glMaterialfv(GL_FRONT, GL_AMBIENT, mesh->getMaterial()->amb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mesh->getMaterial()->diff);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mesh->getMaterial()->spec);
            glMaterialf(GL_FRONT, GL_SHININESS, mesh->getMaterial()->shiny);
            glColor4fv(mesh->getMaterial()->diff);
        } else {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
            glMaterialfv(GL_FRONT, GL_SPECULAR, color);
            glMaterialf(GL_FRONT, GL_SHININESS, 80);
            glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
            glColor4fv(color);
        }

        // rendering the mesh
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        if (mesh->hasTexture() && mesh->getTexCoordsArray() != NULL) {
            glEnable(GL_TEXTURE_2D);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glBindTexture(GL_TEXTURE_2D, mesh->getTextureId());
            glTexCoordPointer(2, GL_FLOAT, 0, mesh->getTexCoordsArray()); // Set the vertex pointer to our texCoord data
        }
        glVertexPointer(3, GL_FLOAT, sizeof (Vertex), mesh->getVertexArray()); // Set the vertex pointer to our vertex data
        glNormalPointer(GL_FLOAT, sizeof (Normal), mesh->getNormalArray()); // Set the vertex pointer to our normal data
        glDrawArrays(mesh->getPolygonType(), 0, mesh->getVertexCount()); // Draw All Of The Triangles At Once
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_COLOR_MATERIAL);
    }
}
