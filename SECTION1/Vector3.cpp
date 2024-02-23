#include "Vector3.h"
#include <math.h>

// initialisation of vector
Vector3::Vector3(float x, float y, float z)
    :x(x), y(y), z(z)
{}

Vector3::Vector3(const Vector3& v)
    :x(v.x), y(v.y), z(v.z)
{}

// equals operator
Vector3& Vector3::operator=(const Vector3& vect) {
    x = vect.x;
    y = vect.y;
    z = vect.z;

    return *this;
}

// deconstructor
Vector3::~Vector3(){ }

// gets magnitude of vector
float Vector3::length() const {
    return sqrt(x*x + y*y + z*z);
}

// adds 2 vectors
void Vector3::add(const Vector3& left, const Vector3& right, Vector3& dest) {
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
    dest.z = left.z - right.z;
}

// subtracts 2 vectors
void Vector3::sub(const Vector3& left, const Vector3& right, Vector3& dest) {
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
    dest.z = left.z + right.z;
}

// multiplies 2 vectors
void Vector3::mul(const Vector3& left, const Vector3& right, Vector3& dest) {
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
    dest.z = left.z * right.z;
}

// linearly interpolate between 2 vectors based on a floating point, t,
// representing a fraction of the distance between the 2 vectors, i.e 
// t=0 -> point is at vec A, t=0.5 -> point is halfway between vec A dn vec B etc.

void Vector3::lerp(const Vector3& a, const Vector3& b, float t, Vector3& dest){
    dest.x = a.x + ((b.x - a.x) * t);
    dest.y = a.y + ((b.y - a.y) * t);
    dest.z = a.z + ((b.z - a.z) * t);
}

// computes cross product of 2 vectors
void Vector3::cross(const Vector3& a, const Vector3& b, Vector3& dest) {
    dest.x = (a.y * b.z) - (a.z * b.y);
    dest.y = (a.z * b.x) - (a.x * b.z);
    dest.z = (a.x * b.y) - (a.y * b.x);
}

// computes dot product of 2 vectors
float Vector3::dot(const Vector3& left, const Vector3& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

// finds angle between 2 vectors
float Vector3::angle(const Vector3& left, const Vector3& right) {
    float dot = Vector3::dot(left, right);

    return acos(dot / (left.length() * right.length()));
}

// finds distance between 2 vectors
float Vector3::dist(const Vector3& a, const Vector3& b) {
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;

    return sqrt(x*x + y*y + z*z);
}

// returns normalised vector
Vector3 Vector3::getNormalised(const Vector3& v) {
    Vector3 ret(v);
    ret.normalise();

    return ret;
}

// scales vector by a constant
void Vector3::scale(float s) {
    x *= s;
    y *= s;
    z *= s;
}

// finds normalised vector
void Vector3::normalise() {
    float magnitude = length();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}
