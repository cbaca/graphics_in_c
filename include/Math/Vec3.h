#ifndef VEC3_FLOAT
#define VEC3_FLOAT
#include <stdbool.h>

typedef struct Mat4 Mat4;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Int3 { int x, y, z; } Int3;
typedef struct Bool3 { bool x, y, z; } Bool3;

Vec3 *vec3set(Vec3 *dest, const Vec3 *src);
Vec3 *vec3init(Vec3 *dest, const float x, const float y, const float z);
Vec3 *vec3add(Vec3 *dest, const Vec3 *src);
Vec3 *vec3sub(Vec3 *dest, const Vec3 *src);
Vec3 *vec3normalize(Vec3 *v);
Vec3 *vec3cross(Vec3 *dest, const Vec3 *src);
Vec3 *vec3multiply(Vec3 *dest, const Vec3 *src);
Vec3 *vec3multScalar(Vec3 *dest, float scalar);
Vec3 *vec3addScalar(Vec3 *dest, float scalar);
Vec3 *vec3mulMat4(Vec3 *dest, Mat4 *m);
Vec3 *vec3negate(Vec3 *v);
Vec3 *vec3unitDirection(Vec3 *dest, const Vec3 *src);
// float *vec3toArray(Vec3 *v);
float vec3length(const Vec3 *v);

float vec3dotProduct(const Vec3 *v, const Vec3 *m);
float vec3dot(const Vec3 *v, const Vec3 *m);

float vec3distance(const Vec3 *from, const Vec3 *to);
bool pointInSphere(const Vec3 *pt, const Vec3 *sp, const float radius);
bool areOrthogonal(const Vec3 *a, const Vec3 *b);
Vec3 *ray_and_plane_intersect(Vec3 *ray, Vec3 *raydir, Vec3 *v0, Vec3 *v1, Vec3 *v2);
#endif /* VEC3_FLOAT */
