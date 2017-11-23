#ifndef VECROT_H
#define VECROT_H
#include "math_types.h"

mat4_t *mat4_rot_from_quat(mat4_t *m, const quat_t *q);

mat4_t *mat4_rot_from_vec(mat4_t *m, const vec3_t *v, const float degrees);

mat4_t *mat4_set_rot_x(mat4_t *m, const float degrees);

mat4_t *mat4_set_rot_y(mat4_t *m, const float degrees);

mat4_t *mat4_set_rot_z(mat4_t *m, const float degrees);

mat4_t *mat4_rotate(mat4_t *m, const vec3_t *v, const float degrees);

mat4_t *mat4_rotate_x(mat4_t *m, const float degrees);

mat4_t *mat4_rotate_y(mat4_t *m, const float degrees);

mat4_t *mat4_rotate_z(mat4_t *m, const float degrees);

mat4_t *mat4_set_lookat(mat4_t *m, vec3_t *pos, vec3_t *tar, vec3_t *up);

mat4_t *mat4_set_lookat_min(mat4_t *m, const vec3_t *tar, const vec3_t *up);

mat4_t *mat4_set_camera_transform(mat4_t *m,
    const vec3_t *pos, const vec3_t *tar, const vec3_t *up);

mat3_t *vec3_to_mat3(mat3_t *m, const euler_t *e);
mat3_t *quat_to_mat3(mat3_t *dest, const quat_t *src);

quat_t *quat_rotation_from_vector(quat_t *dest, const vec3_t *v, const float degrees);


/**
 * quat_rot - Calculate the rotation vector from a quaternion.
 *
 * Description:
 * The rotated vector is found by multiplying it on the right by
 * the rotation quaterniun, and on the left by the conjugate of
 * the rotation quaternion.
 *
 * @param dest: Destination of return value.
 * @param src:  Rotation quaternion.
 * @return:     Pointer to @dest.
 */
quat_t *quat_rot(quat_t *dest, const quat_t *src);
quat_t *quat_slerp(quat_t *dest, quat_t *src, float t);
quat_t *quat_slerp_b(quat_t *dest, const quat_t *src, float t);

vec3_t *vec3_from_quat(vec3_t *dest, const quat_t *q);
vec3_t *vec3_quat_rotate(vec3_t *dest, const quat_t *src);
vec3_t *vec3_mat_rotate(vec3_t *dest, const quat_t *src);
#endif /* VECROT_H */
