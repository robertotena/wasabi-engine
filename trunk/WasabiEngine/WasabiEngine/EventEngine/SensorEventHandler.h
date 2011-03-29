/* 
 * File:   SensorEventHandler.h
 * Author: Fran_2
 *
 * Created on 9 de enero de 2011, 20:59
 */

#ifndef SENSOREVENTHANDLER_H
#define	SENSOREVENTHANDLER_H

#include <WasabiEngine/EventEngine/EventEngine.h>

namespace WasabiEngine {

    class Sensor;
    
    class SensorEventHandler : public EventHandler {
    private:
        Sensor* sensor;
    public:
        SensorEventHandler(Sensor* sensor);
        void handle(const Event* event);
    };
}

#endif	/* SENSOREVENTHANDLER_H */

