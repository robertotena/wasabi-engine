/* 
 * File:   EventEngine.cpp
 * Author: fran
 * 
 * Created on 23 de noviembre de 2010, 17:41
 */

#include "EventEngine.h"

using namespace WasabiEngine;

EventEngine::EventEngine() {
}

EventEngine::~EventEngine() {
}

void EventEngine::init() {
    SDL_EnableUNICODE(1);
}

void EventEngine::finish() {
    //Delete each port
    for (PortMap::iterator portAddress = registrationMap.begin(); portAddress != registrationMap.end(); portAddress++) {
        //Delete each receiver
        ReceiverMap* receiverMap = portAddress->second;
        for (ReceiverMap::iterator receiverAddress = receiverMap->begin(); receiverAddress != receiverMap->end(); receiverAddress++) {
            //Delete each registration
            RegistrationList* registrationList = receiverAddress->second;
            for (RegistrationList::iterator registration = registrationList->begin(); registration != registrationList->end(); registration++)
                delete (*registration);
            delete registrationList;
        }
        delete receiverMap;
    }

    Event* event;
    //Delete queued events
    while (!systemEventQueue.empty()) {
        event = systemEventQueue.top();
        systemEventQueue.pop();
        EventFactory::getInstance()->destroy(event);
    }
    while (!userEventQueue.empty()) {
        event = userEventQueue.top();
        userEventQueue.pop();
        EventFactory::getInstance()->destroy(event);
    }
}

HandlerRegistration* EventEngine::addHandler(EventHandler* handler, bool isKidnapper) {
    //Check if the port exists
    ReceiverMap* portAddress = registrationMap[handler->getPort()];
    if (portAddress == NULL) {
        portAddress = new ReceiverMap();
        registrationMap[handler->getPort()] = portAddress;
    }

    //Check if the receiver exists
    RegistrationList* registrationList = (*portAddress)[handler->getReceiver()];
    if (registrationList == NULL) {
        registrationList = new RegistrationList();
        (*portAddress)[handler->getReceiver()] = registrationList;
    }

    //Create and insert new registration
    HandlerRegistration* registration = new HandlerRegistration(handler, isKidnapper);
    registrationList->insert(registration);

    //Add event peeper
    if (!handler->getEventPeeper().isNull())
        addEventPeeper(handler->getEventPeeper());

    return registration;
}

bool EventEngine::removeHandler(HandlerRegistration* handlerRegistration) {
    bool success = false;
    ReceiverMap* portAddress = registrationMap[handlerRegistration->getHandler()->getPort()];
    if (portAddress != NULL) {
        RegistrationList* receiverAddress = (*portAddress)[handlerRegistration->getHandler()->getReceiver()];
        if (receiverAddress != NULL) {
            if (receiverAddress->erase(handlerRegistration))
                success = true;
            delete handlerRegistration;
        }
    }
    return success;
}

void EventEngine::addEventPeeper(const EventPeeper & eventPeeper) {
    std::list<EventPeeper>::iterator it;
    switch (eventPeeper.type) {
        case EVENT_PEEPER_SYSTEM:
            it = std::find(systemPeepers.begin(), systemPeepers.end(), eventPeeper);
            if (it == systemPeepers.end())
                systemPeepers.push_back(eventPeeper);
            break;
        case EVENT_PEEPER_USER:
            it = std::find(userPeepers.begin(), systemPeepers.end(), eventPeeper);
            if (it == userPeepers.end())
                userPeepers.push_back(eventPeeper);
            break;
        default:
            break;
    }
}

void EventEngine::broadcastEvent(Event* event, int delay) {
    event->setDelay(delay);
    event->setTimestamp(WasabiTime::getTicks());
    event->setDispatchType(EVENT_BROADCAST_DISPATCH);
    if (event->isSystemEvent())
        systemEventQueue.push(event);
    else
        userEventQueue.push(event);
}

void EventEngine::sendEvent(Event* event, unsigned int receiverId, int delay) {
    event->setDelay(delay);
    event->setTimestamp(WasabiTime::getTicks());
    event->setDispatchType(EVENT_UNICAST_DISPATCH);
    event->setReceiverId(receiverId);
    if (event->isSystemEvent())
        systemEventQueue.push(event);
    else
        userEventQueue.push(event);
}

void EventEngine::clearQueuedUserEvents() {
    Event* event;
    //Delete queued events
//    while (!systemEventQueue.empty()) {
//        event = systemEventQueue.top();
//        systemEventQueue.pop();
//        EventFactory::getInstance()->destroy(event);
//    }
    while (!userEventQueue.empty()) {
        event = userEventQueue.top();
        userEventQueue.pop();
        EventFactory::getInstance()->destroy(event);
    }
}

void EventEngine::fireEvents(EventQueue& queue) {
    Event* dispatch;
    unsigned int now = WasabiTime::getTicks();

    while (!queue.empty()) {
        dispatch = queue.top();
        //Are we ready to fire the next event?
        if (dispatch->getFireTime() > now)
            break;

        //We have any registred handler for the event?
        ReceiverMap* portAddress = registrationMap[dispatch->getPort()];
        if (portAddress != NULL) {
            //If we are ready, fire events
            if (dispatch->getDispatchType() == EVENT_BROADCAST_DISPATCH) {
                for (ReceiverMap::iterator receiverAddress = portAddress->begin(); receiverAddress != portAddress->end(); receiverAddress++) {
                    RegistrationList* registrationList = receiverAddress->second;
                    for (RegistrationList::iterator registration = registrationList->begin(); registration != registrationList->end(); registration++) {
                        (*registration)->getHandler()->handle(dispatch);
                        //Stop processing if the current handler is a kidnapper
                        if ((*registration)->isKidnapper())
                            break;
                    }
                }
            } else /* UNICAST */ {
                RegistrationList* registrationList = (*portAddress)[dispatch->getReceiverId()];
                if (registrationList != NULL) {
                    for (RegistrationList::iterator registration = registrationList->begin(); registration != registrationList->end(); registration++)
                        (*registration)->getHandler()->handle(dispatch);
                }
            }
        }
        //Remove event from queue
        queue.pop();
        //Delete the memory allocated by the factory
        EventFactory::getInstance()->destroy(dispatch);
    }
}

void EventEngine::peepEvents(PeeperList& peeperList) {
    PeeperList::iterator it;
    for (it = peeperList.begin(); it != peeperList.end(); it++) {
        (it->function)();
    }
}
