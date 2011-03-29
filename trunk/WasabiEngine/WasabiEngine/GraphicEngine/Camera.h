/* 
 * File:   Camera.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:49
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include <string>
#include <WasabiEngine/GraphicEngine/MovableObject.h>
#include <WasabiEngine/GraphicEngine/GraphicEngineConf.h>
#include <WasabiEngine/GraphicEngine/SceneNode.h>

// FIXME: traer metodos inline del cpp
namespace WasabiEngine {

    class Camera : public MovableObject {
    private:
        std::string name;
        float translation[3];
        float scaleF[3];
        Quaternion rotation;
        PolygonMode polygonMode;
        bool autoTrackingEnabled;
        SceneNode* trackingTarget;
        WasVec3d trackingOffset;
    public:
        Camera();
        Camera(const Camera& orig);
        ~Camera();
        std::string getName();
        void clear();
        void renderObject();
        void setPolygonMode(const PolygonMode& mode);
        void setAutoTracking(const bool& enabled, SceneNode* target=0, const WasVec3d& offset=WasVec3d::ZERO);
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
        WasVec3d getDirection() const;

        friend class SceneManager;
    };
}
#endif	/* CAMERA_H */

