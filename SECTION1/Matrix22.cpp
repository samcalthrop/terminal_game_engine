#include "Matrix22.h"
#include "Vector2.h"
#include <iostream>

// initialise an identity matrix
Matrix22::Matrix22()
    :m00(1), m01(0),
    m10(0), m11(1)
{}

Matrix22::Matrix22(const Matrix22& m)
    :m00(m.m00), m01(m.m01),
    m10(m.m10), m11(m.m11)
{}

// equals operator
Matrix22& Matrix22::operator=(const Matrix22& m) {
    this->m00 = m.m00;
    this->m01 = m.m01;
    this->m10 = m.m10;
    this->m11 = m.m11;

    return *this;
}

// destructor
Matrix22::~Matrix22(){}

// add 2 matrices
void Matrix22::add(const Matrix22& left, const Matrix22& right, Matrix22& dest){
    dest.m00 = left.m00 + right.m00;
    dest.m01 = left.m01 + right.m01;
    dest.m10 = left.m10 + right.m10;
    dest.m11 = left.m11 + right.m11;
}

// subtract 2 matrices
void Matrix22::sub(const Matrix22& left, const Matrix22& right, Matrix22& dest){
    dest.m00 = left.m00 - right.m00;
    dest.m01 = left.m01 - right.m01;
    dest.m10 = left.m10 - right.m10;
    dest.m11 = left.m11 - right.m11;
}

// multiply 2 matrices
void Matrix22::mul(const Matrix22& left, const Matrix22& right, Matrix22& dest){
    float m00 = left.m00 * right.m00 + left.m10 * right.m01;
    float m01 = left.m01 * right.m00 + left.m11 * right.m01;
    float m10 = left.m00 * right.m10 + left.m10 * right.m11;
    float m11 = left.m01 * right.m10 + left.m11 * right.m11;

    dest.m00 = m00;
    dest.m01 = m01;
    dest.m10 = m10;
    dest.m11 = m11;
}

// transformation by a 2D vector
void Matrix22::trans(const Matrix22& left, const Vector2& right, Vector2& dest){
    float x = left.m00 * right.x + left.m10 * right.y;
    float y = left.m01 * right.x + left.m11 * right.y;

    dest.x = x;
    dest.y = y;
}

// set identity matrix
void Matrix22::setIdentity() {
    m00 = 1;
    m11 = 1;
    m10 = 0;
    m01 = 0;
}

// set zero matrix
void Matrix22::setZero() {
    m00 = 0;
    m11 = 0;
    m10 = 0;
    m01 = 0;
}

// transpose matrix
void Matrix22::transpose() {
    float temp = m01;
    m01 = m10;
    m10 = temp;
}

// invert matrix
void Matrix22::invert() {
    float determinant = det();

    if (determinant != 0) {
        float determinant_inv = 1/(float)determinant;
        float t00 =  this->m11 * determinant_inv;
        float t01 = -this->m01 * determinant_inv;
        float t11 =  this->m00 * determinant_inv;
        float t10 = -this->m10 * determinant_inv;

        this->m00 = t00;
        this->m01 = t01;
        this->m10 = t10;
        this->m11 = t11;
    }
}

// multiply matrix by -1
void Matrix22::negate(){
    m00 = -m00;
    m01 = -m01;
    m10 = -m10;
    m11 = -m11;
}

// find determinant
float Matrix22::det() const{
    return m00 * m11 - m01 * m10;
}

// print matrix to terminal
void Matrix22::print() const{
	std::cout << m00 << " " << m01 << "\n";
	std::cout << m10 << " " << m11 << "\n";
}