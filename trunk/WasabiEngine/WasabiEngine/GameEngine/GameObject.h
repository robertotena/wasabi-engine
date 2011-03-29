/* 
 * File:   GameObject.h
 * Author: Roberto
 *
 * Created on 6 de enero de 2011, 2:37
 */

#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <string>
#include <sstream>
#include <WasabiEngine/Utils/SuperFastHash.h>

namespace WasabiEngine {

    /**
     * A game object is the base class for any element in the game. Every game
     * object has a numeric and unique ID, that is generated in an automated way.
     * Also it can has a name and a typeName for debug purposes.
     */
    class GameObject {
    private:
        static unsigned int objectsCount;
    protected:
        unsigned int id;
        unsigned int typeHashCode;
        std::string name;
        std::string typeName;
    public:
        static const unsigned int INVALID_ID = 0; //FIXME: Poner al valor que devuelva el hash con la cadena vacia
        static const unsigned int UNDEFINED_TYPE_CODE = 0; //FIXME: Poner al valor que devuelva el hash con la cadena vacia

        GameObject();
        virtual ~GameObject() = 0;
        unsigned int getId() const;
        const std::string& getName() const;
        bool setName(const std::string& name);
        const std::string& getTypeName() const;
        void setTypeName(const std::string& typeName);
        unsigned int getTypeHashCode() const;
    };

    inline unsigned int GameObject::getId() const {
        return id;
    }

    inline const std::string& GameObject::getName() const {
        return name;
    }

    inline const std::string& GameObject::getTypeName() const {
        return typeName;
    }

    inline unsigned int GameObject::getTypeHashCode() const {
        return typeHashCode;
    }
}

#endif	/* GAMEOBJECT_H */

