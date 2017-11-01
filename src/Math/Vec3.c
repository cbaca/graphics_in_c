#include "Maths.h"
#include <math.h>
#include <float.h>
#include <stdlib.h>
#define DOTVEC3(v, m) (v->x * m->x + v->y * m->y + v->z * m->z)

Vec3 *vec3set(Vec3 *dest, const Vec3 *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
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

Vec3 *vec3normalize(Vec3 *v)
{
    float rlen = 1.0f / sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x *= rlen;
    v->y *= rlen;
    v->z *= rlen;
    return v;
}

Vec3 *vec3divide(Vec3 *dest, const Vec3 *src)
{
    dest->x /= src->x;
    dest->y /= src->y;
    dest->z /= src->z;
    return dest;
}

Vec3 *vec3multiply(Vec3 *dest, const Vec3 *src)
{
    dest->x *= src->x;
    dest->y *= src->y;
    dest->z *= src->z;
    return dest;
}

Vec3 *vec3multScalar(Vec3 *dest, float scalar)
{
    dest->x *= scalar;
    dest->y *= scalar;
    dest->z *= scalar;
    return dest;
}

Vec3 *vec3addScalar(Vec3 *dest, float scalar)
{
    dest->x += scalar;
    dest->y += scalar;
    dest->z += scalar;
    return dest;
}

Vec3 *rtp_to_xyz(Vec3 *v, float radius, float theta, float phi)
{
    v->x = radius * sinf(phi) * cosf(theta);
    v->y = radius * sinf(phi) * sinf(theta);
    v->z = radius * cosf(phi);
    return v;
}

float vec3length(const Vec3 *v)
{
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

Vec3 *vec3negate(Vec3 *v)
{
    v->x = -v->x; v->y = -v->y; v->z = -v->z; return v;
}

/**
 * vec3cross
 * @return handle to Vec3 instance
 * @param dest, Vec3 handle which contains the second operand of the cross product,
 *        and will be modified with the result of the cross product.
 * @param src, Vec3 handle which contains the first operand of the cross product.
 *
 * The cross product is also known as directed area product.
 * It can be used to find a vector perpendicular to the operand vectors.
 * One use for this is to calculate surface normal vectors of surfaces.
 *
 * The /magnitude/ of the cross product of two vectors a and b, can
 * can be interpreted as the area of the parallelogram having sides a & b:
 *
 *      ||a x b|| == ||a||*||b||*sin(theta)
 * While dotProduct can be considered a measure of /parallelism/, since the
 * cross product goes by the sin of the angle between its operands,
 * it can be considered a measure of /perpendicularity/.
 */
Vec3 *vec3cross(Vec3 *dest, const Vec3 *src)
{
    float x = dest->y * src->z - dest->z * src->y;
    float y = dest->z * src->x - dest->x * src->z;
    float z = dest->x * src->y - dest->y * src->x;
    dest->x = x; dest->y = y; dest->z = z;
    return dest;
}

/**
 * Dot product.
 * Get the cosine of two vectors.
 * Also known as the "projection product".
 * ab = ||a||cos(t)
 * ab = a . bhat, bhat is the unit vector of b => b / ||b||
 */
float vec3dotProduct(const Vec3 *v, const Vec3 *m)
{
    return v->x * m->x + v->y * m->y + v->z * m->z;
}

float vec3dot(const Vec3 *v, const Vec3 *m)
{
    return v->x * m->x + v->y * m->y + v->z * m->z;
} __attribute__ ((const))

/**
 * subtract vectors, and take the length of the difference to get distance between two vectors.
 */
float vec3distance(const Vec3 *from, const Vec3 *to)
{
    float x = to->x - from->x;
    float y = to->y - from->y;
    float z = to->z - from->z;
    return sqrtf(x*x + y*y + z*z);
}

Vec3 *vec3unitDirection(Vec3 *a, const Vec3 *b)
{
    Vec3 dir;
    return vec3set(a, vec3normalize(vec3sub(vec3set(&dir, b), a)));
}

bool areOrthogonal(const Vec3 *a, const Vec3 *b)
{
    return DOTVEC3(a, b) == 0.0f;
}

// https://cadxfem.org/inf/Fast%20MinimumStorage%20RayTriangle%20Intersection.pdf
Vec3 *ray_and_plane_intersection(Vec3 *ray, Vec3 *raydir, Vec3 *v0, Vec3 *v1, Vec3 *v2)
{
    Vec3 e0, e1, p, t, q;
    float det;

    // vectors for two edges sharing v0
    vec3sub(vec3set(&e0, v1), v0);
    vec3sub(vec3set(&e1, v2), v0);
    vec3cross(vec3set(&p, raydir), &e1);

    det = vec3dot(&p, &e1);

    if (det < 0.000001f) return NULL;

    ray->y = vec3dot(&p, vec3sub(vec3set(&t, ray), v0));

    if (ray->y < 0.0f || ray->y > det) return NULL;

    ray->x = vec3dot(raydir, vec3cross(vec3set(&q, &t), &e0));

    if (ray->x < 0.0f || ray->x + ray->y > det) return NULL;

    ray->z = vec3dot(&q, &e1);

    return vec3multScalar(ray, 1.0f / det);

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
    t0 = vec3dotProduct(plane_normal, &diff); // plane normal X diff

    t1 = vec3dotProduct(plane_normal, &unitdir);

    Vec3 point_of_intersection = (Vec3){ lv0->x + t0 * unitdir.x / t1,
                                         lv0->y + t0 * unitdir.y / t1,
                                         lv0->z + t0 * unitdir.z / t1  };
    vec3set(ret, &point_of_intersection);
    return true;
}

Vec3 *vec3normalVector(Vec3 *a, const Vec3 *b, const Vec3 *c)
{
    Vec3 v1 = (Vec3){ b->x - a->x, b->y - a->y, b->z - a->z };
    Vec3 v2 = (Vec3){ c->x - a->x, c->y - a->y, c->z - a->z };
    return vec3cross(vec3set(a, &v1), &v2);
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
    Vec3 v = (Vec3){ p1->x - p0->x, p1->y - p0->y, p1->z - p0->z };
    Vec3 u = (Vec3){ p2->x - p0->x, p2->y - p0->y, p2->z - p0->z };
    Vec3 n;
    vec3normalize(vec3cross(vec3set(&n, &v), &u));
    ret[0] = n.x;
    ret[1] = n.y;
    ret[2] = n.z;
    ret[3] = vec3dotProduct(vec3negate(&n), p0);
}

// Vec3 *vec3scalarTripleProduct(Vec3 *a, const Vec3 *b, const Vec3 *c)
// {
//     a . (b x c) or b . (c x a) or c . (a x b)
//     (a . (b x c)) * a == (a x b) x (a x c)
// }

// Final Diffuse = surface diffuse color * light diffuse color * brightness * attenuation
// final specularity = surface specualr color * light specular color * specularity value * attenuation
// final color = ambience + final diffuse + final specularity
