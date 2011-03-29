/* 
 * File:   ContactEventHandler.h
 * Author: Fran_2
 *
 * Created on 12 de marzo de 2011, 19:51
 */

#ifndef CONTACTEVENTHANDLER_H
#define	CONTACTEVENTHANDLER_H

#include <WasabiEngine/EventEngine/EventHandler.h>

namespace WasabiEngine {

    /**
     * Base handler to evaluate collisions between physic objects.
     */
    class ContactEventHandler : public EventHandler {
    public:
        ContactEventHandler(unsigned int objectId);
        virtual void handle(const Event* event) = 0;
        unsigned int getContactedObjectId(const Event* event);
        float getNormalImpulse(const Event* event);
        float getTangentImpulse(const Event* event);
        const char* getEventName() const;

        static const char EVENT_NAME[];
    };
}
#endif	/* CONTACTEVENTHANDLER_H */

