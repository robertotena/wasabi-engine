/* 
 * File:   Quaternion.cpp
 * Author: Fran_2
 * 
 * Created on 23 de febrero de 2011, 12:04
 */

#include "Quaternion.h"

using namespace WasabiEngine;

Quaternion::Quaternion() {
    w = 1;
    x = 0;
    y = 0;
    z = 0;
}

Quaternion::Quaternion(const float& w, const float& x, const float& y, const float& z) {
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

Quaternion::Quaternion(const Radian& angle, const WasVec3d& axis) {
    Radian halfAngle(angle * 0.5f);
    float s = sin(halfAngle.valueRadians());
    w = cos(halfAngle.valueRadians());
    x = s * axis.x;
    y = s * axis.y;
    z = s * axis.z;
}

//Ogre implementation
Quaternion Quaternion::inverse() const {
    float fNorm = w * w + x * x + y * y + z*z;
    if (fNorm > 0.0) {
        float fInvNorm = 1.0f / fNorm;
        return Quaternion(w*fInvNorm, -x*fInvNorm, -y*fInvNorm, -z * fInvNorm);
    } else {
        // return an invalid result to flag the error
        return Quaternion(0, 0, 0, 0);
    }
}

void Quaternion::toAngleAxis(Radian& angle, WasVec3d& axis) const {
    float scale = sqrt(x * x + y * y + z * z);
    if (scale > 0.0) {
        angle = 2.0 * acos(w);
        axis.x = x / scale;
        axis.y = y / scale;
        axis.z = z / scale;
    } else {
        angle = 0.0;
        axis.x = 0.0;
        axis.y = 0.0;
        axis.z = 0.0;
    }
}

//Ogre implementation
Quaternion Quaternion::operator*(const Quaternion& q) const {
    // Is not commutative!
    return Quaternion(
            w * q.w - x * q.x - y * q.y - z * q.z,
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y + y * q.w + z * q.x - x * q.z,
            w * q.z + z * q.w + x * q.y - y * q.x);
}

//Ogre implementation
WasVec3d Quaternion::operator*(const WasVec3d& v) const {
    // nVidia SDK implementation
    WasVec3d uv, uuv;
    WasVec3d qvec(x, y, z);
    uv = qvec.crossProduct(v);
    uuv = qvec.crossProduct(uv);
    uv = uv * (2.0f * w);
    uuv = uuv * 2.0f;

    return v + uv + uuv;
}
