/* 
 * File:   Vectors.cpp
 * Author: Roberto
 * 
 * Created on 8 de enero de 2011, 12:43
 */

#include "Vectors.h"
#include "Box2D/Common/b2Math.h"

using namespace WasabiEngine;

// WasVec3d

const WasVec3d WasVec3d::ZERO;
const WasVec3d WasVec3d::X_UNIT(1, 0, 0);
const WasVec3d WasVec3d::Y_UNIT(0, 1, 0);
const WasVec3d WasVec3d::Z_UNIT(0, 0, 1);

WasVec3d::WasVec3d() {
    x = y = z = 0.0;
}

WasVec3d::WasVec3d(const float& x, const float& y, const float& z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

WasVec3d::WasVec3d(const WasVec3d p1, const WasVec3d p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    z = p1.z - p2.z;
}

WasVec3d::WasVec3d(const WasVec3d& orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
}

float WasVec3d::module() const {
    return sqrt(x * x + y * y + z * z);
}

void WasVec3d::normalize() {
    //Use double precision!
    double mod = sqrt(x * x + y * y + z * z);
    if (mod != 0) {
        x /= mod;
        y /= mod;
        z /= mod;
    } else {
        x = 0;
        y = 0;
        z = 0;
    }
}

WasVec3d WasVec3d::crossProduct(const WasVec3d& v) const {
    return WasVec3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float* WasVec3d::ptr(){
    return &x;
}

WasVec3d WasVec3d::operator+(const WasVec3d& vector) const {
    return WasVec3d(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

WasVec3d WasVec3d::operator-(const WasVec3d& vector) const {
    return WasVec3d(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

WasVec3d WasVec3d::operator*(const float& scalar) const {
    return WasVec3d(this->x * scalar, this->y * scalar, this->z * scalar);
}

WasVec3d WasVec3d::operator/(const float& scalar) const {
    return WasVec3d(this->x / scalar, this->y / scalar, this->z / scalar);
}

WasVec3d& WasVec3d::operator=(const WasVec3d& orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
    return *this;
}

WasVec3d& WasVec3d::operator+=(const WasVec3d vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

WasVec3d& WasVec3d::operator-=(const WasVec3d vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

WasVec3d& WasVec3d::operator*=(const float& scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

WasVec3d& WasVec3d::operator/=(const float& scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

// WasVec2d

const WasVec2d WasVec2d::ZERO;
const WasVec2d WasVec2d::X_UNIT(1, 0);
const WasVec2d WasVec2d::Y_UNIT(0, 1);

WasVec2d::WasVec2d() {
    x = y = 0.0;
}

WasVec2d::WasVec2d(const float& x, const float& y) {
    this->x = x;
    this->y = y;
}

WasVec2d::WasVec2d(const WasVec2d p1, const WasVec2d p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
}

WasVec2d::WasVec2d(const b2Vec2 vector) {
    x = vector.x;
    y = vector.y;
}

WasVec2d::WasVec2d(const WasVec2d& orig) {
    x = orig.x;
    y = orig.y;
}

float WasVec2d::module() const {
    return sqrt(x * x + y * y);
}

void WasVec2d::normalize() {
    float mod = module();
    if (mod != 0) {
        x /= mod;
        y /= mod;
    } else {
        x = 0;
        y = 0;
    }
}

float WasVec2d::distance(const WasVec2d& v) const {
    float d1, d2;
    d1 = x - v.x;
    d2 = y - v.y;
    return sqrt(d1 * d1 + d2 * d2);
}

float WasVec2d::crossProduct(const WasVec2d& v) const {
    return x * v.y - y * v.x;
}

WasVec2d WasVec2d::operator+(const WasVec2d& vector) const {
    return WasVec2d(this->x + vector.x, this->y + vector.y);
}

WasVec2d WasVec2d::operator-(const WasVec2d& vector) const {
    return WasVec2d(this->x - vector.x, this->y - vector.y);
}

WasVec2d WasVec2d::operator*(const float& scalar) const {
    return WasVec2d(this->x * scalar, this->y * scalar);
}

WasVec2d WasVec2d::operator/(const float& scalar) const {
    return WasVec2d(this->x / scalar, this->y / scalar);
}

WasVec2d& WasVec2d::operator=(const WasVec2d& orig) {
    x = orig.x;
    y = orig.y;
    return *this;
}

WasVec2d& WasVec2d::operator+=(const WasVec2d vector) {
    x += vector.x;
    y += vector.y;
    return *this;
}

WasVec2d& WasVec2d::operator-=(const WasVec2d vector) {
    x -= vector.x;
    y -= vector.y;
    return *this;
}

WasVec2d& WasVec2d::operator*=(const float& scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

WasVec2d& WasVec2d::operator/=(const float& scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}