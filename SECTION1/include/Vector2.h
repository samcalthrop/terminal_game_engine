#ifndef INCLUDE_VECTOR2_H
#define INCLUDE_VECTOR2_H

class Vector2 {
    public:
        Vector2(float x=0, float y=0);
        Vector2(const Vector2& vect);
        Vector2& operator=(const Vector2& vect);
        
        virtual ~Vector2();

        float length() const;
        static void add(const Vector2& left, const Vector2& right, Vector2& dest);
        static void sub(const Vector2& left, const Vector2& right, Vector2& dest);
        static void mul(const Vector2& left, const Vector2& right, Vector2& dest);
        static void lerp(const Vector2& a, const Vector2& b, float t, Vector2& dest);

        Vector2& operator+=(const Vector2& right);
		Vector2& operator-=(const Vector2& right);
		Vector2 operator+(const Vector2& right) const;
		Vector2 operator-(const Vector2& right) const;
		float operator*(const Vector2& b) const;

        static float dot(const Vector2& a, const Vector2& b);
        static float angle(const Vector2& a, const Vector2& b);
        static float dist(const Vector2& a, const Vector2& b);
        static Vector2 getNormalised(const Vector2& v);

        Vector2& scale(float s);
        Vector2& normalise();
        
        float x, y;
};

#endif