/* 
 * File:   Actor.h
 * Author: Roberto
 *
 * Created on 9 de noviembre de 2010, 18:24
 */

#ifndef ACTOR_H
#define	ACTOR_H

#include <WasabiEngine/GameEngine/GameObject.h>

namespace WasabiEngine {

    /**
     * Base class for game object width an active behaviour, tipically a player
     * or an AI opponent. The update method of the object will be called in any
     * game logic update.
     */
    class Actor : public GameObject{
    public:
        virtual ~Actor(){}
        virtual void update() = 0;
    };
}

#endif	/* ACTOR_H */

