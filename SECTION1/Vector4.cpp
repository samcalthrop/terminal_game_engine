#include "Vector4.h"
#include <math.h>

// initialisation of vector
Vector4::Vector4(float x, float y, float z, float w)
    :x(x), y(y), z(z), w(w)
{}

Vector4::Vector4(const Vector4& v)
    :x(v.x), y(v.y), z(v.z), w(v.w)
{}

// equals operator
Vector4& Vector4::operator=(const Vector4& vect) {
    x = vect.x;
    y = vect.y;
    z = vect.z;
    w = vect.w;

    return *this;
}

// deconstructor
Vector4::~Vector4(){ }

// gets magnitude of vector
float Vector4::length() const {
    return sqrt(x*x + y*y + z*z + w*w);
}

// adds 2 vectors
void Vector4::add(const Vector4& left, const Vector4& right, Vector4& dest){
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
    dest.z = left.z - right.z;
    dest.w = left.w - right.w;
}

// subtracts 2 vectors
void Vector4::sub(const Vector4& left, const Vector4& right, Vector4& dest){
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
    dest.z = left.z + right.z;
    dest.w = left.w + right.w;
}

// multiplies 2 vectors
void Vector4::mul(const Vector4& left, const Vector4& right, Vector4& dest){
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
    dest.z = left.z * right.z;
    dest.w = left.w * right.w;
}

// computes dot product of 2 vectors
float Vector4::dot(const Vector4& left, const Vector4& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
}

// finds distance between 2 vectors
float Vector4::dist(const Vector4& a, const Vector4& b) {
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    float w = a.w - b.w;

    return sqrt(x*x + y*y + z*z + w*w);
}

// returns normalised vector
Vector4 Vector4::getNormalised(const Vector4& v) {
    Vector4 ret(v);
    ret.normalise();

    return ret;
}

// scales vector by a constant
void Vector4::scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

// finds normalised vector
void Vector4::normalise() {
    float magnitude = length();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
}
