/* 
 * File:   ActorControlHandler.h
 * Author: Fran_2
 *
 * Created on 21 de marzo de 2011, 14:23
 */

#ifndef ACTORCONTROLHANDLER_H
#define	ACTORCONTROLHANDLER_H

#include <WasabiEngine/WasabiEngine.h>

using namespace WasabiEngine;

class ActorControlHandler : public KeyboardEventHandler {
private:
    Actor* actor;
public:
    ActorControlHandler(Actor* actor);
    ActorControlHandler(const ActorControlHandler& orig);
    virtual ~ActorControlHandler();
    void handle(const Event* event);
};

#endif	/* ACTORCONTROLHANDLER_H */

