/* 
 * File:   Scenery.h
 * Author: Roberto
 *
 * Created on 6 de enero de 2011, 2:55
 */

#ifndef SCENERY_H
#define	SCENERY_H

#include <WasabiEngine/GameEngine/GameObject.h>

namespace WasabiEngine {

    /**
     * A scenery object represent any game object without a active behaviour, like
     * a create, or a tree.
     */
    class Scenery : public GameObject {
    public:

        Scenery() {
            setTypeName("Scenery");
        };

        ~Scenery() {
        };

        void clear() {
        };
    };

}

#endif	/* SCENERY_H */

