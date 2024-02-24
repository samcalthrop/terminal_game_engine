#ifndef INCLUDE_GENERIC_MATH_H
#define INCLUDE_GENERIC_MATH_H

class GenericMath {
    public:
        static float interpolate(float a, float b, float t);
        static float toRadians(float degrees);
        static float toDegrees(float radians);
};

#endif