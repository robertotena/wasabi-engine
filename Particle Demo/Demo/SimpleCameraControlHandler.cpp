/* 
 * File:   SimpleCameraControlHandler.cpp
 * Author: Roberto
 * 
 * Created on 6 de marzo de 2011, 23:16
 */

#include "SimpleCameraControlHandler.h"
#include <Demo/SimpleCamera.h>

SimpleCameraControlHandler::SimpleCameraControlHandler(SimpleCamera* camera) {
    this->camera = camera;
}

SimpleCameraControlHandler::~SimpleCameraControlHandler() {
    camera = NULL;
}

void SimpleCameraControlHandler::handle(const Event* event)
{
    if (event->getIntegerProperty("state") == KEY_PRESSED) {
        switch (event->getIntegerProperty("key")) {
            case KEY_1:
                camera->setCameraMode(CAMERA_FRONT);
                break;
            case KEY_2:
                camera->setCameraMode(CAMERA_PERSPECTIVE);
                break;
            case KEY_3:
                camera->setCameraMode(CAMERA_TOP);
                break;
        }
    }
}
