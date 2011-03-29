/* 
 * File:   Camera.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:49
 */

#include "Camera.h"

using namespace WasabiEngine;

Camera::Camera() {
    translation[0] = 0;
    translation[1] = 0;
    translation[2] = 0;
    scaleF[0] = 1;
    scaleF[1] = 1;
    scaleF[2] = 1;
    autoTrackingEnabled = false;
    trackingTarget = NULL;
    polygonMode = PM_SOLID;
}

Camera::Camera(const Camera& orig) {
    translation[0] = orig.translation[0];
    translation[1] = orig.translation[1];
    translation[2] = orig.translation[2];
    scaleF[0] = orig.scaleF[0];
    scaleF[1] = orig.scaleF[1];
    scaleF[2] = orig.scaleF[2];
    rotation = orig.rotation;
    autoTrackingEnabled = orig.autoTrackingEnabled;
    trackingTarget = orig.trackingTarget;
    trackingOffset = orig.trackingOffset;
    polygonMode = orig.polygonMode;
}

Camera::~Camera() {
    clear();
}

std::string Camera::getName()
{
    return name;
}

void Camera::clear()
{
    trackingTarget = NULL;
}

void Camera::renderObject()
{
    if(polygonMode == PM_SOLID)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else if(polygonMode == PM_WIREFRAME)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else if(polygonMode == PM_POINTS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

    // update parameters if it's tracking
    if(autoTrackingEnabled && trackingTarget != NULL)
    {
        setOrientation(trackingTarget->getOrientation());
        setPosition(trackingTarget->getPosition() + trackingOffset);
    }

    Radian radRotation;
    WasVec3d axis;
    
    rotation.inverse().toAngleAxis(radRotation, axis);
    glRotatef(radRotation.valueDegrees(), axis.x, axis.y, axis.z);
    glTranslatef(-translation[0], -translation[1], -translation[2]);


    glBegin(GL_LINES);
        // Eje Y
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glColor4f(0.2, 0.8, 0.0, 0.8);

        glVertex3f( 0.00, 0.0, 0.0);
        glVertex3f( 0.00, 3.0, 0.0);
        glVertex3f( 0.00, 3.0, 0.0);
        glVertex3f( 0.05, 2.7, 0.0);
        glVertex3f( 0.00, 3.0, 0.0);
        glVertex3f(-0.05, 2.7, 0.0);

        // Eje X
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glColor4f(0.2, 0.0, 0.8, 0.8);

        glVertex3f(0.0,  0.01, 0.0);
        glVertex3f(3.0,  0.01, 0.0);
        glVertex3f(3.0,  0.01, 0.0);
        glVertex3f(2.7,  0.06, 0.0);
        glVertex3f(3.0,  0.01, 0.0);
        glVertex3f(2.7, -0.06, 0.0);

        // Eje Z
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glColor4f(0.8, 0.2, 0.0, 0.8);

        glVertex3f(0.0,  0.01, 0.0);
        glVertex3f(0.0,  0.01, 3.0);
        glVertex3f(0.0,  0.01, 3.0);
        glVertex3f(0.0,  0.06, 2.7);
        glVertex3f(0.0,  0.01, 3.0);
        glVertex3f(0.0, -0.06, 2.7);
    glEnd();
}

void Camera::setPolygonMode(const PolygonMode& mode)
{
    polygonMode = mode;
}

void Camera::setAutoTracking(const bool& enabled, SceneNode* target, const WasVec3d& offset)
{
    if(enabled && target != NULL)
    {
        autoTrackingEnabled = true;
        trackingTarget = target;
        trackingOffset = offset;
    }
    else
    {
        autoTrackingEnabled = false;
        trackingTarget = NULL;
    }
}

void Camera::translate(const WasVec3d& vector) {
    translation[0] += vector.x;
    translation[1] += vector.y;
    translation[2] += vector.z;
}

void Camera::setPosition(const WasVec3d& position) {
    translation[0] = position.x;
    translation[1] = position.y;
    translation[2] = position.z;
}

WasVec3d Camera::getPosition() const {
    return WasVec3d(translation[0], translation[1], translation[2]);
}

void Camera::scale(const WasVec3d& vector) {
    scaleF[0] *= vector.x;
    scaleF[1] *= vector.y;
    scaleF[2] *= vector.z;
}

void Camera::pitch(const Radian& angle) {
    rotate(WasVec3d::X_UNIT, angle);
}

void Camera::yaw(const Radian& angle) {
    rotate(WasVec3d::Y_UNIT, angle);
}

void Camera::roll(const Radian& angle) {
    rotate(WasVec3d::Z_UNIT, angle);
}

void Camera::rotate(const WasVec3d& axis, const Radian& angle) {
    Quaternion q(angle, axis);
    rotation = q * rotation;
}

const Quaternion& Camera::getOrientation() const {
    return rotation;
}

void Camera::setOrientation(const Quaternion& q) {
    rotation = q;
}

WasVec3d Camera::getDirection() const {
    WasVec3d direction = rotation * (WasVec3d::Z_UNIT);
    direction.normalize();
    direction *= -1;
    return direction;
}
