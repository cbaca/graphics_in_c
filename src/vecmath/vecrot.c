#include "vecmath.h"
#include <float.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*
 * yaw,   pitch, roll
 * <- ->, v^,    (^ v)
 *
 * theta θ == pitch
 *   phi Φ == yaw
 *   psi ψ == roll
 */

mat4_t *mat4_rot_from_quat(mat4_t *m, const quat_t *q)
{
    const float nq = quat_len_sqr(q);
    const float s = (nq > 0.f) ? 2.f / nq : 0.f;

    const float
        xs = q->x * s,
        ys = q->y * s,
        zs = q->z * s;

    const float
        wx = q->w * xs,
        wy = q->w * ys,
        wz = q->w * zs,
            xx = q->x * xs,
            xy = q->x * ys,
            xz = q->x * zs,
                yy = q->y * ys,
                yz = q->y * zs,
                zz = q->y * zs;

    m->data[ 0] = 1.f - (yy + zz);
    m->data[ 1] = xy - wz;
    m->data[ 2] = xz + wy;
    m->data[ 3] = 0.f;
    m->data[ 4] = xy - wz;
    m->data[ 5] = 1.f - (xx + zz);
    m->data[ 6] = yz - wx;
    m->data[ 7] = 0.f;
    m->data[ 8] = xz - wy;
    m->data[ 9] = yz + wx;
    m->data[10] = 1.f - (xx + yy);
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.f;
    m->data[15] = 1.f;
    return m;
}

mat4_t *mat4_rot_from_vec(mat4_t *m, const vec3_t *v, const float degrees)
{
    const float rad = TO_RAD(degrees);

    const float
        c = cosf(rad),
        s = sinf(rad);

    const float
        nc = 1.f - c,
            xs = v->x * s,
            ys = v->y * s,
            zs = v->z * s,
                xy = v->x * v->y,
                xz = v->x * v->z,
                yz = v->y * v->z;

    const float
        xync = xy * nc,
        xznc = xz * nc,
        yznc = yz * nc;

    m->data[ 0] = v->x * v->x * nc + c;
    m->data[ 1] = xync + zs;
    m->data[ 2] = xznc - ys;
    m->data[ 3] = 0.f;
    m->data[ 4] = xync - zs;
    m->data[ 5] = v->y * v->y * nc + c;
    m->data[ 6] = yznc + xs;
    m->data[ 7] = 0.f;
    m->data[ 8] = xznc + ys;
    m->data[ 9] = yznc - xs;
    m->data[10] = v->z * v->z * nc + c;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.f;
    m->data[15] = 1.f;
    return m;
}

mat4_t *mat4_set_rot_x(mat4_t *m, const float degrees)
{
    const float rad = TO_RAD(degrees);
    const float s = sinf(rad),
                c = cosf(rad);
    m->data[ 0] = 1.0f;
    m->data[ 1] = m->data[ 2] = m->data[ 3] = m->data[ 4] = 0.0f;
    m->data[ 5] = c;
    m->data[ 6] = s;
    m->data[ 7] = m->data[ 8] = 0.0f;
    m->data[ 9] = -s;
    m->data[10] = c;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.0f;
    m->data[15] = 1.0f;
    return m;
}

mat4_t *mat4_set_rot_y(mat4_t *m, const float degrees)
{
    const float rad = TO_RAD(degrees);
    const float s = sinf(rad),
                c = cosf(rad);
    m->data[ 0] = c;
    m->data[ 1] = 0.0f;
    m->data[ 2] = -s;
    m->data[ 3] = m->data[ 4] = 0.0f;
    m->data[ 5] = 1.0f;
    m->data[ 6] = m->data[ 7] = 0.0f;
    m->data[ 8] = s;
    m->data[ 9] = 0.0f;
    m->data[10] = c;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.0f;
    m->data[15] = 1.0f;
    return m;
}

mat4_t *mat4_set_rot_z(mat4_t *m, const float degrees)
{
    const float radians = TO_RAD(degrees);
    float s = sinf(radians);
    float c = cosf(radians);
    m->data[ 0] = c;
    m->data[ 1] = s;
    m->data[ 2] = m->data[ 3] = 0.0f;
    m->data[ 4] = -s;
    m->data[ 5] = c;
    m->data[ 6] = m->data[ 7] = m->data[ 8] = m->data[ 9] = 0.0f;
    m->data[10] = 1.0f;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.0f;
    m->data[15] = 1.0f;
    return m;
}

mat4_t *mat4_rotate(mat4_t *m, const vec3_t *v, const float degrees)
{
    mat4_t tmp;
    memcpy(tmp.data, m->data, MAT4_SIZE);
    return mat4_mul(m, mat4_rot_from_vec(&tmp, v, degrees));
}

mat4_t *mat4_rotate_x(mat4_t *m, const float degrees)
{
    mat4_t tmp;
    return mat4_mul(m, mat4_set_rot_x(setMat4(&tmp, m), degrees));
}

mat4_t *mat4_rotate_y(mat4_t *m, const float degrees)
{
    mat4_t tmp;
    return mat4_mul(m, mat4_set_rot_y(setMat4(&tmp, m), degrees));
}

mat4_t *mat4_rotate_z(mat4_t *m, const float degrees)
{
    mat4_t tmp;
    return mat4_mul(m, mat4_set_rot_z(setMat4(&tmp, m), degrees));
}

mat4_t *mat4_set_lookat(mat4_t *m, vec3_t *pos, vec3_t *tar, vec3_t *up)
{
    vec3_t forward,
           side,
           top;

    forward = vec3copySub(tar, pos);
    vec3normalize(&forward);
    side = vec3copyCross(&forward, up);
    vec3normalize(&side);
    top = vec3copyCross(&side, &forward);

    m->data[ 0] = side.x;
    m->data[ 1] = top.x;
    m->data[ 2] = -forward.x;
    m->data[ 3] = 0.0f;
    m->data[ 4] = side.y;
    m->data[ 5] = top.y;
    m->data[ 6] = -forward.y;
    m->data[ 7] = 0.0f;
    m->data[ 8] = side.z;
    m->data[ 9] = top.z;
    m->data[10] = -forward.z;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.0f;
    m->data[15] = 1.0f;
    return m;
}

mat4_t *mat4_set_lookat_min(mat4_t *m, const vec3_t *tar, const vec3_t *up)
{
    vec3_t n, u, v; // forward, right, up
    vec3normalize(vec3set(&n, tar));
    vec3normalize(vec3cross(vec3set(&u, up), tar));
    vec3cross(vec3set(&v, &n), &u);

    m->data[ 0] = u.x;
    m->data[ 1] = u.y;
    m->data[ 2] = u.z;
    m->data[ 3] = 0.f;
    m->data[ 4] = v.x;
    m->data[ 5] = v.y;
    m->data[ 6] = v.z;
    m->data[ 7] = 0.f;
    m->data[ 8] = n.x;
    m->data[ 9] = n.y;
    m->data[10] = n.z;
    m->data[11] = m->data[12] = m->data[13] = m->data[14] = 0.f;
    m->data[15] = 1.f;
    return m;
}

mat4_t *mat4_set_camera_transform(mat4_t *m,
    const vec3_t *pos, const vec3_t *tar, const vec3_t *up)
{
    vec3_t f, s, u; // forward, right, up
    vec3normalize(vec3sub(vec3set(&f, tar), pos));
    vec3normalize(vec3cross(vec3set(&s, &f), up));
    vec3cross(vec3set(&u, &s), &f);
    m->data[ 0] = s.x;
    m->data[ 1] = u.x;
    m->data[ 2] = -f.x;
    m->data[ 3] = 0.0f;
    m->data[ 4] = s.y;
    m->data[ 5] = u.y;
    m->data[ 6] = -f.y;
    m->data[ 7] = 0.0f;
    m->data[ 8] = s.z;
    m->data[ 9] = u.z;
    m->data[10] = -f.z;
    m->data[11] = 0.0f;
    m->data[12] = -vec3dotProduct(&s, pos);
    m->data[13] = -vec3dotProduct(&u, pos);
    m->data[14] =  vec3dotProduct(&f, pos);
    m->data[15] = 1.0f;
    return m;
}

/* quat_local_rotation
   Multiply this with the*/
quat_t *quat_rotation_from_vector(quat_t *dest, const vec3_t *v, const float degrees)
{
    float half = TO_RAD(degrees) * 0.5f;
    float s = sinf(half);
    dest->x = v->x * s;
    dest->y = v->y * s;
    dest->z = v->z * s;
    dest->w = cosf(half);
    return dest;
}

/* Euler angles to quaternions
 * qyaw =   [cos(phi * 0.5),   { 0, 0,   sin(phi * 0.5) } ]
 * qpitch = [cos(theta * 0.5), { 0, sin(theta * 0.5), 0 } ]
 * qroll  = [cos(psi * 0.5),   { sin(psi * 0.5),   0, 0 } ]
 *
 * w = cos(ψ/2) * cos(θ/2) * cos(Φ/2) + sin(ψ/2) * sin(θ/2) * sin(Φ/2)
 * x = sin(ψ/2) * cos(θ/2) * cos(Φ/2) - cos(ψ/2) * sin(θ/2) * sin(Φ/2)
 * y = cos(ψ/2) * sin(θ/2) * cos(Φ/2) + sin(ψ/2) * cos(θ/2) * sin(Φ/2)
 * z = cos(ψ/2) * cos(θ/2) * sin(Φ/2) - sin(ψ/2) * sin(θ/2) * cos(Φ/2)
 */

/*
 * Calculate the rotation vector from a quternion.
 */
quat_t *quat_rot(quat_t *dest, const quat_t *src)
{
    dest->w = 0.f;
    quat_t inv;
    quat_inverse(quat_set(&inv, src));
    quat_mul(dest, src);
    quat_mul(&inv, dest);
    quat_set(dest, &inv);
    return dest;
}

/* Euler angles to 3x3 rotation matrix
   { cosθcosΦ               , cosθsinΦ               , -sinθ    }
   { sinψsinθcosΦ - cosψsinΦ, sinψsinθsinΦ + cosψcosθ, cosθsinψ }
   { cosψsinθcosΦ + sinψsinΦ, cosψsinθsinΦ - sinψcosΦ, cosθcosψ } */
mat3_t *vec3_to_mat3(mat3_t *m, const euler_t *e)
{
    const float
        cp = cosf(e->pitch), cy = cosf(e->yaw), cr = cosf(e->roll),
        sp = sinf(e->pitch), sy = sinf(e->yaw), sr = sinf(e->roll);
    const float srsp = sr * sp;
    const float crsp = cr * sp;

    m->data[0] = cp * cy;
    m->data[1] = cp * sy;
    m->data[2] = -sp;
    m->data[3] = srsp * cy - cr * sy;
    m->data[4] = srsp * sy + cr * cp;
    m->data[5] = cp * sr;
    m->data[6] = crsp * cy + sr * sy;
    m->data[7] = crsp * sy - sr * cy;
    m->data[8] = cp * cr;
    return m;
}

/**
 *
 */
mat3_t *quat_to_mat3(mat3_t *dest, const quat_t *src)
{
    const float nq = quat_len_sqr(src);
    const float s = nq > 0.f ? 2.f / nq : 0.f;

    const float xs = src->x * s,
                ys = src->y * s,
                zs = src->z * s;

    const float
        wx = src->w * xs,
        wy = src->w * ys,
        wz = src->w * zs,
            xx = src->x * xs,
            xy = src->x * ys,
            xz = src->x * zs,
                yy = src->y * ys,
                yz = src->y * zs,
                zz = src->y * zs;

    /* The diagonals 0, 4, and 8 and simplified
       because we should be working with a
       unit quaternion.
       Otherwise, the formula would be
       dest->data[0] = w*w + x*x  - y*y - z*z
       dest->data[4] = w*w - x*x  + y*y - z*z
       dest->data[8] = w*w + x*x  - y*y + z*z */
    dest->data[ 0] = 1.f - (yy + zz);
    dest->data[ 1] = xy - wz;
    dest->data[ 2] = xz + wy;

    dest->data[ 3] = xy - wz;
    dest->data[ 4] = 1.f - (xx + zz);
    dest->data[ 5] = yz - wx;

    dest->data[ 6] = xz - wy;
    dest->data[ 7] = yz + wx;
    dest->data[ 8] = 1.f - (xx + yy);

    return dest;
}

quat_t *quat_slerp(quat_t *dest, quat_t *src, float t)
{
    float dot = quat_dot(dest, src);
    float pdot = fabsf(dot);

    float scl0;
    float scl1;

    if (pdot >= 1.f) {
        scl0 = 1.f - t;
        scl1 = t;
    } else {
        float theta = acosf(pdot);
        float stheta = sinf(theta);

        scl0 = sinf((1.f - t) * theta) / stheta;
        scl1 = sinf(t * theta) / stheta;
    }

    if (dot < 0.f)
        scl1 = -scl1;

    quat_t v1;
    quat_set(&v1, src);
    quat_scale(&v1, scl1);
    quat_scale(dest, scl0);
    return quat_add(dest, &v1);
}

quat_t *quat_slerp_b(quat_t *dest, const quat_t *src, float t)
{
    float dot = quat_dot(dest, src);

    if (fabs(dot) > 0.9995f) {
        quat_t v1;
        return quat_add(dest, quat_scale(quat_sub(quat_set(&v1, src), dest), t));
    }

    quat_t v1;
    quat_set(&v1, src);

    if (dot < 0.f) {
        quat_conjugate(&v1);
        dot = -dot;
    }

    clamp(dot, -1.f, 1.f);
    float theta = acosf(dot) * t;
    quat_scale(quat_normalize(quat_sub(&v1, quat_scale(dest, dot))), sinf(theta));
    quat_scale(dest, cosf(theta));
    return quat_add(dest, &v1);
}

/* Note: the angle of the rotation is 2*atan2f(quat_length(q), q->w) */
vec3_t *vec3_from_quat(vec3_t *dest, const quat_t *q)
{
    float rlen = quat_length(q);
    rlen = rlen != 0.f ? 1.f / rlen : 0.f;
    dest->x = q->x * rlen;
    dest->y = q->y * rlen;
    dest->z = q->z * rlen;
    return dest;
}

vec3_t *vec3_quat_rotate(vec3_t *dest, const quat_t *src)
{
    quat_t tmp;
    quat_rot(&tmp, src);
    return vec3_from_quat(dest, src);
}

vec3_t *vec3_mat_rotate(vec3_t *dest, const quat_t *src)
{
    mat3_t _m;
    mat3_t *m = quat_to_mat3(&_m, src);

    return vec3init(dest,
        dest->x * m->data[0] + dest->y * m->data[3] + dest->z * m->data[6],
        dest->x * m->data[1] + dest->y * m->data[4] + dest->z * m->data[7],
        dest->x * m->data[2] + dest->y * m->data[5] + dest->z * m->data[8]);
}

/*
vec3 *rtp_to_xyz(Vec3 *v, float radius, float theta, float phi)
{
    v->x = radius * sinf(phi) * cosf(theta);
    v->y = radius * sinf(phi) * sinf(theta);
    v->z = radius * cosf(phi);
    return v;
}
*/
