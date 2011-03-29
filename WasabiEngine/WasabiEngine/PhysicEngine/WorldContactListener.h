/* 
 * File:   WorldContactListener.h
 * Author: Roberto
 *
 * Created on 12 de febrero de 2011, 17:26
 */

#ifndef WORLDCONTACTLISTENER_H
#define	WORLDCONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <WasabiEngine/PhysicEngine/PhysicObject.h>

namespace WasabiEngine {

    /**
     * Internal class to handle contacts in Box2d and call physic objects
     * contact listeners.
     */
    class WorldContactListener : public b2ContactListener {
    public:
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        void PostSolve(b2Contact* contact, const b2ContactImpulse * impulse);
    };
}

#endif	/* WORLDCONTACTLISTENER_H */
