/* 
 * File:   SceneryFactory.h
 * Author: Roberto
 *
 * Created on 10 de enero de 2011, 23:33
 */

#ifndef SCENERYFACTORY_H
#define	SCENERYFACTORY_H

#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>
#include <WasabiEngine/GameEngine/Scenery.h>
#include <WasabiEngine/GameEngine/SceneryDefinition.h>

namespace WasabiEngine {

    class SceneryFactory {
    private:
        ResourceFactory<Scenery>* factory;
        SceneryFactory(const SceneryFactory& orig);
    public:
        SceneryFactory();
        SceneryFactory(const unsigned int& nScenerys);
        ~SceneryFactory();
        Scenery* create(const SceneryDefinition& definition);
        void destroy(Scenery* scenery);
        void clear();
    };

}

#endif	/* SCENERYFACTORY_H */

