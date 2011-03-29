/*
 * File:   EventFactory.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 10 de diciembre de 2010, 21:08
 */

#include "EventFactory.h"

using namespace WasabiEngine;

const int EventFactory::DEFAULT_POOL_SIZE = 128;

ResourceFactory<Event> EventFactory::factory(DEFAULT_POOL_SIZE);

EventFactory::EventFactory(){
}

Event* EventFactory::create(const std::string& name) {
    Event* event = factory.createResource();
    event->setEventType(name);
    event->setPort(SuperFastHash(name.c_str(),name.length()));
    return event;
}

void EventFactory::destroy(Event* event){
    factory.returnResource(event);
}
