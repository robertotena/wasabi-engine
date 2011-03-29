/* 
 * File:   EventPeeper.h
 * Author: fran
 *
 * Created on 23 de noviembre de 2010, 17:44
 */

#ifndef EVENTPEEPER_H
#define	EVENTPEEPER_H

namespace WasabiEngine {
    /**
     * Functoid to evaluate any event source and pump those events.
     */
    typedef void (*EventPeeperFunction)();

    enum EventPeeperType{
        EVENT_PEEPER_NULL,
        EVENT_PEEPER_SYSTEM,
        EVENT_PEEPER_USER
    };

    /**
     * An event peeper stores an EventPeeperFunction and the EventPeeperType of the function.
     */
    struct EventPeeper{
        EventPeeperFunction function;
        EventPeeperType type;
        EventPeeper(){
            function = 0;
            type = EVENT_PEEPER_NULL;
        }

        EventPeeper(EventPeeperFunction f, EventPeeperType t){
            function = f;
            type = t;
        }

        bool isNull(){
            return type == EVENT_PEEPER_NULL;
        }
        
        bool operator==(const EventPeeper& eventPeeper){
            return function == eventPeeper.function;
        }
    };
}

#endif	/* EVENTPEEPER_H */
