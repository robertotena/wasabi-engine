/* 
 * File:   GameWorld.h
 * Author: Fran_2
 *
 * Created on 26 de enero de 2011, 12:18
 */

#ifndef GAMEWORLD_H
#define	GAMEWORLD_H

#include <WasabiEngine/GameEngine/GameObject.h>

namespace WasabiEngine {

    /**
     * Base class for any GameWorld. A GameWorld is reponsible for update the GameObjects
     * and can implement LOD techniques.
     */
    class GameWorld : public GameObject {
    protected:
        GameWorld(const GameWorld& orig);
    public:
        GameWorld() {}
        virtual void attachWorld(GameObject* gameObject) = 0;
        virtual void detachWorld(GameObject* gameObject) = 0;
        virtual void update() = 0;
        virtual void clear() = 0;
    };
}

#endif	/* GAMEWORLD_H */

