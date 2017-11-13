#ifndef VEC3_ASM_H
#define VEC3_ASM_H
#include "math_types.h"
Vec3 vec3_cpy(const Vec3 *v0);
Vec3 vec3_construct(const float x, const float y, const float z);
Vec3 *vec3_set(Vec3 *dest, const Vec3 *src);
Vec3 *vec3_init(Vec3 *dest, const float x, const float y, const float z);
Vec3 *vec3_add(Vec3 *dest, const Vec3 *src);
Vec3 *vec3_sub(Vec3 *dest, const Vec3 *src);
Vec3 *vec3_negate(Vec3 *dest);
Vec3 *vec3_mul(Vec3 *dest, const Vec3 *src);
Vec3 *vec3_div(Vec3 *dest, const Vec3 *src);
Vec3 *vec3_add_scalar(Vec3 *dest, const float scalar);
Vec3 *vec3_mul_scalar(Vec3 *dest, const float scalar);
Vec3 *vec3_div_scalar(Vec3 *dest, const float scalar);

Vec3 *vec3_normalize(Vec3 *dest);
// Vec3 *vec3_unit_direction(Vec3 *dest, const Vec3 *src);
// Vec3 *vec3_mul_mat4(Vec3 *dest, Mat4 *m);
// Vec3 *vec3_normal_vector(Vec3 *a, const Vec3 *b, const Vec3 *c);
Vec3 *vec3_cross(Vec3 *dest, const Vec3 *src);
float vec3_dot(const Vec3 *v0, const Vec3 *v1);

float vec3_length(const Vec3 *v);
// float vec3_distance(const Vec3 *from, const Vec3 *to);

Vec3 vec3_copy_mul_scalar(const Vec3 *a, const float s);
Vec3 vec3_copy_add(const Vec3 *a, const Vec3 *b);
Vec3 vec3_copy_sub(const Vec3 *a, const Vec3 *b);
Vec3 vec3_copy_cross(const Vec3 *a, const Vec3 *b);

bool vec3_equiv(const Vec3 *v0, const Vec3 *v1);
// bool vec3_are_orthogonal(const Vec3 *a, const Vec3 *b);
bool vec3_point_in_sphere(const Vec3 *pt, const Vec3 *sp, const float radius);

// Vec3 *vec3_ray_plane_intersection(Vec3 *ret, const Vec3 *ray, const Vec3 *raydir, const Vec3 *v[3]);
// Vec3 *vec3_vec_plane_intersection(Vec3 *ret,
    // const Vec3 *ray, const Vec3 *raydir, const Vec3 *v0, const Vec3 *v1, const Vec3 *v2);
// void vec3_printf(const char *name, const Vec3 *v);
#endif
