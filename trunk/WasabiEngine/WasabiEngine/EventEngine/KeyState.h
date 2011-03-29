/* 
 * File:   KeyState.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 2 de diciembre de 2010, 18:04
 */

#ifndef KEYSTATE_H
#define	KEYSTATE_H

#include <SDL/SDL.h>

namespace WasabiEngine {

    /**
     * The key states returned by KeyboardEvent.
     */
    enum KeyState {
        KEY_PRESSED = SDL_KEYDOWN,
        KEY_RELASED = SDL_KEYUP
    };
}

#endif	/* KEYSTATE_H */

