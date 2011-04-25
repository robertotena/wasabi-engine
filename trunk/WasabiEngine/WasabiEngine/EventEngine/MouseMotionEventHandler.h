/* 
 * File:   MouseMotionEventHandler.h
 * Author: Fran_2
 *
 * Created on 24 de abril de 2011, 16:16
 */

#ifndef MOUSEMOTIONEVENTHANDLER_H
#define	MOUSEMOTIONEVENTHANDLER_H

#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>

namespace WasabiEngine {

    class MouseMotionEventHandler : public EventHandler {
    protected:
        static void peep();
    public:
        static const char EventName[];
        MouseMotionEventHandler();
        virtual void handle(const Event* event) = 0;
        int getX(const Event* event) const;
        int getY(const Event* event) const;
        virtual EventPeeper getEventPeeper() const;
    };

    inline EventPeeper MouseMotionEventHandler::getEventPeeper() const {
        static EventPeeper peeper(&peep, EVENT_PEEPER_SYSTEM);
        return peeper;
    }
}
#endif	/* MOUSEMOTIONEVENTHANDLER_H */

