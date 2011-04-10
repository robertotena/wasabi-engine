/* 
 * File:   RaceCameraControlHandler.h
 * Author: Roberto
 *
 * Created on 6 de marzo de 2011, 23:16
 */

#ifndef RACECAMERACONTROLHANDLER_H
#define	RACECAMERACONTROLHANDLER_H

#include <WasabiEngine/WasabiEngine.h>

using namespace WasabiEngine;

class SimpleCamera;

class SimpleCameraControlHandler : public KeyboardEventHandler {
private:
    SimpleCamera* camera;
public:
    SimpleCameraControlHandler(SimpleCamera* camera);
    ~SimpleCameraControlHandler();
    void handle(const Event* event);
};

#endif	/* RACECAMERACONTROLHANDLER_H */

