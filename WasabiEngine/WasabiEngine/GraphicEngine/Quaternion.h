/* 
 * File:   Quaternion.h
 * Author: Fran_2
 *
 * Created on 23 de febrero de 2011, 12:04
 */

#ifndef QUATERNION_H
#define	QUATERNION_H

#include <WasabiEngine/Utils/MathUtil.h>
#include <WasabiEngine/Utils/Vectors.h>

namespace WasabiEngine {

    class Quaternion {
    public:
        float w;
        float x;
        float y;
        float z;
        Quaternion();
        Quaternion(const float& w, const float& x, const float& y, const float& z);
        Quaternion(const Radian& angle, const WasVec3d& axis);
        Quaternion inverse() const;
        void toAngleAxis(Radian& angle, WasVec3d& axis) const;
        Quaternion operator*(const Quaternion& q) const;
        WasVec3d operator*(const WasVec3d& vec) const;
    };
}
#endif	/* QUATERNION_H */

