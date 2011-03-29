/* 
 * File:   QuitHandler.h
 * Author: Fran_2
 *
 * Created on 3 de diciembre de 2010, 19:09
 */

#ifndef QUITHANDLER_H
#define	QUITHANDLER_H

#include <WasabiEngine/EventEngine/QuitEventHandler.h>

namespace WasabiEngine {

    class GameLoop;
    
    class QuitHandler : public QuitEventHandler {
    private:
        GameLoop* gameLoop;
    public:
        QuitHandler(GameLoop* gameLoop);
        void handle(const Event* event);
        ~QuitHandler();
    };
}

#endif	/* QUITHANDLER_H */

