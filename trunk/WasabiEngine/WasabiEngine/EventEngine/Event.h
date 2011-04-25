/* 
 * File:   Event.h
 * Author: fran
 *
 * Created on 23 de noviembre de 2010, 17:43
 */

#ifndef EVENT_H
#define	EVENT_H

#include <string>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/Utils/SuperFastHash.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventProperty.h>

namespace WasabiEngine {

    enum EventDispatchType {
        EVENT_UNDEFINED_DISPATCH,
        EVENT_BROADCAST_DISPATCH,
        EVENT_UNICAST_DISPATCH
    };

    /**
     * Each event can send up to 8 data fields to a handler. Also it has associated
     * info like creation timestamp, delay, port, etc.
     */
    class Event {
    private:
        //Dispatch info
        std::string eventType;
        EventDispatchType dispatchType;
        int port;
        int senderId;
        int receiverId;
        unsigned int timestamp;
        int delay; //ms
        bool systemEvent;

        //Properties
        int propertiesCount;
        static const int MAX_EVENT_PROPERTIES = 8;
        EventProperty properties[MAX_EVENT_PROPERTIES];
 public:

        Event();
        void setEventType(const std::string& eventType);
        EventDispatchType getDispatchType() const;
        void setDispatchType(const EventDispatchType& dispatchType);
        int getPort() const;
        void setPort(const int& port);
        void setTimestamp(const unsigned int& timestamp);
        void setDelay(const int& delay);
        void setSystemEvent(const bool& isSystemEvent);
        void clear();
   
        virtual ~Event();
        std::string getEventType() const;
        int getSenderId() const;
        void setSenderId(const int& id);
        int getReceiverId() const; //May be null if the event is a broadcast event
        void setReceiverId(const int& id);
        unsigned int getTimestamp() const;
        int getDelay() const;
        unsigned int getFireTime() const;
        bool isSystemEvent() const;

        bool addProperty(const std::string& name, const int& value);
        bool addProperty(const std::string& name, const float& value);
        bool addProperty(const std::string& name, const bool& value);
        bool addProperty(const std::string& name, const std::string& value);
        int getIntegerProperty(const std::string& name) const;
        float getFloatProperty(const std::string& name) const;
        bool getBooleanProperty(const std::string& name) const;
        unsigned int getHashProperty(const std::string& name) const;
        int getPropertiesCount() const;
        bool hasProperty(const std::string& name) const;
        
        friend class EventEngine;
        friend class ResourceFactory<Event>;
    };

    class EventDispatchComparator {
    public:

        bool operator()(const Event* a, const Event* b) const {
            return a->getFireTime() > b->getFireTime();
        }
    };

    inline void Event::setEventType(const std::string& eventType) {
        this->eventType = eventType;
    }

    inline EventDispatchType Event::getDispatchType() const {
        return dispatchType;
    }

    inline void Event::setDispatchType(const EventDispatchType& dispatchType) {
        this->dispatchType = dispatchType;
    }

    inline int Event::getPort() const {
        return port;
    }

    inline void Event::setPort(const int& port) {
        this->port = port;
    }

    inline void Event::setTimestamp(const unsigned int& timestamp) {
        this->timestamp = timestamp;
    }

    inline void Event::setDelay(const int& delay) {
        this->delay = delay;
    }

    inline void Event::setSystemEvent(const bool& isSystemEvent) {
        this->systemEvent = isSystemEvent;
    }

    inline std::string Event::getEventType() const {
        return eventType;
    }

    inline int Event::getSenderId() const {
        return senderId;
    }

    inline void Event::setSenderId(const int& id) {
        senderId = id;
    }

    inline int Event::getReceiverId() const {
        return receiverId;
    }

    inline void Event::setReceiverId(const int& id) {
        receiverId = id;
    }

    inline unsigned int Event::getTimestamp() const {
        return timestamp;
    }

    inline int Event::getDelay() const {
        return delay;
    }

    inline unsigned int Event::getFireTime() const {
        return timestamp + delay;
    }

    inline int Event::getPropertiesCount() const {
        return propertiesCount;
    }

    inline bool Event::isSystemEvent() const {
        return systemEvent;
    }
}

#endif	/* EVENT_H */
