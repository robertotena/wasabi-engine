/* 
 * File:   EventEngine.h
 * Author: fran
 *
 * Created on 23 de noviembre de 2010, 17:41
 */

#ifndef EVENTENGINE_H
#define	EVENTENGINE_H

#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <WasabiEngine/EventEngine/Event.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventFactory.h>
#include <WasabiEngine/EventEngine/EventHandler.h>
#include <WasabiEngine/EventEngine/HandlerRegistration.h>
#include <WasabiEngine/Utils/WasabiTime.h>

namespace WasabiEngine {

    /**
     * Event engine for send and receive unicast and broadcast events along the game objects.
     */

    /* FIXME Si trabaja con SDL necesita que este cargado previamente el sistema grafico! */
    class EventEngine {
    private:
        typedef std::priority_queue<Event*, std::vector<Event*>, EventDispatchComparator> EventQueue;
        typedef std::set<HandlerRegistration*> RegistrationList;
        typedef std::map<unsigned int, RegistrationList* > ReceiverMap;
        typedef std::map<unsigned int, ReceiverMap*> PortMap;
        typedef std::list<EventPeeper> PeeperList;

        EventQueue systemEventQueue;
        EventQueue userEventQueue;
        PortMap registrationMap;
        PeeperList systemPeepers;
        PeeperList userPeepers;

        EventEngine();
        void fireEvents(EventQueue& queue);
        void peepEvents(PeeperList& peeperList);
        void addEventPeeper(const EventPeeper& eventPeeper);
    public:
        ~EventEngine();
        /**
         * Adds a handler on the system and activates it. You will need the returned
         * handlerRegistration if want deactivate de handler, but do not try to delete
         * the handlerRegistration memory. Use the removeHandler method instead.
         * @param handler The handler to add on the system
         * @param isKidnapper If it's true, the event will not allow to propagate the events of his type to other handlers.
         * @return The handler registration
         */
        HandlerRegistration* addHandler(EventHandler* handler, bool isKidnapper = false);
        /**
         * Deactivates a handler. The associated HandlerRegistration will be invalid after this.
         * @param handlerRegistration The associated registration of a handler.
         * @return true if the remove is successful.
         */
        bool removeHandler(HandlerRegistration* handlerRegistration);
        /**
         * Broadcast an event to any handler of the same type.
         * @param event The event
         * @param delay to fire the event, in milliseconds
         */
        void broadcastEvent(Event* event, int delay = 0);
        /**
         * Send a unicast event to a handler of the same type and receiverId
         * @param event The event
         * @param receiverId The id of the  handler receiver
         * @param delay Delay to fire the event, in milliseconds
         */
        void sendEvent(Event* event, unsigned int receiverId, int delay = 0);
        /**
         * Pumps new events to the queue and fires the current system events.
         */
        void updateSystemEvents();
        /**
         * Pumps new events to the queue and fires the current user events.
         */
        void updateUserEvents();
        static EventEngine* getInstance();

        /**
         * Initializes the engine
         */
        void init();
        /**
         * Clears the engine contents
         */
        void finish();
    };

    inline void EventEngine::updateSystemEvents() {
        fireEvents(systemEventQueue);
        peepEvents(systemPeepers);
    }

    inline void EventEngine::updateUserEvents() {
        fireEvents(userEventQueue);
        peepEvents(userPeepers);
    }

    inline EventEngine* EventEngine::getInstance() {
        static EventEngine instance;
        return &instance;
    }
}

#endif	/* EVENTENGINE_H */
