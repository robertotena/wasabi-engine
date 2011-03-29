/* 
 * File:   HandlerRegistration.h
 * Author: fran
 *
 * Created on 23 de noviembre de 2010, 17:59
 */

#ifndef HANDLERREGISTRATION_H
#define	HANDLERREGISTRATION_H

#include <WasabiEngine/EventEngine/EventHandler.h>
#include <WasabiEngine/EventEngine/Event.h>

namespace WasabiEngine {
    class EventEngine;

    class HandlerRegistration {
    private:
        EventHandler* handler;
        bool kidnapper;
    public:
        HandlerRegistration(EventHandler* handler, const bool& isKidnapper);
        EventHandler* getHandler();
        bool isKidnapper();
        bool removeHandler();
    };

    inline EventHandler* HandlerRegistration::getHandler() {
        return handler;
    }
    inline bool HandlerRegistration::isKidnapper() {
        return kidnapper;
    }
}

#endif	/* HANDLERREGISTRATION_H */
