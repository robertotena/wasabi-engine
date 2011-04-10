/* 
 * File:   RaceCamera.h
 * Author: Roberto
 *
 * Created on 5 de marzo de 2011, 11:03
 */

#ifndef RACECAMERA_H
#define	RACECAMERA_H

#include <WasabiEngine/WasabiEngine.h>
#include <Demo/SimpleCameraControlHandler.h>

using namespace WasabiEngine;

enum CameraMode {
    CAMERA_FRONT, CAMERA_PERSPECTIVE, CAMERA_TOP
};

class SimpleCamera : public Actor {
private:
    Camera* camera;
    CameraMode mode;
    SimpleCameraControlHandler controlHandler;
    HandlerRegistration* controlHR;
    SimpleCamera(const SimpleCamera& orig);
public:
    SimpleCamera();
    ~SimpleCamera();
    void setCameraMode(const CameraMode& mode);
    void update();
};

inline void SimpleCamera::setCameraMode(const CameraMode& mode) {
    this->mode = mode;
}

#endif	/* RACECAMERA_H */

