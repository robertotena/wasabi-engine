/* 
 * File:   SystemManager.cpp
 * Author: Fran_2
 * 
 * Created on 3 de diciembre de 2010, 18:57
 */

#include "Demo.h"

Demo::Demo() {
    GraphicEngineConf geConf;
    geConf.width = 1024;
    geConf.height = 768;
    geConf.wmCaption = "Particle Demo";

    gameEngine.setVideoMode(geConf);
    gameEngine.setGameLoop(&gameLoop);

    /* Create an actor. An actor can have a physic behaviour, a mesh, lights, etc. */
    actor = new SimpleActor();
    gameEngine.getGameWorld()->attach(actor);

    /* Create a camera */
    camera = new SimpleCamera();
    gameEngine.getGameWorld()->attach(camera);
}

Demo::~Demo() {
    delete actor;
    delete camera;
}

void Demo::run() {
    gameEngine.run();
}