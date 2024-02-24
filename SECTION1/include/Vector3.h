#ifndef INCLUDE_VECTOR3_H
#define INCLUDE_VECTOR3_H

class Vector3 {
    public:
        Vector3(float x=0, float y=0, float z=0);
        Vector3(const Vector3& vect);
        Vector3& operator=(const Vector3& vect);
        
        virtual ~Vector3();

        float length() const;
        static void add(const Vector3& left, const Vector3& right, Vector3& dest);
        static void sub(const Vector3& left, const Vector3& right, Vector3& dest);
        static void mul(const Vector3& left, const Vector3& right, Vector3& dest);
        static void lerp(const Vector3& a, const Vector3& b, float t, Vector3& dest);
        static void cross(const Vector3& a, const Vector3& b, Vector3& dest);

		Vector3& operator%=(const Vector3& right);
		Vector3& operator+=(const Vector3& right);
		Vector3& operator-=(const Vector3& right);
		Vector3 operator+(const Vector3& right);
		Vector3 operator-(const Vector3& right);
		Vector3 operator%(const Vector3& right);
		float operator*(const Vector3& b);

        static float dot(const Vector3& a, const Vector3& b);
        static float angle(const Vector3& a, const Vector3& b);
        static float dist(const Vector3& a, const Vector3& b);
        static Vector3 getNormalised(const Vector3& v);

        Vector3& scale(float s);
		Vector3& normalise();

        float x, y, z;
};

#endif