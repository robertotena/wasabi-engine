/* 
 * File:   Vectors.h
 * Author: Roberto
 *
 * Created on 8 de enero de 2011, 12:43
 */

#ifndef VECTORS_H
#define	VECTORS_H

#include <math.h>
#include <Box2D/Box2D.h>

namespace WasabiEngine {

    /**
     * 3 Component vector.
     */
    class WasVec3d {
    public:
        static const WasVec3d ZERO;
        static const WasVec3d X_UNIT;
        static const WasVec3d Y_UNIT;
        static const WasVec3d Z_UNIT;

        float x;
        float y;
        float z;

        WasVec3d();
        WasVec3d(const float& x, const float& y, const float& z);
        WasVec3d(const WasVec3d p1, const WasVec3d p2);
        WasVec3d(const WasVec3d& orig);
        float module() const;
        void normalize();
        /**
         * Pointer accessor to a float array [x,y,z]
         */
        float* ptr(); //Jugando al limite, como rober xD
        float distance(const WasVec3d& v) const;
        WasVec3d crossProduct(const WasVec3d& v) const;
        WasVec3d operator+(const WasVec3d& vector) const;
        WasVec3d operator-(const WasVec3d& vector) const;
        WasVec3d operator*(const float& scalar) const;
        WasVec3d operator/(const float& scalar) const;
        WasVec3d& operator=(const WasVec3d& orig);
        WasVec3d& operator+=(const WasVec3d vector);
        WasVec3d& operator-=(const WasVec3d vector);
        WasVec3d& operator*=(const float& scalar);
        WasVec3d& operator/=(const float& scalar);
    };

    /**
     * 2 Component vector.
     */
    class WasVec2d {
    public:
        static const WasVec2d ZERO;
        static const WasVec2d X_UNIT;
        static const WasVec2d Y_UNIT;

        float x;
        float y;

        WasVec2d();
        WasVec2d(const float& x, const float& y);
        WasVec2d(const WasVec2d p1, const WasVec2d p2);
        WasVec2d(const b2Vec2 vector);
        WasVec2d(const WasVec2d& orig);
        float module() const;
        void normalize();
        float distance(const WasVec2d& v) const;
        float crossProduct(const WasVec2d& v) const;

        operator b2Vec2() const {
            return b2Vec2(x, y);
        }
        WasVec2d operator+(const WasVec2d& vector) const;
        WasVec2d operator-(const WasVec2d& vector) const;
        WasVec2d operator*(const float& scalar) const;
        WasVec2d operator/(const float& scalar) const;
        WasVec2d& operator=(const WasVec2d& orig);
        WasVec2d& operator+=(const WasVec2d vector);
        WasVec2d& operator-=(const WasVec2d vector);
        WasVec2d& operator*=(const float& scalar);
        WasVec2d& operator/=(const float& scalar);
    };

}

#endif	/* VECTORS_H */

