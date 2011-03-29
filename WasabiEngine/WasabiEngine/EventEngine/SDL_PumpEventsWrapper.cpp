/* 
 * File:   SDL_PumpEventsWrapper.cpp
 * Author: Franco Gotusso <gotusso@gmail.com>
 * 
 * Created on 19 de diciembre de 2010, 12:45
 */

#include "SDL_PumpEventsWrapper.h"

using namespace WasabiEngine;

Uint32 SDL_PumpEventsWrapper::discardMask = SDL_ALLEVENTS;

void SDL_PumpEventsWrapper::pump(Uint32 mask){
    discardMask = discardMask & ~mask;
    SDL_PumpEvents();
    //Clean up undesired events
    SDL_Event sdlEvents[128];
    int elements;
    do {
        elements = SDL_PeepEvents(sdlEvents, 128, SDL_GETEVENT, discardMask);
    } while (elements > 0);
}