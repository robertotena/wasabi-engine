/* 
 * File:   SensorHandler.h
 * Author: Fran_2
 *
 * Created on 8 de enero de 2011, 19:48
 */

#ifndef SENSORHANDLER_H
#define	SENSORHANDLER_H

namespace WasabiEngine {
    class SensorHandler {
    public:
        virtual void handle(int monitoredObjectId) = 0;
    };
}

#endif	/* SENSORHANDLER_H */

