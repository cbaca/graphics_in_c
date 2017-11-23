#include "vecmath.h"
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _DOTVEC3(v, m) (v->x * m->x + v->y * m->y + v->z * m->z)
#define _LENVEC3(v) sqrtf(v->x * v->x + v->y * v->y + v->z * v->z)
#define _MULVEC3SCLR(v, s) v->x *= s; v->y *= s; v->z *= s

Vec3 vec3copy(const Vec3 *src)
{
    // return (Vec3){ src->x, src->y, src->z };
    return (Vec3){ .x = src->x, .y = src->y, .z = src->z };
}

Vec3 vec3construct(const float x, const float y, const float z)
{
    return (Vec3){ .x = x, .y = y, .z = z };
}

vec3_t *vec3_set(vec3_t *dest, const vec3_t *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    return dest;
}

Vec3 *vec3set(Vec3 *dest, const Vec3 *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    return dest;
}

vec3_t *vec3_init(vec3_t *dest, const float x, const float y, const float z)
{
    dest->x = x;
    dest->y = y;
    dest->z = z;
    return dest;
}

Vec3 *vec3init(Vec3 *dest, const float x, const float y, const float z)
{
    dest->x = x;
    dest->y = y;
    dest->z = z;
    return dest;
}

Vec3 *vec3add(Vec3 *dest, const Vec3 *src)
{
    dest->x += src->x;
    dest->y += src->y;
    dest->z += src->z;
    return dest;
}

Vec3 *vec3sub(Vec3 *dest, const Vec3 *src)
{
    dest->x -= src->x;
    dest->y -= src->y;
    dest->z -= src->z;
    return dest;
}

Vec3 *vec3negate(Vec3 *v)
{
    v->x = -v->x; v->y = -v->y; v->z = -v->z;
    return v;
}

Vec3 *vec3mul(Vec3 *dest, const Vec3 *src)
{
    dest->x *= src->x;
    dest->y *= src->y;
    dest->z *= src->z;
    return dest;
}

Vec3 *vec3div(Vec3 *dest, const Vec3 *src)
{
    dest->x /= src->x;
    dest->y /= src->y;
    dest->z /= src->z;
    return dest;
}

Vec3 *vec3addScalar(Vec3 *dest, float scalar)
{
    dest->x += scalar;
    dest->y += scalar;
    dest->z += scalar;
    return dest;
}

Vec3 *vec3mulScalar(Vec3 *dest, float scalar)
{
    _MULVEC3SCLR(dest, scalar);
    return dest;
}

Vec3 *vec3divScalar(Vec3 *dest, float scalar)
{
    dest->x /= scalar;
    dest->y /= scalar;
    dest->z /= scalar;
    return dest;
}

Vec3 *vec3normalize(Vec3 *v)
{
    float rlen = 1.0f / _LENVEC3(v);
// _LENVEC3(v) sqrtf(v->x * v->x + v->y * v->y + v->z * v->z)
// _MULVEC3SCLR(v, s) v->x *= s; v->y *= s; v->z *= s
    _MULVEC3SCLR(v, rlen);
    return v;
}

Vec3 *vec3unitDirection(Vec3 *a, const Vec3 *b)
{
    Vec3 dir = vec3copy(b);
    return vec3set(a, vec3normalize(vec3sub(&dir, a)));
}

Vec3 *vec3mulMat4(Vec3 *dest, Mat4 *mat)
{
    float a[4] = { dest->x, dest->y, dest->z, 1.0f };
    return vec3init(dest, a[0] * mat->data[ 0] + a[1] * mat->data[ 4] +
                          a[2] * mat->data[ 8] + a[3] * mat->data[12],
                          a[0] * mat->data[ 1] + a[1] * mat->data[ 5] +
                          a[2] * mat->data[ 9] + a[3] * mat->data[13],
                          a[0] * mat->data[ 2] + a[1] * mat->data[ 6] +
                          a[2] * mat->data[10] + a[3] * mat->data[14]);
}

/*
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
*/

// Vec3 *vec3_surface_vertex_from_plane(Vec3 *v0, Vec3 *v1, Vec3 *v2)
void vec3_surface_normal_from_plane(Vec3 *v0, Vec3 *v1, Vec3 *v2)
{
    Vec3 e0 = vec3copySub(v2, v1);
    Vec3 e1 = vec3copySub(v0, v1);
    e0 = vec3copyCross(&e1, &e0);
    vec3normalize(vec3add(v0, &e0));
    vec3normalize(vec3add(v1, &e0));
    vec3normalize(vec3add(v2, &e0));
}

Vec3 *vec3normalVector(Vec3 *a, const Vec3 *b, const Vec3 *c)
{
    Vec3 v = vec3copySub(c, a);
    *a = vec3copySub(b, a);
    return vec3cross(a, &v);

    // Vec3 v1 = (Vec3){ b->x - a->x, b->y - a->y, b->z - a->z };
    // Vec3 v2 = (Vec3){ c->x - a->x, c->y - a->y, c->z - a->z };
    // return vec3cross(vec3set(a, &v1), &v2);
}

Vec3 *vec3cross(Vec3 *dest, const Vec3 *src)
{
    return vec3init(dest, dest->y * src->z - dest->z * src->y,
                          dest->z * src->x - dest->x * src->z,
                          dest->x * src->y - dest->y * src->x);
    // float x = dest->y * src->z - dest->z * src->y;
    // float y = dest->z * src->x - dest->x * src->z;
    // float z = dest->x * src->y - dest->y * src->x;
    // dest->x = x; dest->y = y; dest->z = z;
    // return dest;
}

float vec3dot(const Vec3 *v, const Vec3 *m)
{
    return v->x * m->x + v->y * m->y + v->z * m->z;
}

float vec3length(const Vec3 *v)
{
    return _LENVEC3(v);
}

float vec3distance(const Vec3 *from, const Vec3 *to)
{
    float x = to->x - from->x;
    float y = to->y - from->y;
    float z = to->z - from->z;
    return sqrtf(x*x + y*y + z*z);
}

Vec3 vec3copyMulScalar(const Vec3 *a, const float s)
{
    return vec3construct(a->x * s, a->y * s, a->z * s);
}

Vec3 vec3copyAdd(const Vec3 *a, const Vec3 *b)
{
    return vec3construct(a->x + b->x, a->y + b->y, a->z + b->z);
}

Vec3 vec3copySub(const Vec3 *a, const Vec3 *b)
{
    return vec3construct(a->x - b->x, a->y - b->y, a->z - b->z);
}

Vec3 vec3copyCross(const Vec3 *a, const Vec3 *b)
{
    return vec3construct(a->y * b->z - a->z * b->y,
                         a->z * b->x - a->x * b->z,
                         a->x * b->y - a->y * b->x);
}

bool vec3equiv(const Vec3 *v0, const Vec3 *v1)
{
    Vec3 v = vec3copySub(v0, v1);
    if (v.x < -0.000001f) return false;
    if (v.x > 0.000001f) return false;
    if (v.y < -0.000001f) return false;
    if (v.y > 0.000001f) return false;
    if (v.z < -0.000001f) return false;
    if (v.z > 0.000001f) return false;
    return true;
}

bool areOrthogonal(const Vec3 *a, const Vec3 *b)
{
    return _DOTVEC3(a, b) == 0.0f;
}

// https://cadxfem.org/inf/Fast%20MinimumStorage%20RayTriangle%20Intersection.pdf
Vec3 *ray_plane_intersection(Vec3 *ret, const Vec3 *ray, const Vec3 *raydir, const Vec3 *v[3])
{
    Vec3 e0, e1, p, t, q;
    float det;

    vec3sub(vec3set(&e0, v[1]), v[0]);
    vec3sub(vec3set(&e1, v[2]), v[0]);
    vec3cross(vec3set(&p, raydir), &e1);

    det = vec3dot(&p, &e1);

    if (det < 0.000001f) return NULL;

    ret->y = vec3dot(&p, vec3sub(vec3set(&t, ray), v[0]));

    if (ret->y < -0.000001f || ret->y > det) return NULL;

    ret->x = vec3dot(raydir, vec3cross(vec3set(&q, &t), &e0));

    if (ret->x < -0.000001f || ret->x + ret->y > det) return NULL;

    ret->z = vec3dot(&q, &e1);

    return vec3multScalar(ret, 1.0f / det);
}

Vec3 *ray_and_plane_intersection(Vec3 *ret, const Vec3 *ray, const Vec3 *raydir, const Vec3 *v0, const Vec3 *v1, const Vec3 *v2)
{
    Vec3 e0, e1, p, t, q;
    float det;

    // vectors for two edges sharing v0
    vec3sub(vec3set(&e0, v1), v0);
    vec3sub(vec3set(&e1, v2), v0);
    vec3cross(vec3set(&p, raydir), &e1);

    det = vec3dot(&p, &e1);

    if (det < 0.000001f) return NULL;

    ret->y = vec3dot(&p, vec3sub(vec3set(&t, ray), v0));

    if (ret->y < 0.0f || ret->y > det) return NULL;

    ret->x = vec3dot(raydir, vec3cross(vec3set(&q, &t), &e0));

    if (ret->x < 0.0f || ret->x + ret->y > det) return NULL;

    ret->z = vec3dot(&q, &e1);

    return vec3multScalar(ret, 1.0f / det);

    // Vec3 t, q;
    // if (det > -0.000001f && det < 0.000001f) return 0;
    // float inv_det = 1.0f / det;
    // ray->y = vec3dot(&p, vec3sub(vec3set(&t, ray), v0)) * inv_det;
    // if (ray->y < 0.0f || ray->y > 1.0f) return 0;
    // ray->x = vecdot(raydir, vec3cross(vec3set(&q, &t), &e0)) * inv_det;
    // if (ray->x < 0.0f || ray->x + ray->y > 1.0f) return 0;
    // ray->z = vec3dot(&q, &e1) * inv_det;
    // return ray;
}


// http://people.sc.fsu.edu/%7Ejburkardt/c_src/geometry/geometry.c line 17294
// point on plane, normal of plane, line start, line end
// segmentAndPlane
bool vectorAndPlaneIntersection(Vec3 *ret, Vec3 *point_on_plane, Vec3 *plane_normal, Vec3 *lv0, Vec3 *lv1)
{
    vec3normalize(plane_normal);
    Vec3 unitdir;
    vec3set(&unitdir, lv0);
    vec3unitDirection(&unitdir, lv1);
    if (areOrthogonal(plane_normal, &unitdir))

        return false;

    float t0, t1;
    Vec3  diff;

    vec3sub(vec3set(&diff, point_on_plane), lv0); // point on plane - line vertex 0
    t0 = vec3dot(plane_normal, &diff); // plane normal X diff

    t1 = vec3dot(plane_normal, &unitdir);

    Vec3 point_of_intersection = vec3construct(lv0->x + t0 * unitdir.x / t1,
                                               lv0->y + t0 * unitdir.y / t1,
                                               lv0->z + t0 * unitdir.z / t1);
    vec3set(ret, &point_of_intersection);
    return true;
}

Vec3 *vec3projectPoint(Vec3 *pos, float dist, Vec3 *norm)
{
    Vec3 n;
    return vec3sub(pos, vec3multScalar(vec3set(&n, norm), dist));
}

/**
 * Attenuation of specular reflection.
 */
float vec3attenuation(const float dist, const float maxdist)
{
    float att = dist / maxdist;
    return 1.0f - (att < 0.0f ? 0.0f : att > 1.0f ? 1.0f : att);
}


bool pointInSphere(const Vec3 *pt, const Vec3 *sp, const float radius)
{
    float x = pt->x - sp->x;
    float y = pt->y - sp->y;
    float z = pt->z - sp->z;
    return (x*x + y*y + z*z) <= radius * radius;
}


float vec3computeLineDistance(float coeffs[4], Vec3 *v, float r)
{
    return coeffs[0] * r * v->x + coeffs[1] * r * v->y + coeffs[2] * r * v->z + coeffs[3];
}

void vec3computeLineCoefficients(float ret[4], Vec3 *p0, Vec3 *p1, Vec3 *p2)
{
    Vec3 v = vec3construct(p1->x - p0->x, p1->y - p0->y, p1->z - p0->z);
    Vec3 u = vec3construct(p2->x - p0->x, p2->y - p0->y, p2->z - p0->z);
    Vec3 n;
    vec3normalize(vec3cross(vec3set(&n, &v), &u));
    ret[0] = n.x;
    ret[1] = n.y;
    ret[2] = n.z;
    ret[3] = vec3dotProduct(vec3negate(&n), p0);
}

Vec3 *rtp_to_xyz(Vec3 *v, float radius, float theta, float phi)
{
    v->x = radius * sinf(phi) * cosf(theta);
    v->y = radius * sinf(phi) * sinf(theta);
    v->z = radius * cosf(phi);
    return v;
}

void vec3printf(const char *name, const Vec3 *v)
{
    if (name) {
//         printf("%s %+-.4f %+-.4f %+-.4f\n", name, v->x, v->y, v->z);
        printf("%s %+-.6f %+-.6f %+-.6f\n", name, v->x, v->y, v->z);
        return;
    }
//     printf("%+-.4f %+-.4f %+-.4f\n", v->x, v->y, v->z);
    printf("%+-.6f %+-.6f %+-.6f\n", v->x, v->y, v->z);
}

// void variance()
// {
    // int mu = 0; for (i = 0; i < N; ++i) mu += x[i]; mu /= N;
    // int sum = 0; for (i : N) sum += ((x[i] - mu) * (x[i] - mu)); sum /= N;
    //  variance = sqrtf(sum);
    //
    // int sum = 0; for (i : N) sum += x[i];
    // variance = sqrtf((sum - (mu * mu)) / N);
// }

// Vec3 *vec3scalarTripleProduct(Vec3 *a, const Vec3 *b, const Vec3 *c)
// {
//     a . (b x c) or b . (c x a) or c . (a x b)
//     (a . (b x c)) * a == (a x b) x (a x c)
// }

// Final Diffuse = surface diffuse color * light diffuse color * brightness * attenuation
// final specularity = surface specualr color * light specular color * specularity value * attenuation
// final color = ambience + final diffuse + final specularity
