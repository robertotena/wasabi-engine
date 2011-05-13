/* 
 * File:   SceneNode.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:10
 */

#include "SceneNode.h"

using namespace WasabiEngine;

SceneNode::SceneNode() {
    translation[0] = 0;
    translation[1] = 0;
    translation[2] = 0;
    scaleF[0] = 1;
    scaleF[1] = 1;
    scaleF[2] = 1;
    visible = true;
    parent = NULL;
}

SceneNode::SceneNode(const SceneNode& orig) {
    translation[0] = orig.translation[0];
    translation[1] = orig.translation[1];
    translation[2] = orig.translation[2];
    scaleF[0] = orig.scaleF[0];
    scaleF[1] = orig.scaleF[1];
    scaleF[2] = orig.scaleF[2];
    rotation = orig.rotation;
    visible = orig.visible;
    parent = orig.parent;
    for (std::list<SceneNode*>::const_iterator node = orig.children.begin(); node != orig.children.end(); node++) {
        children.push_back(new SceneNode(**node));
    }
    for (std::list<MovableObject*>::const_iterator object = orig.objects.begin(); object != orig.objects.end(); object++) {
        objects.push_back(*object);
    }
}

SceneNode::~SceneNode() {
    removeAllChildren();
}

void SceneNode::translate(const WasVec3d& vector) {
    translation[0] += vector.x;
    translation[1] += vector.y;
    translation[2] += vector.z;
}

void SceneNode::setPosition(const WasVec3d& position) {
    translation[0] = position.x;
    translation[1] = position.y;
    translation[2] = position.z;
}

WasVec3d SceneNode::getPosition() const {
    return WasVec3d(translation[0], translation[1], translation[2]);
}

void SceneNode::scale(const WasVec3d& vector) {
    scaleF[0] *= vector.x;
    scaleF[1] *= vector.y;
    scaleF[2] *= vector.z;
}

void SceneNode::pitch(const Radian& angle) {
    rotate(WasVec3d::X_UNIT, angle);
}

void SceneNode::yaw(const Radian& angle) {
    rotate(WasVec3d::Y_UNIT, angle);
}

void SceneNode::roll(const Radian& angle) {
    rotate(WasVec3d::Z_UNIT, angle);
}

void SceneNode::rotate(const WasVec3d& axis, const Radian& angle) {
    Quaternion q(angle, axis);
    rotation = q * rotation;
}

const Quaternion& SceneNode::getOrientation() const {
    return rotation;
}

void SceneNode::setOrientation(const Quaternion& q) {
    rotation = q;
}

SceneNode* SceneNode::createChild(const WasVec3d& translation) {
    SceneNode* node = new SceneNode();
    node->parent = this;
    node->translate(translation);
    children.push_back(node);
    return node;
}

void SceneNode::removeChild(SceneNode* node) {
    std::list<SceneNode*>::iterator i = std::find(children.begin(), children.end(), node);
    if (i != children.end()) {
        delete *i;
        children.erase(i);
    }
}

void SceneNode::removeAllChildren() {
    for (std::list<SceneNode*>::iterator node = children.begin(); node != children.end(); node++) {
        delete *node;
    }
    children.clear();
}

SceneNode* SceneNode::getParentSceneNode() {
    return parent;
}

void SceneNode::showBoundingBox(bool show) {
    //FIXME
}

void SceneNode::setVisible(bool visible) {
    this->visible = visible;
}

bool SceneNode::isVisible() const {
    return visible;
}

void SceneNode::attachObject(MovableObject* object) {
    objects.push_back(object);
    object->parentSceneNode = this;
}

void SceneNode::insertObject(MovableObject* object, int index) {
    std::list<MovableObject*>::iterator it = objects.begin();
    for (int i = 0; i < objects.size() && i < index; i++)
        it++;
    objects.insert(it, object);
    object->parentSceneNode = this;
}

void SceneNode::detachObject(MovableObject* object) {
    std::list<MovableObject*>::iterator i = std::find(objects.begin(), objects.end(), object);
    if (i != objects.end()) {
        objects.erase(i);
        (*i)->parentSceneNode = NULL;
    }
}

void SceneNode::renderNode() {
    Radian radRotation;
    WasVec3d axis;

    glTranslatef(translation[0], translation[1], translation[2]); // Move object
    rotation.toAngleAxis(radRotation, axis);
    glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
    glScalef(scaleF[0], scaleF[1], scaleF[2]);
    std::list<MovableObject*>::iterator it;
    for (it = objects.begin(); it != objects.end(); it++)
        (*it)->renderObject();
}
