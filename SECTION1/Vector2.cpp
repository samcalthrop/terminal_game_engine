#include "Vector2.h"
#include <math.h>

// initialisation of vector
Vector2::Vector2(float x, float y)
    :x(x), y(y)
{}

Vector2::Vector2(const Vector2& v)
    :x(v.x), y(v.y)
{}

// equals operator
Vector2& Vector2::operator=(const Vector2& vect) {
    x = vect.x;
    y = vect.y;

    return *this;
}

// deconstructor
Vector2::~Vector2(){ }

// gets magnitude of vector
float Vector2::length() const {
    return sqrt(x*x + y*y);
}

// adds 2 vectors
void Vector2::add(const Vector2& left, const Vector2& right, Vector2& dest){
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
}

// subtracts 2 vectors
void Vector2::sub(const Vector2& left, const Vector2& right, Vector2& dest){
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
}

// multiplies 2 vectors
void Vector2::mul(const Vector2& left, const Vector2& right, Vector2& dest){
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
}

// linearly interpolate between 2 vectors based on a floating point, t,
// representing a fraction of the distance between the 2 vectors, i.e 
// t=0 -> point is at vec A, t=0.5 -> point is halfway between vec A dn vec B etc.

void Vector2::lerp(const Vector2& a, const Vector2& b, float t, Vector2& dest){
    dest.x = a.x + ((b.x - a.x) * t);
    dest.y = a.y + ((b.y - a.y) * t);
}

// incremental operators
Vector2& Vector2::operator+=(const Vector2& right){
    Vector2::add(*this, right, *this);
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& right){
    Vector2::sub(*this, right, *this);
    return *this;
}

// literal operators
Vector2 Vector2::operator+(const Vector2& right) const {
    Vector2 ret;
    Vector2::add(*this, right, ret);
    return ret;
}

Vector2 Vector2::operator-(const Vector2& right) const {
    Vector2 ret;
    Vector2::sub(*this, right, ret);
    return ret;
}

float Vector2::operator*(const Vector2& b) const {
    return Vector2::dot(*this, b);
}

// computes dot product of 2 vectors
float Vector2::dot(const Vector2& left, const Vector2& right) {
    return left.x * right.x + left.y * right.y;
}

// finds angle between 2 vectors
float Vector2::angle(const Vector2& left, const Vector2& right) {
    float dot = Vector2::dot(left, right);

    return acos(dot / (left.length() * right.length()));
}

// finds distance between 2 vectors
float Vector2::dist(const Vector2& a, const Vector2& b) {
    float x = a.x - b.x;
    float y = a.y - b.y;

    return sqrt(x*x + y*y);
}

// returns normalised vector
Vector2 Vector2::getNormalised(const Vector2& v) {
    Vector2 ret(v);
    ret.normalise();

    return ret;
}

// scales vector by a constant
Vector2& Vector2::scale(float s) {
    x *= s;
    y *= s;

    return *this;
}

// finds normalised vector
Vector2& Vector2::normalise() {
    float magnitude = length();

    if(magnitude == 0) return *this;
    
    x /= magnitude;
    y /= magnitude;

    return *this;
}
