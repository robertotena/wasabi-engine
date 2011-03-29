/* 
 * File:   Time.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 12 de diciembre de 2010, 14:31
 */

#ifndef WASABITIME_H
#define	WASABITIME_H

#include <SDL/SDL.h>

namespace WasabiEngine {

    /**
     * Timing functions.
     */
    class WasabiTime {
    public:
        /**
         * Gets the number of milliseconds elapsed since engine initialization.
         * @return Time in milliseconds.
         */
        static Uint32 getTicks() {
            return SDL_GetTicks();
        }
    };
}
#endif	/* WASABITIME_H */

