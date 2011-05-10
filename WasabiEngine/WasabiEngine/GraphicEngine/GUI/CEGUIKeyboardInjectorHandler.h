/* 
 * File:   CEGUIKeyboardInjectorHandler.h
 * Author: Fran_2
 *
 * Created on 20 de abril de 2011, 13:35
 */

#ifndef CEGUIKEYBOARDINJECTORHANDLER_H
#define	CEGUIKEYBOARDINJECTORHANDLER_H

#include <CEGUI/CEGUI.h>
#include <WasabiEngine/EventEngine/KeyboardEventHandler.h>

namespace WasabiEngine {

    class CEGUIKeyboardInjectorHandler : public KeyboardEventHandler {
    public:
        void handle(const Event* event);
    };
}
#endif	/* CEGUIKEYBOARDINJECTORHANDLER_H */

