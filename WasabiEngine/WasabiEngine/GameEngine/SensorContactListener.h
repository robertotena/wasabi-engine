/* 
 * File:   SensorContactListener.h
 * Author: Fran_2
 *
 * Created on 9 de enero de 2011, 21:05
 */

#ifndef SENSORCONTACTLISTENER_H
#define	SENSORCONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>

namespace WasabiEngine {

    class Sensor;
    
    class SensorContactListener : public ObjectContactListener {
    private:
        Sensor* sensor;
    public:
        SensorContactListener(Sensor* sensor);
        ~SensorContactListener();
        void beginContact(PhysicObject* contactedObj);
    };
}

#endif	/* SENSORCONTACTLISTENER_H */

