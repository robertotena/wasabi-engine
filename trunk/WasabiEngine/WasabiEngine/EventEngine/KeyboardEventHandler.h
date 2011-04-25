/* 
 * File:   KeyboardEventHandler.h
 * Author: Fran_2
 *
 * Created on 5 de enero de 2011, 18:04
 */

#ifndef KEYBOARDEVENTHANDLER_H
#define	KEYBOARDEVENTHANDLER_H

#include <SDL/SDL.h>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/EventEngine/Event.h>
#include <WasabiEngine/EventEngine/KeyType.h>
#include <WasabiEngine/EventEngine/KeyState.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventHandler.h>
#include <WasabiEngine/EventEngine/EventFactory.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>

namespace WasabiEngine {

    /**
     * Base class to manage keyboard events. It has 2 properties,
     * "key" that represents the activated key and "state", that
     * represents the key state like, pressed or relased.
     */
    class KeyboardEventHandler : public EventHandler {
    protected:
        static const char EventName[];
        static void peep();
    public:
        KeyboardEventHandler();
        virtual void handle(const Event* event) = 0;
        KeyType getKeyType(const Event* event) const;
        KeyState getKeyState(const Event* event) const;
        virtual EventPeeper getEventPeeper() const;
    };

    inline EventPeeper KeyboardEventHandler::getEventPeeper() const{
        static EventPeeper peeper(&peep, EVENT_PEEPER_SYSTEM);
        return peeper;
    }
}

#endif	/* KEYBOARDEVENTHANDLER_H */

