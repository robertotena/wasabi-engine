/* 
 * File:   EventFactory.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 10 de diciembre de 2010, 21:08
 */

#ifndef EVENTFACTORY_H
#define	EVENTFACTORY_H

#include <string>
#include <WasabiEngine/Utils/SuperFastHash.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/EventEngine/Event.h>

namespace WasabiEngine {

    class EventFactory {
    private:
        static const int DEFAULT_POOL_SIZE;
        static ResourceFactory<Event> factory;
        EventFactory();
    public:
        /**
         * Creates an event of the type "name"
         * @param typeName The type of the event
         * @return An empty event of the given type.
         */
        Event* create(const std::string& typeName);
        /**
         * Destroys an event. Be carreful, you are not the owner of
         * the memory, so do not try to delete it manually.
         * @param event
         */
        void destroy(Event* event);
        static EventFactory* getInstance();
    };

    inline EventFactory* EventFactory::getInstance() {
        static EventFactory instance;
        return &instance;
    }
}

#endif	/* EVENTFACTORY_H */
