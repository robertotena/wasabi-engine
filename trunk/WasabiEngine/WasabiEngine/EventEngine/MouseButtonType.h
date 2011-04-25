/* 
 * File:   MouseButtonType.h
 * Author: Fran_2
 *
 * Created on 24 de abril de 2011, 16:46
 */

#ifndef MOUSEBUTTONTYPE_H
#define	MOUSEBUTTONTYPE_H

#include <SDL/SDL.h>

namespace WasabiEngine {

    enum MouseButtonType {
        MOUSE_BUTTON_LEFT = SDL_BUTTON_LEFT,
        MOUSE_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
        MOUSE_BUTTON_RIGHT = SDL_BUTTON_RIGHT,
        MOUSE_BUTTON_WHEELDOWN = SDL_BUTTON_WHEELDOWN,
        MOUSE_BUTTON_WHEELUP = SDL_BUTTON_WHEELUP
    };
}

#endif	/* MOUSEBUTTONTYPE_H */

