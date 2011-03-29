/* 
 * File:   MathUtil.h
 * Author: Roberto
 *
 * Created on 9 de noviembre de 2010, 17:46
 */

#ifndef MATHUTIL_H
#define	MATHUTIL_H

#include <cstdlib>
#include <math.h>

namespace WasabiEngine {

    /**
     * Container for generic math functions.
     */
    class WasabiMath {
    public:
        const static float PI;
        static float max(const float& a, const float& b);
        static float min(const float& a, const float& b);
        static int sign(const float& number);
    };

    class Degree;

    /**
     * Wrapper class to handle radians
     */
    class Radian {
    private:
        float rad;
    public:

        Radian(float r = 0);
        Radian(const Degree& d);
        Radian & operator =(const float& f);
        Radian & operator =(const Radian& r);
        Radian & operator =(const Degree& d);
        float valueDegrees() const;
        float valueRadians() const;
        const Radian & operator +() const;
        Radian operator +(const Radian& r) const;
        Radian operator +(const Degree& d) const;
        Radian & operator +=(const Radian& r);
        Radian & operator +=(const Degree& d);
        Radian operator -() const;
        Radian operator -(const Radian& r) const;
        Radian operator -(const Degree& d) const;
        Radian & operator -=(const Radian& r);
        Radian & operator -=(const Degree& d);
        Radian operator *(float f) const;
        Radian operator *(const Radian& f) const;
        Radian & operator *=(float f);
        Radian operator /(float f) const;
        Radian & operator /=(float f);
        bool operator<(const Radian& r) const;
        bool operator <=(const Radian& r) const;
        bool operator ==(const Radian& r) const;
        bool operator !=(const Radian& r) const;
        bool operator >=(const Radian& r) const;
        bool operator>(const Radian& r) const;
    };

    /**
     * Wrapper class to handle degrees.
     */
    class Degree {
    private:
        float degree;
    public:

        Degree(float d = 0);
        Degree(const Radian& r);
        Degree & operator =(const float& f);
        Degree & operator =(const Degree& d);
        Degree & operator =(const Radian& r);
        float valueDegrees() const;
        float valueRadians() const;
        const Degree & operator +() const;
        Degree operator +(const Degree& d) const;
        Degree operator +(const Radian& r) const;
        Degree & operator +=(const Degree& d);
        Degree & operator +=(const Radian& r);
        Degree operator -() const;
        Degree operator -(const Degree& d) const;
        Degree operator -(const Radian& r) const;
        Degree & operator -=(const Degree& d);
        Degree & operator -=(const Radian& r);
        Degree operator *(float f) const;
        Degree operator *(const Degree& f) const;
        Degree & operator *=(float f);
        Degree operator /(float f) const;
        Degree & operator /=(float f);
        bool operator<(const Degree& d) const;
        bool operator <=(const Degree& d) const;
        bool operator ==(const Degree& d) const;
        bool operator !=(const Degree& d) const;
        bool operator >=(const Degree& d) const;
        bool operator>(const Degree& d) const;
    };

    inline Radian::Radian(float r) {
        rad = r;
    }

    inline Radian::Radian(const Degree& d) : rad(d.valueRadians()) {
    }

    inline Radian & Radian::operator =(const float& f) {
        rad = f;
        return *this;
    }

    inline Radian & Radian::operator =(const Radian& r) {
        rad = r.rad;
        return *this;
    }

    inline Radian& Radian::operator =(const Degree& d) {
        rad = d.valueRadians();
        return *this;
    }

    inline float Radian::valueDegrees() const {
        return rad * 180 / WasabiMath::PI;
    }

    inline float Radian::valueRadians() const {
        return rad;
    }

    inline const Radian & Radian::operator +() const {
        return *this;
    }

    inline Radian Radian::operator +(const Radian& r) const {
        return Radian(rad + r.rad);
    }

    inline Radian Radian::operator +(const Degree& d) const {
        return Radian(rad + d.valueRadians());
    }

    inline Radian & Radian::operator +=(const Radian& r) {
        rad += r.rad;
        return *this;
    }

    inline Radian& Radian::operator +=(const Degree& d) {
        rad += d.valueRadians();
        return *this;
    }

    inline Radian Radian::operator -() const {
        return Radian(-rad);
    }

    inline Radian Radian::operator -(const Radian& r) const {
        return Radian(rad - r.rad);
    }

    inline Radian Radian::operator -(const Degree& d) const {
        return Radian(rad - d.valueRadians());
    }

    inline Radian & Radian::operator -=(const Radian& r) {
        rad -= r.rad;
        return *this;
    }

    inline Radian& Radian::operator -=(const Degree& d) {
        rad -= d.valueRadians();
        return *this;
    }

    inline Radian Radian::operator *(float f) const {
        return Radian(rad * f);
    }

    inline Radian Radian::operator *(const Radian& f) const {
        return Radian(rad * f.rad);
    }

    inline Radian & Radian::operator *=(float f) {
        rad *= f;
        return *this;
    }

    inline Radian Radian::operator /(float f) const {
        return Radian(rad / f);
    }

    inline Radian & Radian::operator /=(float f) {
        rad /= f;
        return *this;
    }

    inline bool Radian::operator<(const Radian& r) const {
        return rad < r.rad;
    }

    inline bool Radian::operator <=(const Radian& r) const {
        return rad <= r.rad;
    }

    inline bool Radian::operator ==(const Radian& r) const {
        return rad == r.rad;
    }

    inline bool Radian::operator !=(const Radian& r) const {
        return rad != r.rad;
    }

    inline bool Radian::operator >=(const Radian& r) const {
        return rad >= r.rad;
    }

    inline bool Radian::operator>(const Radian& r) const {
        return rad > r.rad;
    }

    inline Degree::Degree(float d) {
        degree = d;
    }

    inline Degree::Degree(const Radian& r) : degree(r.valueDegrees()) {
    }

    inline Degree & Degree::operator =(const float& f) {
        degree = f;
        return *this;
    }

    inline Degree & Degree::operator =(const Degree& d) {
        degree = d.degree;
        return *this;
    }

    inline Degree & Degree::operator =(const Radian& r) {
        degree = r.valueDegrees();
        return *this;
    }

    inline float Degree::valueDegrees() const {
        return degree;
    }

    inline float Degree::valueRadians() const {
        return degree * WasabiMath::PI / 180;
    }

    inline const Degree & Degree::operator +() const {
        return *this;
    }

    inline Degree Degree::operator +(const Degree& d) const {
        return Degree(degree + d.degree);
    }

    inline Degree Degree::operator +(const Radian& r) const {
        return Degree(degree + r.valueDegrees());
    }

    inline Degree & Degree::operator +=(const Degree& d) {
        degree += d.degree;
        return *this;
    }

    inline Degree & Degree::operator +=(const Radian& r) {
        degree += r.valueDegrees();
        return *this;
    }

    inline Degree Degree::operator -() const {
        return Degree(-degree);
    }

    inline Degree Degree::operator -(const Degree& d) const {
        return Degree(degree - d.degree);
    }

    inline Degree Degree::operator -(const Radian& r) const {
        return Degree(degree - r.valueDegrees());
    }

    inline Degree & Degree::operator -=(const Degree& d) {
        degree -= d.degree;
        return *this;
    }

    inline Degree & Degree::operator -=(const Radian& r) {
        degree -= r.valueDegrees();
        return *this;
    }

    inline Degree Degree::operator *(float f) const {
        return Degree(degree * f);
    }

    inline Degree Degree::operator *(const Degree& f) const {
        return Degree(degree * f.degree);
    }

    inline Degree & Degree::operator *=(float f) {
        degree *= f;
        return *this;
    }

    inline Degree Degree::operator /(float f) const {
        return Degree(degree / f);
    }

    inline Degree & Degree::operator /=(float f) {
        degree /= f;
        return *this;
    }

    inline bool Degree::operator<(const Degree& d) const {
        return degree < d.degree;
    }

    inline bool Degree::operator <=(const Degree& d) const {
        return degree <= d.degree;
    }

    inline bool Degree::operator ==(const Degree& d) const {
        return degree == d.degree;
    }

    inline bool Degree::operator !=(const Degree& d) const {
        return degree != d.degree;
    }

    inline bool Degree::operator >=(const Degree& d) const {
        return degree >= d.degree;
    }

    inline bool Degree::operator>(const Degree& d) const {
        return degree > d.degree;
    }
}

#endif	/* MATHUTIL_H */
