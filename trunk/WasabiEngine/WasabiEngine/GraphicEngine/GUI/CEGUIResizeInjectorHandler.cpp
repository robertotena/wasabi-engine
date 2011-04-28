/* 
 * File:   CEGUIResizeInjectorHandler.cpp
 * Author: Fran_2
 * 
 * Created on 23 de abril de 2011, 16:48
 */

#include "CEGUIResizeInjectorHandler.h"

using namespace WasabiEngine;

void CEGUIResizeInjectorHandler::handle(const Event* event){
    CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size(getNewWidth(event),getNewHeight(event)));
}

