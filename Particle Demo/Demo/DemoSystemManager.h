/* 
 * File:   SystemManager.h
 * Author: Fran_2
 *
 * Created on 3 de diciembre de 2010, 18:57
 */

#ifndef SYSTEMMANAGER_H
#define	SYSTEMMANAGER_H

#include <WasabiEngine/WasabiEngine.h>
#include <Demo/GraphicDemo.h>

using namespace WasabiEngine;

class DemoSystemManager : public GameSystemManager {
private:
    GameLoop gameLoop;
    GraphicDemo demo;
    DemoSystemManager();
public:
    ~DemoSystemManager();
    bool initSystem();
    static DemoSystemManager* getInstance();
};

inline DemoSystemManager* DemoSystemManager::getInstance() {
    static DemoSystemManager instance;
    return &instance;
}

#endif	/* SYSTEMMANAGER_H */
