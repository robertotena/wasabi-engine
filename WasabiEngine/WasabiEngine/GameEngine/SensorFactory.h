/* 
 * File:   SensorFactory.h
 * Author: Fran_2
 *
 * Created on 8 de enero de 2011, 20:58
 */

#ifndef SENSORFACTORY_H
#define	SENSORFACTORY_H

#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/GameEngine/Sensor.h>
#include <WasabiEngine/GameEngine/GameObjectManager.h>

namespace WasabiEngine {

    class SensorFactory {
    private:
        ResourceFactory<Sensor> factory;
        SensorFactory();
        SensorFactory(const SensorFactory& factory);
    public:
        virtual ~SensorFactory();
        Sensor* create(const WasVec2d& position, const float& radius);
        void destroy(Sensor* sensor);
        static SensorFactory* getInstance();
    };

    inline SensorFactory* SensorFactory::getInstance() {
        static SensorFactory instance;
        return &instance;
    }
}
#endif	/* SENSORFACTORY_H */

