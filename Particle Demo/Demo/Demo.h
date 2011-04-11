/* 
 * File:   Demo.h
 * Author: Fran_2
 *
 * Created on 3 de diciembre de 2010, 18:57
 */

#ifndef DEMO_H
#define	DEMO_H

#include <WasabiEngine/WasabiEngine.h>
#include <Demo/SimpleActor.h>
#include <Demo/SimpleCamera.h>

using namespace WasabiEngine;

class Demo {
private:
    GameSystemManager gameEngine;
    GameLoop gameLoop;
    SimpleActor* actor;
    SimpleCamera* camera;
    Demo();
public:
    ~Demo();
    static Demo* getInstance();
    void run();
};

inline Demo* Demo::getInstance() {
    static Demo instance;
    return &instance;
}

#endif	/* DEMO_H */
