/* 
 * File:   ActorControlHandler.cpp
 * Author: Fran_2
 * 
 * Created on 21 de marzo de 2011, 14:23
 */

#include "ActorControlHandler.h"

ActorControlHandler::ActorControlHandler(Actor* actor) {
    this->actor = actor;
}

ActorControlHandler::ActorControlHandler(const ActorControlHandler& orig) {
}

ActorControlHandler::~ActorControlHandler() {
}

void ActorControlHandler::handle(const Event* event) {
    PhysicObject* object = PhysicEngine::getInstance()->getItem(actor->getId());
    float velocity = 5;

    if (!object)
        return;
    if (event->getIntegerProperty("state") == KEY_PRESSED) {
        switch (event->getIntegerProperty("key")) {
            case KEY_LEFT:
                object->setLinearVelocity(WasVec2d(-velocity,0));
                break;
            case KEY_RIGHT:
                object->setLinearVelocity(WasVec2d(velocity,0));
                break;
            case KEY_UP:
                object->setLinearVelocity(WasVec2d(0,velocity));
                break;
            case KEY_DOWN:
                object->setLinearVelocity(WasVec2d(0,-velocity));
            default:
                break;
        }
    } else /* KEY_RELASED */ {
        object->setLinearVelocity(WasVec2d(0,0));
    }
}