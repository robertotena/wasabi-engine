/* 
 * File:   CEGUIResizeInjectorHandler.h
 * Author: Fran_2
 *
 * Created on 23 de abril de 2011, 16:48
 */

#ifndef CEGUIRESIZEINJECTORHANDLER_H
#define	CEGUIRESIZEINJECTORHANDLER_H

#include <cegui/CEGUI.h>
#include <WasabiEngine/EventEngine/VideoResizeEventHandler.h>

namespace WasabiEngine {

    class CEGUIResizeInjectorHandler : public VideoResizeEventHandler {
    public:
        void handle(const Event* event);
    };
}
#endif	/* CEGUIRESIZEINJECTORHANDLER_H */

