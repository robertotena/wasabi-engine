/* 
 * File:   GameLoop.h
 * Author: Fran_2
 *
 * Created on 1 de noviembre de 2010, 12:11
 */

#ifndef GAMELOOP_H
#define	GAMELOOP_H

#include <cstdlib>
#include <WasabiEngine/GameEngine/GameSystemManager.h>
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/Utils/WasabiTime.h>
#include <WasabiEngine/Utils/MathUtil.h>

namespace WasabiEngine {

    class GameSystemManager;

    class GameLoop {
    protected:
        GameSystemManager* gameSystemManager;
        unsigned int tickTime;
        int maxLoops;
        bool networkGame;
        bool gameDone;
    public:
        GameLoop();
        ~GameLoop();

        bool isGameDone() const;
        void setGameDone(const bool &isGameDone);
        bool isNetworkGame() const;
        void setNetworkGame(const bool &isNetworkGame);
        int getTickTime();
        void setTickTime(const unsigned int &tickTime);
        int getMaxLoops() const;
        void setMaxLoops(const int &maxLoops);
        GameSystemManager* getGameSystemManager();
        void updateSystemEvents();
        void updateUserEvents();

        void run();
        virtual void gameTick();
        virtual void independentTick(int frameTime);
        virtual void renderTick(float percentWithinTick);

        friend class GameSystemManager;
    };

    inline bool GameLoop::isGameDone() const {
        return gameDone;
    }

    inline void GameLoop::setGameDone(const bool &isGameDone) {
        gameDone = isGameDone;
    }

    inline bool GameLoop::isNetworkGame() const {
        return networkGame;
    }

    inline void GameLoop::setNetworkGame(const bool &isNetworkGame) {
        networkGame = isNetworkGame;
    }

    inline int GameLoop::getTickTime() {
        return tickTime;
    }

    inline void GameLoop::setTickTime(const unsigned int &tickTime) {
        this->tickTime = tickTime;
    }

    inline int GameLoop::getMaxLoops() const {
        return maxLoops;
    }

    inline void GameLoop::setMaxLoops(const int &maxLoops) {
        this->maxLoops = maxLoops;
    }

    inline GameSystemManager* GameLoop::getGameSystemManager() {
        return gameSystemManager;
    }

    inline void GameLoop::updateSystemEvents() {
        EventEngine::getInstance()->updateSystemEvents();
    }

    inline void GameLoop::updateUserEvents() {
        EventEngine::getInstance()->updateUserEvents();
    }

    inline void GameLoop::gameTick(){
        gameSystemManager->getGameWorld()->update();
    }

    inline void GameLoop::independentTick(int frameTime){
    }

    inline void GameLoop::renderTick(float percentWithinTick){
        GraphicEngine::getInstance()->render();
    }
}

#endif	/* GAMELOOP_H */
