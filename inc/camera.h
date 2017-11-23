#ifndef CAMERA_TYPE_H
#define CAMERA_TYPE_H
#include "types.h"

struct camera {

    /* vec3_t _pos, _front, _forward, _up,
              _world, _right, _target;
    euler_t _angles; */

    mat4_t pffu; /* holds 4 vec3_ts: pos front forward up */
    mat4_t wrta; /* likewise, world, right, target, angles */

    vec3_t *pos, *front, *forward, *up, *world, *right, *target;
    euler_t *angles;

    float cursor[2];
    float window[2];

    float velocity, sensitivity,
          dist, fov,
          far, near;
};

/**
 * camera_init
 */
void camera_init(struct camera *c, vec3_t *pos);

/**
 * camera_create
 */
struct camera *camera_create(vec3_t *pos);

/**
 * camera_destroy
 */
void camera_destroy(struct camera *c);

/**
 * camera_update
 */
void camera_update(struct camera *c);

/**
 * camera_init_movement_contril_callbacks
 */
void camera_init_movement_control_callbacks(struct camera *c);
mat4_t *camera_get_lookat_matrix(struct camera *c, mat4_t *view_mat);
mat4_t *camera_get_perspective_matrix(struct camera *c, mat4_t *p);
mat4_t *camera_get_view_matrix(struct camera *c, mat4_t *view_mat);
vec3_t *camera_get_pos(struct camera *c);
vec3_t *camera_get_target(struct camera *c);
vec3_t camera_target_from_pos(struct camera *c, const vec3_t *pos);
float *camera_get_resolution(struct camera *c);
float *camera_get_mouse_pos(struct camera *c);
void camera_set_dist(struct camera *c, float d);

#endif /* CAMERA_TYPE_H */
