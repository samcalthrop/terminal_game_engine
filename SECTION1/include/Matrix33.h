#ifndef INCLUDE_MATRIX33_H
#define INCLUDE_MATRIX33_H

class Vector3;

class Matrix33{
    public: 
        Matrix33(); 
        Matrix33(const Matrix33& m);
        Matrix33& operator=(const Matrix33& m);

        virtual ~Matrix33(); 
        
        static void add(const Matrix33& left, const Matrix33& right, Matrix33& dest);
        static void sub(const Matrix33& left, const Matrix33& right, Matrix33& dest);
        static void mul(const Matrix33& left, const Matrix33& right, Matrix33& dest);
        static void trans(const Matrix33& left, const Vector3& right, Vector3& dest);

        Matrix33& operator+=(const Matrix33& right);
        Matrix33& operator-=(const Matrix33& right);
        Matrix33& operator*=(const Matrix33& right);
        Matrix33 operator+(const Matrix33& right) const;
        Matrix33 operator-(const Matrix33& right) const;
        Matrix33 operator*(const Matrix33& right) const;
        Vector3 operator*(const Vector3& vec) const;

        void setIdentity();
        void setZero();
    
        void transpose();
        void invert();
        void negate();
		void print() const;
    
        float det() const;
        
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
};
    
#endif
