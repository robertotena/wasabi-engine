/* 
 * File:   WorldContactListener.cpp
 * Author: Roberto
 * 
 * Created on 12 de febrero de 2011, 17:26
 */

#include "WorldContactListener.h"

using namespace WasabiEngine;

void WorldContactListener::BeginContact(b2Contact* contact) {

    PhysicObject* physicObjA = (PhysicObject*) contact->GetFixtureA()->GetBody()->GetUserData();
    PhysicObject* physicObjB = (PhysicObject*) contact->GetFixtureB()->GetBody()->GetUserData();

    if (physicObjA->getContactListener() != NULL)
        physicObjA->getContactListener()->beginContact(physicObjB);
    if (physicObjB->getContactListener() != NULL)
        physicObjB->getContactListener()->beginContact(physicObjA);
}

void WorldContactListener::EndContact(b2Contact* contact) {
    PhysicObject* physicObjA = (PhysicObject*) contact->GetFixtureA()->GetBody()->GetUserData();
    PhysicObject* physicObjB = (PhysicObject*) contact->GetFixtureB()->GetBody()->GetUserData();

    if (physicObjA->getContactListener() != NULL)
        physicObjA->getContactListener()->endContact(physicObjB);
    if (physicObjB->getContactListener() != NULL)
        physicObjB->getContactListener()->endContact(physicObjA);
}

void WorldContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse * impulse) {
    PhysicObject* physicObjA = (PhysicObject*) contact->GetFixtureA()->GetBody()->GetUserData();
    PhysicObject* physicObjB = (PhysicObject*) contact->GetFixtureB()->GetBody()->GetUserData();

    //FIXME: De momento ignoro la posicion del contacto. Quiza mas adelante nos interese.
    
    float normalImpulse = 0;
    float tangentImpulse = 0;
    for(int i = 0; i< contact->GetManifold()->pointCount; i++){
        normalImpulse += impulse->normalImpulses[i];
        tangentImpulse += impulse->tangentImpulses[i];
    }

    if (physicObjA->getContactListener() != NULL)
        physicObjA->getContactListener()->postSolve(physicObjB, normalImpulse, tangentImpulse);
    if (physicObjB->getContactListener() != NULL)
        physicObjB->getContactListener()->postSolve(physicObjA, normalImpulse, tangentImpulse);
}