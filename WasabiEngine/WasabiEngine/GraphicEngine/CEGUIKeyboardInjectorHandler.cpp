/* 
 * File:   CEGUIKeyboardInjectorHandler.cpp
 * Author: Fran_2
 * 
 * Created on 20 de abril de 2011, 13:35
 */

#include "CEGUIKeyboardInjectorHandler.h"

using namespace WasabiEngine;

void CEGUIKeyboardInjectorHandler::handle(const Event* event) {
    CEGUI::System::getSingleton().injectKeyDown(e.key.keysym.scancode);
    if ((e.key.keysym.unicode & 0xFF80) == 0) {
        CEGUI::System::getSingleton().injectChar(e.key.keysym.unicode & 0x7F);
    }
}
