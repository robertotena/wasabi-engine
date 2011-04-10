/* 
 * File:   SystemManager.cpp
 * Author: Fran_2
 * 
 * Created on 3 de diciembre de 2010, 18:57
 */

#include "DemoSystemManager.h"

DemoSystemManager::DemoSystemManager() {
}

DemoSystemManager::~DemoSystemManager() {
}

bool DemoSystemManager::initSystem() {
    GraphicEngineConf geConf;
    geConf.width = 1024;
    geConf.height = 768;
    geConf.wmCaption = "Particle Demo";
    setVideoMode(geConf);

    setGameLoop(&gameLoop);

    return true;
}
