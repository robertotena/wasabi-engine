/* 
 * File:   GameLoop.cpp
 * Author: Fran_2
 * 
 * Created on 1 de noviembre de 2010, 12:11
 */

#include "GameLoop.h"

//FIXME: De momento dejo los couts para ayudar en la depuracion
#include <iostream>
using namespace std;

using namespace WasabiEngine;

GameLoop::GameLoop() {
    //FIXME: Probar distintas configuraciones de estos valores cuando tengamos mas funcionalidad en el juego
    tickTime = 1000.f / 60.0f; // 60 mHz

    maxLoops = 60;
    gameDone = false;
    pause = false;
    networkGame = false;
}

GameLoop::~GameLoop() {
}

void GameLoop::run() {
    unsigned int time0;
    unsigned int time1;
    unsigned int loopTime = 0;
    int frameTime;
    int numLoops;
    float percentWithinTick;

    time0 = WasabiTime::getTicks();
    while (!gameDone) {
        //cout << "Loop start" << endl;
        loopTime = WasabiTime::getTicks();
        time1 = WasabiTime::getTicks();
        frameTime = 0;
        numLoops = 0;
        if (!pause) {
            while ((time1 - time0) > tickTime && numLoops < maxLoops) {
                //cout << "User events" << endl;
                updateUserEvents();
                //cout << "User ticks" << endl;
                gameTick();
                //cout << "Physics" << endl;
                PhysicEngine::getInstance()->step();
                time0 += tickTime;
                frameTime += tickTime;
                numLoops++;
            }
        }
        //cout << "System events" << endl;
        independentTick(frameTime);
        updateSystemEvents();

        //cout << "Render" << endl;
        if (!networkGame && ((time1 - time0) > tickTime)) {
            time0 = time1 - tickTime;
        }
        percentWithinTick = WasabiMath::min(1.f, float(time1 - time0) / tickTime);
        renderTick(percentWithinTick);
        //cout << "Loop end" << endl;
        //FPS
        loopTime = WasabiTime::getTicks() - loopTime;
        if (loopTime != 0)
            ; //std::cout << "FPS: "<< (1000 / loopTime )<<std::endl;
    }
}

bool GameLoop::isPaused() const{
    return pause;
}

void GameLoop::setPause(bool pause){
    this->pause = pause;
}