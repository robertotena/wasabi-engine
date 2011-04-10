/* 
 * File:   GraphicDemo.cpp
 * Author: Fran_2
 * 
 * Created on 21 de marzo de 2011, 11:36
 */

#include "GraphicDemo.h"
#include <Demo/DemoSystemManager.h>

GraphicDemo::GraphicDemo() {
    GameWorld3DDef worldDef;
    worldDef.width = 10;
    worldDef.length = 10;

    /* Create a world. A world updates in each frame the positions between the physic engine
     * and the graphic engine of the actors that it has attached */
    world = new GameWorld3D(worldDef, DemoSystemManager::getInstance());
    DemoSystemManager::getInstance()->setGameWorld(world);

    /* Create an actor. An actor can have a physic behaviour, a mesh, lights, etc. */
    actor = new SimpleActor();
    world->attach(actor);

    /* Create a camera */
    camera = new SimpleCamera();
    world->attach(camera);
}

GraphicDemo::~GraphicDemo() {
    delete actor;
    delete camera;
    delete world;
}
