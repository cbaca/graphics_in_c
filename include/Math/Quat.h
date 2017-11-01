#ifndef QUAT_H
#define QUAT_H
#include "Vec3.h"
typedef struct Quat {
    float x, y, z, w;
} Quat;

typedef Quat Vec4;

/*
Quat *quatInit(Quat *q, const float x, const float y, const float z, const float w);
Quat *quatNormalize(Quat *q);
Quat *quatSet(Quat *dest, const Quat *const *src);
Quat *quatMultiply(Quat *dest, const Quat *const *src);
Quat *quatSetRotation(Quat *dest, const Vec3 *const axis, const float degrees);
*/
#endif /* QUAT_H */
