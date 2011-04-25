/* 
 * File:   MouseButtonEventHandler.h
 * Author: Fran_2
 *
 * Created on 24 de abril de 2011, 16:41
 */

#ifndef MOUSEBUTTONEVENTHANDLER_H
#define	MOUSEBUTTONEVENTHANDLER_H


#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>
#include <WasabiEngine/EventEngine/MouseButtonState.h>
#include <WasabiEngine/EventEngine/MouseButtonType.h>

namespace WasabiEngine {

    class MouseButtonEventHandler : public EventHandler {
    protected:
        static void peep();
    public:
        static const char EventName[];
        MouseButtonEventHandler();
        virtual void handle(const Event* event) = 0;
        MouseButtonType getButtonType(const Event* event) const;
        MouseButtonState getButtonState(const Event* event) const;
        virtual EventPeeper getEventPeeper() const;
    };

    inline EventPeeper MouseButtonEventHandler::getEventPeeper() const {
        static EventPeeper peeper(&peep, EVENT_PEEPER_SYSTEM);
        return peeper;
    }
}
#endif	/* MOUSEBUTTONEVENTHANDLER_H */

