/* 
 * File:   MouseButtonEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 24 de abril de 2011, 16:41
 */

#include "MouseButtonEventHandler.h"

using namespace WasabiEngine;

const char MouseButtonEventHandler::EventName[] = "MouseButtonEvent";

MouseButtonEventHandler::MouseButtonEventHandler() : EventHandler(GameObject::INVALID_ID, EventName) {
}

MouseButtonType MouseButtonEventHandler::getButtonType(const Event* event) const {
    return (MouseButtonType) event->getIntegerProperty("button");
}

MouseButtonState MouseButtonEventHandler::getButtonState(const Event* event) const {
    return (MouseButtonState) event->getIntegerProperty("state");
}

void MouseButtonEventHandler::peep() {
    SDL_Event sdlEvent[4];
    SDL_PumpEventsWrapper::pump(SDL_MOUSEBUTTONDOWNMASK | SDL_MOUSEBUTTONUPMASK);
    int elements = SDL_PeepEvents(sdlEvent, 4, SDL_GETEVENT, SDL_MOUSEBUTTONDOWNMASK | SDL_MOUSEBUTTONUPMASK);
    for (int i = 0; i < elements; i++) {
        Event* event = EventFactory::getInstance()->create(EventName);
        event->addProperty("button", sdlEvent[i].button.button);
        event->addProperty("state", sdlEvent[i].button.type);
        event->setSystemEvent(true);
        EventEngine::getInstance()->broadcastEvent(event);
    }
}
