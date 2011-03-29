/* 
 * File:   HandlerRegistration.cpp
 * Author: fran
 * 
 * Created on 23 de noviembre de 2010, 17:59
 */

#include "HandlerRegistration.h"
#include "EventEngine.h"

using namespace WasabiEngine;

HandlerRegistration::HandlerRegistration(EventHandler* handler, const bool& isKidnapper) {
    this->handler = handler;
    this->kidnapper = isKidnapper;
}

bool HandlerRegistration::removeHandler() {
    return EventEngine::getInstance()->removeHandler(this);
}
