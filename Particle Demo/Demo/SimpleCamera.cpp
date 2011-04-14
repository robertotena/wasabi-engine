/* 
 * File:   RaceCamera.cpp
 * Author: Roberto
 * 
 * Created on 5 de marzo de 2011, 11:03
 */

#include "SimpleCamera.h"

SimpleCamera::SimpleCamera() : controlHandler(this) {
    /* Create the camera */
    camera = GraphicEngine::getInstance()->createCamera("SimpleCamera");
    controlHR = EventEngine::getInstance()->addHandler(&controlHandler, false);
    mode = CAMERA_FRONT;
    update();
}

SimpleCamera::SimpleCamera(const SimpleCamera& orig) : controlHandler(this) {
    // not allowed
}

SimpleCamera::~SimpleCamera() {
    controlHR->removeHandler();
    GraphicEngine::getInstance()->destroyCamera(camera);
}

void SimpleCamera::update() {
    /* Change the position and orientation of the camera based in the used camera type */
    if (mode == CAMERA_PERSPECTIVE) {
        camera->setPosition(WasVec3d(10, 2, 10));
        camera->setOrientation(Quaternion(Radian(Degree(45)), WasVec3d::Y_UNIT));
    } else if (mode == CAMERA_FRONT) {
        camera->setPosition(WasVec3d(0, 1, 10));
        camera->setOrientation(Quaternion(Radian(Degree(0)), WasVec3d::Y_UNIT));
    } else if (mode == CAMERA_TOP) {
        camera->setPosition(WasVec3d(0, 10, 0));
        camera->setOrientation(Quaternion(Radian(Degree(-90)), WasVec3d::X_UNIT));
    }
}


