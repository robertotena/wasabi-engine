/* 
 * File:   GameSystemManager.h
 * Author: fran
 *
 * Created on 22 de noviembre de 2010, 16:56
 */

#ifndef GAMESYSTEMMANAGER_H
#define	GAMESYSTEMMANAGER_H

#include <WasabiEngine/GameEngine/GameWorld.h>
#include <WasabiEngine/GameEngine/QuitHandler.h>
#include <WasabiEngine/EventEngine/EventFactory.h>
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>

namespace WasabiEngine {

    class GameLoop;

    /**
     * The main class of the engine and his entry point. You should inherit from this class
     * to init your system and then call to the run() method.
     */
    class GameSystemManager {
    protected:
        GameWorld* gameWorld;
        GameLoop* gameLoop;
        QuitHandler* quitHandler;
        HandlerRegistration* quitHandlerRegistration;
        bool finishSystem();
    public:
        GameSystemManager();
        GameSystemManager(const GameSystemManager& orig);
        virtual ~GameSystemManager();
        void setGameLoop(GameLoop* gameLoop);
        virtual bool initSystem() = 0;
        void setVideoMode(const GraphicEngineConf& conf);
        void setGameWorld(GameWorld* gameWorld);
        GameWorld* getGameWorld();
        void run();
    };

    inline void GameSystemManager::setGameWorld(GameWorld* gameWorld){
        this->gameWorld = gameWorld;
    }

    inline GameWorld* GameSystemManager::getGameWorld(){
        return gameWorld;
    }
}

#endif	/* GAMESYSTEMMANAGER_H */
