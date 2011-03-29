/* 
 * File:   Sensor.h
 * Author: Fran_2
 *
 * Created on 8 de enero de 2011, 19:38
 */

#ifndef SENSOR_H
#define	SENSOR_H

#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>
#include <WasabiEngine/EventEngine/SensorEventHandler.h>
#include <WasabiEngine/EventEngine/HandlerRegistration.h>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/GameEngine/SensorHandler.h>
#include <WasabiEngine/GameEngine/SensorContactListener.h>

namespace WasabiEngine {

    /**
     * A sensor allows to detect when an individual object pass through a non
     * solid radial zone and then call to a handler.
     */
    class Sensor : public GameObject {
    private:
        SensorContactListener contactListener;
        SensorEventHandler* eventHandler;
        HandlerRegistration* handlerRegistration;
        PropertyMap<SensorHandler*> handlersMap;
        
        Sensor();
        Sensor(const Sensor& sensor);
        void prepare(const WasVec2d& position, const float& radius);
        void clear();
    public:
        virtual ~Sensor();
        void addHandler(int monitoredObjectId, SensorHandler* handler);
        void removeHandler(int monitoredObjectId);

        friend class ResourceFactory<Sensor>;
        friend class SensorEventHandler;
        friend class SensorFactory;
    };
}

#endif	/* SENSOR_H */

