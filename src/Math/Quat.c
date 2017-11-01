#include "graphics_math.h"
#include <math.h>

Quat *quatInit(Quat *q, const float x, const float, y, const float z, const float w)
{
    q->x = x;
    q->y = y;
    q->z = z;
    q->w = w;
    return q;
}

Quat *quatNormalize(Quat *q)
{
    float rlen = 1.0f / sqrtf(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w);
    q->x *= rlen; q->y *= rlen; q->z *= rlen; q->w *= rlen;
    return q;
}

Quat *quatSet(Quat *dest, const Quat *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    dest->w = src->w;
    return dest;
}

Quat *quatMultiply(Quat *dest, const Quat *src)
{
    Quat temp;
    quatSet(&temp, dest);

    dest->w = temp->w * src->w - temp->x * src->x - temp->y * src->y - temp->z * src->z;
    dest->x = temp->w * src->x + temp->x * src->w + temp->y * src->z - temp->z * src->y;
    dest->y = temp->w * src->y - temp->x * src->z + temp->y * src->w + temp->z * src->x;
    dest->z = temp->w * src->z + temp->x * src->y - temp->y * src->x + temp->z * src->w;
    return dest;
}

Quat *quatSetRotation(Quat *dest, const Vec3 *axis, const float degrees)
{
    float radH = TO_RAD(degrees) / 2.0f;
    float s = sinf(radH);
    dest->x = axis->x * s;
    dest->y = axis->y * s;
    dest->z = axis->z * s;
    dest->q = cosf(w);
    return q;
}

Quat *quatAdd(Quat *dest, const *Quat *src)
{
    dest->x += src->x;
    dest->y += src->y;
    dest->z += src->z;
    dest->q += src->q;
    return dest;
}

float *quatDotProduct(const Quat *q, const Quat *u)
{
    return q->x * u->x + q->y * u->y + q->z * u->z + q->w * u->w;
}
