/* 
 * File:   GraphicEngineConf.h
 * Author: Fran_2
 *
 * Created on 23 de febrero de 2011, 17:09
 */

#ifndef GRAPHICENGINECONF_H
#define	GRAPHICENGINECONF_H

namespace WasabiEngine {

    /**
     * Graphic Engine configuration parameters.
     */
    typedef struct {
        /**
         * Screen width in pixels.
         */
        int width;
        /**
         * Screen heigth in pixels.
         */
        int height;
        /**
         * Fullscreen flag
         */
        bool fullscreen;
        /**
         * Window caption
         */
        std::string wmCaption;
    } GraphicEngineConf;

     enum FogMode {
        FOG_EXP = 0,
        FOG_EXP2,
        FOG_LINEAR,
        FOG_NONE
    };

    enum PolygonMode {
        PM_POINTS = 0,
        PM_WIREFRAME,
        PM_SOLID
    };
}

#endif	/* GRAPHICENGINECONF_H */

