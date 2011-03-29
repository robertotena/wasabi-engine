/* 
 * File:   GameObjectManager.h
 * Author: Roberto
 *
 * Created on 6 de enero de 2011, 2:42
 */

#ifndef GAMEOBJECTMANAGER_H
#define	GAMEOBJECTMANAGER_H

#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/GameEngine/GameObject.h>

namespace WasabiEngine {

    /**
     * Class for manage and get game objects by ID. All GameObject are automatically attached and
     * detached from the manager.
     */
    class GameObjectManager {
    private:
        PropertyMap<GameObject*> objects;

        GameObjectManager() {
        }

        GameObjectManager(const GameObjectManager& orig) {
        }
    public:
        /**
         * Add an object to the manager
         * @param gameObject The object to attach
         */
        void attach(GameObject* gameObject);
        /**
         * Remove an object from the manager
         * @param gameObject The object to remove.
         */
        void detach(GameObject* gameObject);
        /**
         * Obtains a GameObject based on their ID
         * @param id The ID of the desired object
         * @return The object or NULL if it not exists.
         */
        GameObject* getItem(const unsigned int& id);
        static GameObjectManager* getInstance();
    };

    inline void GameObjectManager::attach(GameObject* gameObject) {
        if (gameObject != NULL)
            objects.set(gameObject->getId(), gameObject);
    }

    inline void GameObjectManager::detach(GameObject* gameObject) {
        if (gameObject != NULL)
            objects.remove(gameObject->getId());
    }

    inline GameObject* GameObjectManager::getItem(const unsigned int& id) {
        GameObject** obj = objects.get(id);
        if (obj != NULL)
            return *obj;
        return NULL;
    }

    inline GameObjectManager* GameObjectManager::getInstance() {
        static GameObjectManager instance;
        return &instance;
    }

}

#endif	/* GAMEOBJECTMANAGER_H */

