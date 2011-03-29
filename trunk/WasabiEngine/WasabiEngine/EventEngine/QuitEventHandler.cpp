/* 
 * File:   QuitEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 5 de enero de 2011, 18:32
 */

#include "QuitEventHandler.h"

using namespace WasabiEngine;

const char QuitEventHandler::EventName[] = "QuitEvent";

QuitEventHandler::QuitEventHandler() : EventHandler(GameObject::INVALID_ID, EventName) {
}

void QuitEventHandler::peep() {
    SDL_Event sdlEvent;
    SDL_PumpEventsWrapper::pump(SDL_QUITMASK);
    int elements = SDL_PeepEvents(&sdlEvent, 1, SDL_GETEVENT, SDL_QUITMASK);
    if (elements) {
        Event* event = EventFactory::getInstance()->create(EventName);
        EventEngine::getInstance()->broadcastEvent(event);
    }
}