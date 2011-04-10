/* 
 * File:   MovableObject.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:27
 */

#ifndef MOVABLEOBJECT_H
#define	MOVABLEOBJECT_H

#include <string>
#include <GL/gl.h>


namespace WasabiEngine {

    class SceneNode;

    class MovableObject {
    protected:
        SceneNode* parentSceneNode;
    public:
        MovableObject(){parentSceneNode = NULL;}
        virtual ~MovableObject() {parentSceneNode = NULL;}
        virtual void renderObject() = 0;
        SceneNode* getParentSceneNode();
        bool isAttached();
        
        friend class SceneNode;
    };

    inline SceneNode* MovableObject::getParentSceneNode()
    {
        return parentSceneNode;
    }

    inline bool MovableObject::isAttached()
    {
        return parentSceneNode != NULL;
    }
}
#endif	/* MOVABLEOBJECT_H */

