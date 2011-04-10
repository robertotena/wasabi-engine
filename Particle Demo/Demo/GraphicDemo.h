/* 
 * File:   GraphicDemo.h
 * Author: Fran_2
 *
 * Created on 21 de marzo de 2011, 11:36
 */

#ifndef GRAPHICDEMO_H
#define	GRAPHICDEMO_H

#include <WasabiEngine/WasabiEngine.h>
#include <Demo/SimpleActor.h>
#include <Demo/SimpleCamera.h>

using namespace WasabiEngine;

class GraphicDemo {
private:
    GameWorld3D* world;
    SimpleActor* actor;
    SimpleCamera* camera;
public:
    GraphicDemo();
    virtual ~GraphicDemo();
};

#endif	/* GRAPHICDEMO_H */

