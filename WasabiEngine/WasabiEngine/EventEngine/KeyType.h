/* 
 * File:   KeyType.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 2 de diciembre de 2010, 18:05
 */

#ifndef KEYTYPE_H
#define	KEYTYPE_H

#include <SDL/SDL.h>

namespace WasabiEngine {

    /**
     * The key types returned by KeyboardEvent.
     */
    enum KeyType {
        KEY_UP = SDLK_UP, //the Up arrow key (navigation keypad)
        KEY_DOWN = SDLK_DOWN, //the Down arrow key (navigation keypad)
        KEY_LEFT = SDLK_LEFT, //the Left arrow key (navigation keypad)
        KEY_RIGHT = SDLK_RIGHT, //the Right arrow key (navigation keypad)

        KEY_RETURN = SDLK_RETURN, //the Enter key (main keyboard)
        KEY_ESC = SDLK_ESCAPE, //the Esc key
        KEY_TAB = SDLK_TAB, //The Tab key
        KEY_CAPSLOCK = SDLK_CAPSLOCK, //the Caps Lock key
        KEY_LSHIFT = SDLK_LSHIFT, //the Left Shift key
        KEY_LCTRL = SDLK_LCTRL, //the Left Control key
        KEY_LALT = SDLK_LALT, //the Left Alt key
        KEY_SPACE = SDLK_SPACE, //the Space Bar key(s)
        KEY_RALT = SDLK_RALT, //the Right Alt key
        KEY_RCTRL = SDLK_RCTRL, //the Right Control key
        KEY_RSHIFT = SDLK_RSHIFT, //the Right Shift key
        KEY_BACKSPACE = SDLK_BACKSPACE, //the Back Space key

        KEY_0 = SDLK_0, //the 0 key
        KEY_1 = SDLK_1, //the 1 key
        KEY_2 = SDLK_2, //the 2 key
        KEY_3 = SDLK_3, //the 3 key
        KEY_4 = SDLK_4, //the 4 key
        KEY_5 = SDLK_5, //the 5 key
        KEY_6 = SDLK_6, //the 6 key
        KEY_7 = SDLK_7, //the 7 key
        KEY_8 = SDLK_8, //the 8 key
        KEY_9 = SDLK_9, //the 9 key
        /*
            KEY_KP_ENTER = SDLK_KP_ENTER, //the Enter key (numeric keypad)
            KEY_KP_1 = SDLK_KP_1, //the 1 key (numeric keypad)
            KEY_KP_2 = SDLK_KP_2, //the 2 key (numeric keypad)
            KEY_KP_3 = SDLK_KP_3, //the 3 key (numeric keypad)
            KEY_KP_4 = SDLK_KP_4, //the 4 key (numeric keypad)
            KEY_KP_5 = SDLK_KP_5, //the 5 key (numeric keypad)
            KEY_KP_6 = SDLK_KP_6, //the 6 key (numeric keypad)
            KEY_KP_7 = SDLK_KP_7, //the 7 key (numeric keypad)
            KEY_KP_8 = SDLK_KP_8, //the 8 key (numeric keypad)
            KEY_KP_9 = SDLK_KP_9, //the 9 key (numeric keypad)
            KEY_KP_0 = SDLK_KP_0, //the 0 key (numeric keypad)
         */
        KEY_A = SDLK_a, //the a key
        KEY_B = SDLK_b, //the b key
        KEY_C = SDLK_c, //the c key
        KEY_D = SDLK_d, //the d key
        KEY_E = SDLK_e, //the e key
        KEY_F = SDLK_f, //the f key
        KEY_G = SDLK_g, //the g key
        KEY_H = SDLK_h, //the h key
        KEY_I = SDLK_i, //the i key
        KEY_J = SDLK_j, //the j key
        KEY_K = SDLK_k, //the k key
        KEY_L = SDLK_l, //the l key
        KEY_M = SDLK_m, //the m key
        KEY_N = SDLK_n, //the n key
        KEY_O = SDLK_o, //the o key
        KEY_P = SDLK_p, //the p key
        KEY_Q = SDLK_q, //the q key
        KEY_R = SDLK_r, //the r key
        KEY_S = SDLK_s, //the s key
        KEY_T = SDLK_t, //the t key
        KEY_U = SDLK_u, //the u key
        KEY_V = SDLK_v, //the v key
        KEY_W = SDLK_w, //the w key
        KEY_X = SDLK_x, //the x key
        KEY_Y = SDLK_y, //the y key
        KEY_Z = SDLK_z //the z key
    };
}

#endif	/* KEYTYPE_H */

