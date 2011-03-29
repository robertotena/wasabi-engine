/* 
 * File:   QuitEventHandler.h
 * Author: Fran_2
 *
 * Created on 5 de enero de 2011, 18:32
 */

#ifndef QUITEVENTHANDLER_H
#define	QUITEVENTHANDLER_H

#include <SDL/SDL.h>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/EventEngine/Event.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventHandler.h>
#include <WasabiEngine/EventEngine/EventFactory.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>

namespace WasabiEngine {

    /**
     * Base class to handle the quit events sended by the OS.
     */
    class QuitEventHandler : public EventHandler {
    protected:
        static const char EventName[];
        static void peep();
    public:
        QuitEventHandler();
        virtual void handle(const Event* event) = 0;
        virtual EventPeeper getEventPeeper() const;
    };

    inline EventPeeper QuitEventHandler::getEventPeeper() const{
        static EventPeeper peeper(&peep, EVENT_PEEPER_SYSTEM);
        return peeper;
    }
}

#endif	/* QUITEVENTHANDLER_H */

