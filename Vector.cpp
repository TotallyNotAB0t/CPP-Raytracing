//
// Created by pierr on 26-Apr-23.
//

#include "Vector.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Vector& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

Vector &Vector::operator=(const Vector &v) {
    if (this != &v){
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }
    return *this;
}

Vector::Vector(Vector &&v) noexcept {
    v.x = 0;
    v.y = 0;
    v.z = 0;
}

Vector &Vector::operator=(Vector &&v) noexcept {
    if (this != &v){
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        v.x = 0;
        v.y = 0;
        v.z = 0;
    }
    return *this;
}

float Vector::operator[](int val) const {
    switch (val) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        default:
            throw std::out_of_range("Vector index out of range.");
    }
}

float &Vector::operator[](int val) {
    switch (val) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        default:
            throw std::out_of_range("Vector index out of range.");
    }
}

float Vector::norm() const {
    return std::sqrt(this->x * 2 + this->y * 2 + this->z * 2);
}

Vector::~Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector Vector::normalized() const {
    return (*this) / norm();
}

float Vector::dot(const Vector& v) const {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::operator-() const {
    return Vector(-this->x, -this->y, -this->z);
}

Vector Vector::operator+(const Vector &v) const {
    return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::operator-(const Vector &v) const {
    return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector Vector::operator*(float val) const {
    return Vector(this->x*val, this->y * val, this->z * val);
}

Vector Vector::operator/(float val) const {
    return Vector(this->x / val, this->y / val, this->z / val);
}

std::ostream& operator<<(std::ostream &os, const Vector &v) {
    os << "X : " << v.x << ", " << "Y : " << v.y << ", " << "Z : " << v.z << '.' << std::endl;
    return os;
}
