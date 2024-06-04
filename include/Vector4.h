#ifndef INCLUDE_VECTOR4_H
#define INCLUDE_VECTOR4_H

class Vector4 {
    public:
        Vector4(float x=0, float y=0, float z=0, float w=0);
        Vector4(const Vector4& vect);
        Vector4& operator=(const Vector4& vect);
        
        virtual ~Vector4();

        float length() const;
        static void add(const Vector4& left, const Vector4& right, Vector4& dest);
        static void sub(const Vector4& left, const Vector4& right, Vector4& dest);
        static void mul(const Vector4& left, const Vector4& right, Vector4& dest);
        static void lerp(const Vector4& a, const Vector4& b, float t, Vector4& dest);

		Vector4& operator+=(const Vector4& right);
		Vector4& operator-=(const Vector4& right);
		Vector4 operator+(const Vector4& right) const;
		Vector4 operator-(const Vector4& right) const;
		float operator*(const Vector4& b) const;

        static float dot(const Vector4& a, const Vector4& b);
        static float dist(const Vector4& a, const Vector4& b);
        static Vector4 getNormalised(const Vector4& v);

		Vector4& scale(float s);
		Vector4& normalise();

        float x, y, z, w;
};

#endif