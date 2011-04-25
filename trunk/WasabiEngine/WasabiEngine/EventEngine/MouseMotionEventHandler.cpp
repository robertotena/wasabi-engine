/* 
 * File:   MouseMotionEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 24 de abril de 2011, 16:16
 */

#include "MouseMotionEventHandler.h"

using namespace WasabiEngine;

const char MouseMotionEventHandler::EventName[] = "MouseMotionEvent";

MouseMotionEventHandler::MouseMotionEventHandler() : EventHandler(GameObject::INVALID_ID, EventName) {
}

int MouseMotionEventHandler::getX(const Event* event) const{
    return event->getIntegerProperty("x");
}

int MouseMotionEventHandler::getY(const Event* event) const{
    return event->getIntegerProperty("y");
}

void MouseMotionEventHandler::peep() {
    SDL_Event sdlEvent[32];
    SDL_PumpEventsWrapper::pump(SDL_MOUSEMOTIONMASK);
    int elements = SDL_PeepEvents(sdlEvent, 32, SDL_GETEVENT, SDL_MOUSEMOTIONMASK);
    for (int i = 0; i < elements; i++) {
        Event* event = EventFactory::getInstance()->create(EventName);
        event->addProperty("x", sdlEvent[i].motion.x);
        event->addProperty("y", sdlEvent[i].motion.y);
        event->setSystemEvent(true);
        EventEngine::getInstance()->broadcastEvent(event);
    }
}
