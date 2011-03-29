/* 
 * File:   GameWorld3D.h
 * Author: Franco Gotusso <gotusso@gmail.com>
 *
 * Created on 16 de enero de 2011, 20:07
 */

#ifndef GAMEWORLD3D_H
#define	GAMEWORLD3D_H

#include <set>
#include <WasabiEngine/GameEngine/Actor.h>
#include <WasabiEngine/GameEngine/Scenery.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>
#include <WasabiEngine/GameEngine/GameSystemManager.h>

namespace WasabiEngine {

    typedef struct {
        float width;
        float length;
        float frictionCoefficient;
    } GameWorld3DDef;

    /* FIXME: En un futuro molaria que periodicamente haga comprobaciones para meter y sacar
     * objetos los objetos que se tienen que actualizar, haciendo consultas a box2d para determinar los objetos cercanos.
     */

    /**
     * GameWorld3D is reponsible for update the logic of the GameObjects and synchronize the positions between his
     * physics and the graphics objects (If any). 
     */
    class GameWorld3D : public GameWorld {
    private:
        GameWorld3DDef definition;
        GameSystemManager* systemManager;
        std::set<Actor*> actors;
        std::set<Scenery*> scenery;
        PhysicObject* ground;
        PropertyMap<b2Joint*> jointMap;
        GameWorld3D(const GameWorld3D& orig);
        void attachWorld(GameObject* gameObject);
        void detachWorld(GameObject* gameObject);
    public:
        GameWorld3D(const GameWorld3DDef& definition, GameSystemManager* systemManager);
        ~GameWorld3D();
        //De momento, solo es necesario añadir los objetos que necesiten rozamiento con el suelo
        void attach(Actor* actor);
        bool detach(Actor* actor);
        void attach(Scenery* scenery);
        bool detach(Scenery* scenery);
        void clear();
        void update();
        std::set<Actor*>& getActors();
        std::set<Scenery*>& getScenery();
    };
}

#endif	/* GAMEWORLD3D_H */

