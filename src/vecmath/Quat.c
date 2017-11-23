#include "vecmath.h"
#include <string.h>
#include <math.h>
#include <float.h>

/********
 *          Generation
 */

quat_t quat_copy(quat_t *src)
{
    return (quat_t){ .x = src->x, .y = src->y, .z = src->z, .w = src->w };
}

quat_t *quat_set(quat_t *dest, const quat_t *src)
{
    memcpy(dest, src, sizeof(quat_t));
    return dest;
}

/*
 * theta θ == pitch     yaw,   pitch, roll
 *   phi Φ == yaw       <- ->, v^,    (^ v)
 *   psi ψ == roll
 * qyaw =   [cos(phi * 0.5),   { 0, 0,   sin(phi * 0.5) } ]
 * qpitch = [cos(theta * 0.5), { 0, sin(theta * 0.5), 0 } ]
 * qroll  = [cos(psi * 0.5),   { sin(psi * 0.5),   0, 0 } ]
 *
 * w = cos(ψ/2) * cos(θ/2) * cos(Φ/2) + sin(ψ/2) * sin(θ/2) * sin(Φ/2)
 * x = sin(ψ/2) * cos(θ/2) * cos(Φ/2) - cos(ψ/2) * sin(θ/2) * sin(Φ/2)
 * y = cos(ψ/2) * sin(θ/2) * cos(Φ/2) + sin(ψ/2) * cos(θ/2) * sin(Φ/2)
 * z = cos(ψ/2) * cos(θ/2) * sin(Φ/2) - sin(ψ/2) * sin(θ/2) * cos(Φ/2)
 */
quat_t *quat_from_euler(quat_t *dest, const struct euler *src)
{
    const float cy = cosf(src->yaw * 0.5f),
                cp = cosf(src->pitch * 0.5f),
                cr = cosf(src->roll * 0.5f),
                sy = sinf(src->yaw * 0.5f),
                sp = sinf(src->pitch * 0.5f),
                sr = sinf(src->roll * 0.5f);

    const float sycp = sy * cp,
                cycp = cy * cp,
                cysp = cy * sp,
                sysp = sy * sp;

    dest->x = sycp * cr - cysp * sr;
    dest->y = cysp * cr + sycp * sr;
    dest->z = cycp * sr - sysp * cr;
    dest->w = cycp * cr + sysp * sr;
    return dest;
}

quat_t *quat_from_vec3(quat_t *dest, const vec3_t *src)
{
    const float cy = cosf(src->x * 0.5f),
                cp = cosf(src->y * 0.5f),
                cr = cosf(src->z * 0.5f),
                sy = sinf(src->x * 0.5f),
                sp = sinf(src->y * 0.5f),
                sr = sinf(src->z * 0.5f);

    const float sycp = sy * cp,
                cycp = cy * cp,
                cysp = cy * sp,
                sysp = sy * sp;

    dest->x = sycp * cr - cysp * sr;
    dest->y = cysp * cr + sycp * sr;
    dest->z = cycp * sr - sysp * cr;
    dest->w = cycp * cr + sysp * sr;
    return dest;
}

quat_t *quat_from_mat3(quat_t *q, mat3_t *m)
{
    float w2 = 0.25f * (1.f + m->data[0] + m->data[4] + m->data[8]);
    if (fabsf(w2) > FLT_EPSILON) {
        q->w = sqrtf(w2);
        q->x = (m->data[5] - m->data[7]) / 4.f * q->w;
        q->y = (m->data[6] - m->data[2]) / 4.f * q->w;
        q->z = (m->data[1] - m->data[3]) / 4.f * q->w;
        return q;
    }

    q->w = 0.f;
    float x2 = -0.5f * (m->data[4] + m->data[8]);
    if (fabsf(x2) > FLT_EPSILON) {
        q->x = sqrtf(x2);
        q->y = m->data[1] / 2.f * q->x;
        q->z = m->data[2] / 2.f * q->x;
        return q;
    }

    q->x = 0.f;
    float y2 = 0.5f * (1.f - m->data[8]);
    if (fabsf(y2) > FLT_EPSILON) {
        q->y = sqrtf(y2);
        q->z = m->data[5] / 2.f * q->y;
        return q;
    }

    q->y = 0.f;
    q->z = 1.f;
    return q;
}




/**************
 *              Arithmetic
 */

quat_t *quat_add(quat_t *dest, const quat_t *src)
{
    dest->x += src->x;
    dest->y += src->y;
    dest->z += src->z;
    dest->w += src->w;
    return dest;
}

quat_t *quat_sub(quat_t *dest, const quat_t *src)
{
    dest->x -= src->x;
    dest->y -= src->y;
    dest->z -= src->z;
    dest->w -= src->w;
    return dest;
}

quat_t *quat_mul(quat_t *dest, const quat_t *src)
{
    return quat_init(dest, dest->w * src->w - dest->x * src->x -
                           dest->y * src->y - dest->z * src->z,

                           dest->w * src->x + dest->x * src->w +
                           dest->y * src->z - dest->z * src->y,

                           dest->w * src->y - dest->x * src->z +
                           dest->y * src->w + dest->z * src->x,

                           dest->w * src->z + dest->x * src->y -
                           dest->y * src->x + dest->z * src->w);
}






/**********
 *          Mutative
 */

static inline float
_quat_dot(const quat_t *q0, const quat_t *q1)
{
    return q0->x * q1->x + q0->y * q1->y + q0->z * q1->z + q0->w * q1->w;
}

quat_t *quat_conjugate(quat_t *dest)
{
    dest->x *= -dest->x;
    dest->y *= -dest->y;
    dest->z *= -dest->z;
    return dest;
}

quat_t *quat_normalize(quat_t *dest)
{
    float rlen = quat_length(dest);
    if (rlen == 0.f) {
        *dest = quat_construct(0.f, 0.f, 0.f, 1.f);
        return dest;
    }

    rlen = 1.f / rlen;
    *dest = quat_construct(
        dest->x * rlen,
        dest->y * rlen,
        dest->x * rlen,
        dest->w * rlen);
    return dest;
}

quat_t *quat_scale(quat_t *dest, float s)
{
    dest->x *= s;
    dest->y *= s;
    dest->z *= s;
    return dest;
}

/* quat_inverse / quat reciprocal
   q^-1 = q' / ∥q∥*∥q∥
   qe-1 = 1.f / length(q) * length(q) * conjugate(q) */
quat_t *quat_inverse(quat_t *dest)
{
    float len = quat_length(dest);
    len = len != 0.f ? 1.f / (len * len) : 0.f;
    quat_conjugate(dest);
    quat_scale(dest, len);
    return dest;
}






/* * * * * * * * *
 *                  Condition / State
 */

float quat_len_sqr(const quat_t *q)
{
    return _quat_dot(q, q);
}
float quat_length(const quat_t *q)
{
    return sqrtf(_quat_dot(q, q));
}

float quat_dot(const quat_t *q0, const quat_t *q1)
{
    return _quat_dot(q0, q1);
}

float quat_extract_angle(const quat_t *q)
{
    float rlen = quat_length(q);
    rlen = rlen != 0.f ? 1.f / rlen : 0.f;
    return 2.f * atan2f(rlen, q->w);
}


/* Quatenion to exponential form. */
quat_t *quat_exp(quat_t *dest, quat_t *src)
{
    float alpha = quat_length(src);
    dest->w = cosf(alpha);

    if (alpha == 0.f) {
        dest->x = 0.f;
        dest->y = 0.f;
        dest->z = 0.f;
        return dest;
    }

    const float ralpha = 1.f / alpha;
    const float salpha = sinf(alpha);

    dest->x = src->x * ralpha * salpha;
    dest->y = src->y * ralpha * salpha;
    dest->z = src->z * ralpha * salpha;
    return dest;
}
