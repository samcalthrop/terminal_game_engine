#include "GenericMath.h"
#include "defs.h"

float GenericMath::interpolate(float a, float b, float t) {
    return a + ((b - a) * t);
}

float GenericMath::toRadians(float degrees) {
    return (PI / 180.0f) * degrees;
}

float GenericMath::toDegrees(float radians) {
    return (180.0f / PI) * radians;
}
