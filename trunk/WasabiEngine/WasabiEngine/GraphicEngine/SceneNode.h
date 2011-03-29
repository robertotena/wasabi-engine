/* 
 * File:   SceneNode.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:10
 */

#ifndef SCENENODE_H
#define	SCENENODE_H

#include <list>
#include <GL/gl.h>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/Utils/MathUtil.h>
#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <WasabiEngine/GraphicEngine/Quaternion.h>

namespace WasabiEngine {

    /**
     * Scene tree node. All transformations are relative to his parent.
     */
    class SceneNode {
    private:
        float translation[3];
        float scaleF[3];
        Quaternion rotation;
        bool visible;
        std::list<SceneNode*> children;
        std::list<MovableObject*> objects;
        SceneNode* parent;
        SceneNode();
    public:
        SceneNode(const SceneNode& orig);
        virtual ~SceneNode();
        std::list<SceneNode*> getChildren() const;
        bool hasChildren() const;
        void translate(const WasVec3d& vector);
        void setPosition(const WasVec3d& position);
        WasVec3d getPosition() const;
        void scale(const WasVec3d& vector);
        void pitch(const Radian& angle);
        void yaw(const Radian& angle);
        void roll(const Radian& angle);
        void rotate(const WasVec3d& axis, const Radian& angle);
        const Quaternion& getOrientation() const;
        void setOrientation(const Quaternion& q);
        SceneNode* createChild(const WasVec3d& translation = WasVec3d::ZERO);
        void removeChild(SceneNode* node);
        void removeAllChildren();
        SceneNode* getParentSceneNode();
        void showBoundingBox(bool show);
        void setVisible(bool visible);
        bool isVisible() const;
        void attachObject(MovableObject* object);
        void detachObject(MovableObject* object);
        void renderNode();

        friend class RenderSystem;
        friend class SceneManager;
    };
}
#endif	/* SCENENODE_H */

