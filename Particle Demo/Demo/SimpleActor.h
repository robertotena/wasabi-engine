/* 
 * File:   SimpleActor.h
 * Author: Fran_2
 *
 * Created on 21 de marzo de 2011, 11:38
 */

#ifndef SIMPLEACTOR_H
#define	SIMPLEACTOR_H

#include <WasabiEngine/WasabiEngine.h>
#include <Demo/ActorControlHandler.h>

using namespace WasabiEngine;

class SimpleActor : public Actor {
private:
    PhysicObject* physicObject;
    GraphicObject* rootGraphicObject;
    ActorControlHandler controlHandler;
    HandlerRegistration* controlHR;
public:
    SimpleActor();
    virtual ~SimpleActor();
    void update();
};

#endif	/* SIMPLEACTOR_H */
