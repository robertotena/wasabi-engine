/* 
 * File:   CEGUIMouseMotionInjectorHandler.h
 * Author: Fran_2
 *
 * Created on 24 de abril de 2011, 16:27
 */

#ifndef CEGUIMOUSEMOTIONINJECTORHANDLER_H
#define	CEGUIMOUSEMOTIONINJECTORHANDLER_H

#include <cegui/CEGUI.h>
#include <WasabiEngine/EventEngine/MouseMotionEventHandler.h>

namespace WasabiEngine {

    class CEGUIMouseMotionInjectorHandler : public MouseMotionEventHandler {
    public:
        void handle(const Event* event);
    };
}
#endif	/* CEGUIMOUSEMOTIONINJECTORHANDLER_H */

