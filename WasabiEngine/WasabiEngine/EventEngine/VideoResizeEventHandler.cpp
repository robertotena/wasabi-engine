/* 
 * File:   VideoResizeEventHandler.cpp
 * Author: Fran_2
 * 
 * Created on 23 de abril de 2011, 16:37
 */

#include "VideoResizeEventHandler.h"

using namespace WasabiEngine;

const char VideoResizeEventHandler::EventName[] = "VideoResizeEvent";

VideoResizeEventHandler::VideoResizeEventHandler() : EventHandler(GameObject::INVALID_ID, EventName) {
}

int VideoResizeEventHandler::getNewWidth(const Event* event){
    return event->getIntegerProperty("width");
}

int VideoResizeEventHandler::getNewHeight(const Event* event){
    return event->getIntegerProperty("height");
}

/* This event is added to the system from here and form RenderSystem::SetVideoMode */
void VideoResizeEventHandler::peep() {
    SDL_Event sdlEvent;
    SDL_PumpEventsWrapper::pump(SDL_VIDEORESIZEMASK);
    int elements = SDL_PeepEvents(&sdlEvent, 1, SDL_GETEVENT, SDL_VIDEORESIZEMASK);
    if (elements) {
        Event* event = EventFactory::getInstance()->create(EventName);
        event->addProperty("height", sdlEvent.resize.h);
        event->addProperty("width", sdlEvent.resize.w);
        event->setSystemEvent(true);
        EventEngine::getInstance()->broadcastEvent(event);
    }
}
