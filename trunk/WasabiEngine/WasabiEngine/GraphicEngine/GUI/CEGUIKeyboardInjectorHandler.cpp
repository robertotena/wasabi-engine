/* 
 * File:   CEGUIKeyboardInjectorHandler.cpp
 * Author: Fran_2
 * 
 * Created on 20 de abril de 2011, 13:35
 */

#include "CEGUIKeyboardInjectorHandler.h"

using namespace WasabiEngine;

void CEGUIKeyboardInjectorHandler::handle(const Event* event) {
    CEGUI::System::getSingleton().injectKeyDown(event->getIntegerProperty("scancode"));
    if (event->hasProperty("char")) {
        CEGUI::System::getSingleton().injectChar((char)event->getIntegerProperty("char"));
    }
}
