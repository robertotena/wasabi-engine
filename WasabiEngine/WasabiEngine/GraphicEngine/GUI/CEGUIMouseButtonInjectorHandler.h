/* 
 * File:   CEGUIMouseButtonInjectorHandler.h
 * Author: Fran_2
 *
 * Created on 24 de abril de 2011, 16:58
 */

#ifndef CEGUIMOUSEBUTTONINJECTORHANDLER_H
#define	CEGUIMOUSEBUTTONINJECTORHANDLER_H

#include <CEGUI/CEGUI.h>
#include <WasabiEngine/EventEngine/MouseButtonEventHandler.h>

namespace WasabiEngine {

    class CEGUIMouseButtonInjectorHandler : public MouseButtonEventHandler {
    public:
        void handle(const Event* event);
    };
}

#endif	/* CEGUIMOUSEBUTTONINJECTORHANDLER_H */

