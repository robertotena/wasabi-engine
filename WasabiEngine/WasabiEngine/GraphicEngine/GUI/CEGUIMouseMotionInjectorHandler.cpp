/* 
 * File:   CEGUIMouseMotionInjectorHandler.cpp
 * Author: Fran_2
 * 
 * Created on 24 de abril de 2011, 16:27
 */

#include "CEGUIMouseMotionInjectorHandler.h"

using namespace WasabiEngine;

void CEGUIMouseMotionInjectorHandler::handle(const Event* event){
    CEGUI::System::getSingleton().injectMousePosition(static_cast<float>(getX(event)),static_cast<float>(getY(event)));
}
