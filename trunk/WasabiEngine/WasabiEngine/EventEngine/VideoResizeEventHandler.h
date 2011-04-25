/* 
 * File:   VideoResizeEventHandler.h
 * Author: Fran_2
 *
 * Created on 23 de abril de 2011, 16:37
 */

#ifndef VIDEORESIZEEVENTHANDLER_H
#define	VIDEORESIZEEVENTHANDLER_H

#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>

namespace WasabiEngine {

    class VideoResizeEventHandler : public EventHandler {
    protected:
        static void peep();
    public:
        static const char EventName[];
        VideoResizeEventHandler();
        virtual void handle(const Event* event) = 0;
        virtual EventPeeper getEventPeeper() const;
        int getNewWidth(const Event* event);
        int getNewHeight(const Event* event);
    };

    inline EventPeeper VideoResizeEventHandler::getEventPeeper() const {
        static EventPeeper peeper(&peep, EVENT_PEEPER_SYSTEM);
        return peeper;
    }
}
#endif	/* VIDEORESIZEEVENTHANDLER_H */

