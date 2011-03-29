/* 
 * File:   KeyboardEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 5 de enero de 2011, 18:04
 */

#include "KeyboardEventHandler.h"

using namespace WasabiEngine;

const char KeyboardEventHandler::EventName[] = "KeyboardEvent";

KeyboardEventHandler::KeyboardEventHandler() : EventHandler(GameObject::INVALID_ID,EventName) {
}

void KeyboardEventHandler::peep() {
    SDL_Event sdlEvents[8];
    SDL_PumpEventsWrapper::pump(SDL_KEYEVENTMASK);
    int elements = SDL_PeepEvents(sdlEvents, 8, SDL_GETEVENT, SDL_KEYEVENTMASK);
    for (int i = 0; i < elements; i++) {
        Event* event = EventFactory::getInstance()->create(EventName);
        event->addProperty("key", sdlEvents[i].key.keysym.sym);
        event->addProperty("state", sdlEvents[i].key.type);
        EventEngine::getInstance()->broadcastEvent(event);
    }
}