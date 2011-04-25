/* 
 * File:   CEGUIMouseButtonInjectorHandler.cpp
 * Author: Fran_2
 * 
 * Created on 24 de abril de 2011, 16:58
 */

#include "CEGUIMouseButtonInjectorHandler.h"

using namespace WasabiEngine;

void CEGUIMouseButtonInjectorHandler::handle(const Event* event) {
    if (getButtonState(event) == MOUSE_BUTTON_DOWN) {
        switch (getButtonType(event)) {
            case MOUSE_BUTTON_LEFT:
                CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::LeftButton);
                break;
            case MOUSE_BUTTON_MIDDLE:
                CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::MiddleButton);
                break;
            case MOUSE_BUTTON_RIGHT:
                CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::RightButton);
                break;
            case MOUSE_BUTTON_WHEELDOWN:
                CEGUI::System::getSingleton().injectMouseWheelChange(-1);
                break;
            case MOUSE_BUTTON_WHEELUP:
                CEGUI::System::getSingleton().injectMouseWheelChange(+1);
                break;
        }
    } else if (getButtonState(event) == MOUSE_BUTTON_UP) {
        switch (getButtonType(event)) {
            case MOUSE_BUTTON_LEFT:
                CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::LeftButton);
                break;
            case MOUSE_BUTTON_MIDDLE:
                CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::MiddleButton);
                break;
            case MOUSE_BUTTON_RIGHT:
                CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::RightButton);
                break;
        }
    }
}

