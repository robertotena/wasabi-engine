/* 
 * File:   EventHandler.h
 * Author: fran
 *
 * Created on 24 de noviembre de 2010, 12:42
 */

#ifndef EVENTHANDLER_H
#define	EVENTHANDLER_H

#include <WasabiEngine/EventEngine/Event.h>

namespace WasabiEngine {

    class EventHandler {
    protected:
        int receiver;
        unsigned int port;
    public:
        EventHandler(int receiver, std::string eventType);
        virtual EventPeeper getEventPeeper() const;
        virtual void handle(const Event* event) = 0;
        int getReceiver() const;
        int getPort() const;
    };

    inline EventHandler::EventHandler(int receiver, std::string eventType) {
        this->receiver = receiver;
        port = SuperFastHash(eventType.c_str(), eventType.length());
    }

    inline EventPeeper EventHandler::getEventPeeper() const {
        static EventPeeper peeper;
        return peeper;
    }

    inline int EventHandler::getReceiver() const {
        return receiver;
    }

    inline int EventHandler::getPort() const {
        return port;
    }
}
#endif	/* EVENTHANDLER_H */

