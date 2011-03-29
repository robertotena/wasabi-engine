/* 
 * File:   QuitHandler.cpp
 * Author: Fran_2
 * 
 * Created on 3 de diciembre de 2010, 19:09
 */

#include "QuitHandler.h"
#include <WasabiEngine/GameEngine/GameLoop.h>

using namespace WasabiEngine;

QuitHandler::QuitHandler(GameLoop* gameLoop){
    this->gameLoop = gameLoop;
}

void QuitHandler::handle(const Event* event) {
    if(event->getEventType() == EventName)
        gameLoop->setGameDone(true);
}

QuitHandler::~QuitHandler() {
    gameLoop = NULL;
}

