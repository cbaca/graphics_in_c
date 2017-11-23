#ifndef VEC3_FLOAT
#define VEC3_FLOAT
#include <stdbool.h>
#include "math_types.h"

#define vec3Copy(dest, src) \
    dest->x = src->x; \
    dest->y = src->y; \
    dest->z = src->z;

#define vec3dotProduct(v, m) vec3dot(v, m)
#define vec3multiply(v, m) vec3mul(v, m)
#define vec3multScalar(v, m) vec3mulScalar(v, m)
#define vec3norm(v) vec3normalize(v)

#define vec3_construct(_x, _y, _z) \
    (Vec3){ .x = (_x), .y = (_y), .z = (_z) }

#define vec3_copy_cross(v0, v1) \
    vec3_construct(v0->y * v1->z - v0->z * v1->y, \
                   v0->z * v1->x - v0->x * v1->z, \
                   v0->x * v1->y - v0->y * v1->x)

/**
 * vec3_set
 */
vec3_t *vec3_set(vec3_t *dest, const vec3_t *src);

/**
 * vec3_init
 */
vec3_t *vec3_init(vec3_t *dest, const float x, const float y, const float z);

Vec3 vec3copy(const Vec3 *src);
Vec3 vec3construct(const float x, const float y, const float z) __attribute__ ((const));
Vec3 *vec3set(Vec3 *dest, const Vec3 *src);
Vec3 *vec3init(Vec3 *dest, const float x, const float y, const float z);

Vec3 *vec3add(Vec3 *dest, const Vec3 *src);
Vec3 *vec3sub(Vec3 *dest, const Vec3 *src);
Vec3 *vec3negate(Vec3 *v);
Vec3 *vec3mul(Vec3 *dest, const Vec3 *src);
Vec3 *vec3div(Vec3 *dest, const Vec3 *src);
Vec3 *vec3addScalar(Vec3 *dest, float scalar);
Vec3 *vec3mulScalar(Vec3 *dest, float scalar);
Vec3 *vec3divScalar(Vec3 *dest, float scalar);
Vec3 *vec3normalize(Vec3 *v);
Vec3 *vec3unitDirection(Vec3 *dest, const Vec3 *src);
Vec3 *vec3mulMat4(Vec3 *dest, Mat4 *m);

// vec3_t *vec3_from_quat(vec3_t *dest, const quat_t *q);
// vec3_t *vec3_quat_rotate(vec3_t *dest, const quat_t src);
// vec3_t *vec3_mat_rotate(vec3_t *dest, const quat_t *src);

void vec3_surface_normal_from_plane(Vec3 *restrict v0, Vec3 *restrict v1,
      Vec3 *restrict v2);
Vec3 *vec3normalVector(Vec3 *a, const Vec3 *b, const Vec3 *c);

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
Vec3 *vec3cross(Vec3 *dest, const Vec3 *src);

/**
 * Dot product.
 * Get the cosine of two vectors.
 * Also known as the "projection product".
 * ab = ||a||cos(t)
 * ab = a . bhat, bhat is the unit vector of b => b / ||b||
 */
float vec3dot(const Vec3 *v, const Vec3 *m);
float vec3length(const Vec3 *v);

/**
 * Subtract vectors, and take the length of the difference to get the distance between two vectors.
 */
float vec3distance(const Vec3 *from, const Vec3 *to);

Vec3 vec3copyMulScalar(const Vec3 *a, const float s);
Vec3 vec3copyAdd(const Vec3 *a, const Vec3 *b);
Vec3 vec3copySub(const Vec3 *a, const Vec3 *b);
Vec3 vec3copyCross(const Vec3 *a, const Vec3 *b);
bool vec3equiv(const Vec3 *v0, const Vec3 *v1);

bool pointInSphere(const Vec3 *pt, const Vec3 *sp, const float radius);
bool areOrthogonal(const Vec3 *a, const Vec3 *b);
Vec3 *ray_plane_intersection(Vec3 *ret, const Vec3 *ray, const Vec3 *raydir, const Vec3 *v[3]);
Vec3 *ray_and_plane_intersection(Vec3 *ret, const Vec3 *ray, const Vec3 *raydir, const Vec3 *v0, const Vec3 *v1, const Vec3 *v2);
void vec3printf(const char *name, const Vec3 *v);
#endif /* VEC3_FLOAT */
