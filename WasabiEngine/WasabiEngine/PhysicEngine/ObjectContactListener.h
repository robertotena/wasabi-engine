/* 
 * File:   ObjectContactListener.h
 * Author: Roberto
 *
 * Created on 12 de febrero de 2011, 17:51
 */

#ifndef OBJECTCONTACTLISTENER_H
#define	OBJECTCONTACTLISTENER_H

#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/ContactEventHandler.h>

namespace WasabiEngine {

    class PhysicObject;
    
    class ObjectContactListener {
    private:
        unsigned int ownerId;
    public:
        ObjectContactListener(unsigned int ownerId);
        
        virtual void beginContact(PhysicObject* contactedObj) {
        }

        virtual void endContact(PhysicObject* contactedObj) {
        }

        virtual void postSolve(PhysicObject* contactedObj, float normalImpulse, float tangentImpulse);
    };

}

#endif	/* OBJECTCONTACTLISTENER_H */
