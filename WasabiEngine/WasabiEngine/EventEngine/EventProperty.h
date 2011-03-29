/* 
 * File:   EventProperty.h
 * Author: Fran_2
 *
 * Created on 4 de enero de 2011, 13:48
 */

#ifndef EVENTPROPERTY_H
#define	EVENTPROPERTY_H

#include <string>

namespace WasabiEngine {

    enum EventPropertyType {
        EVENT_PROPERTY_INTEGER,
        EVENT_PROPERTY_FLOAT,
        EVENT_PROPERTY_BOOL,
        EVENT_PROPERTY_HASHED_STRING
    };
    
    union EventPropertyValue {
        int integer_value;
        float float_value;
        bool bool_value;
        unsigned int hashed_value;
    };
    
    struct EventProperty {
        /* FIXME:Name se podria guardar como un valor hasheado para agilizar la
         * comparacion pero dificultaria la depuracion, asi que hasta que el sistema
         * este mas probado lo dejo asi */
        std::string name;
        EventPropertyType type;
        EventPropertyValue value;
    };
}
#endif	/* EVENTPROPERTY_H */

