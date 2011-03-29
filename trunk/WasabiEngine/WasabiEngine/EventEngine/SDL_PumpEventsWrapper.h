/* 
 * File:   SDL_PumpEventsWrapper.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 19 de diciembre de 2010, 12:45
 */

#ifndef SDL_PUMPEVENTSWRAPPER_H
#define	SDL_PUMPEVENTSWRAPPER_H

#include <SDL/SDL.h>

namespace WasabiEngine {

    /**
     * Internal class to deal with SDL events and discard undesired hardware events.
     */
    class SDL_PumpEventsWrapper {
    private:
        static Uint32 discardMask;
    public:
        static void pump(Uint32 mask);
    };
}

#endif	/* SDL_PUMPEVENTSWRAPPER_H */

