#include "camera.h"
#include "backend.h"
#include "vecmath.h"
#include <math.h>
#include <string.h> // memcpy
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

void _camera_pos_forward(struct camera *c);
void _camera_pos_backward(struct camera *c);
void _cameraMoveLeft(struct camera *c);
void _cameraMoveRight(struct camera *c);
void _cameraMoveDown(struct camera *c);
void _cameraMoveUp(struct camera *c);

void _camD_callback(void *c);
void _camU_callback(void *c);
void _camL_callback(void *c);
void _camR_callback(void *c);
void _camF_callback(void *c);
void _camB_callback(void *c);

static void _camera_init(struct camera *c, vec3_t *pos, float x, float y)
{
    c->pos     = (vec3_t *)&c->pffu.data[ 0];
    c->front   = (vec3_t *)&c->pffu.data[ 4];
    c->up      = (vec3_t *)&c->pffu.data[ 8];
    c->world   = (vec3_t *)&c->pffu.data[12];
    c->target  = (vec3_t *)&c->wrta.data[ 0];
    c->forward = (vec3_t *)&c->wrta.data[ 4];
    c->right   = (vec3_t *)&c->wrta.data[ 8];
    c->angles = (euler_t *)&c->wrta.data[12];

    c->pos   = vec3_set(c->pos, pos);
    c->front = vec3_init(c->front, 0.f, 0.f, 0.f);
    c->up    = vec3_init(c->up, 0.f, 1.f, 0.f);
    c->world = vec3_init(c->world, 0.f, 1.f, 0.f);

    if (c->front->z >= 0.f) {
        if (c->front->x >= 0.f)
            c->angles->yaw = 360.f - TO_DEG(asinf(c->front->z));
        else
            c->angles->yaw = 180.f - TO_DEG(asinf(c->front->z));
    } else {
        if (c->front->x > 0.f)
            c->angles->yaw = TO_DEG(asinf(-c->front->z));
        else
            c->angles->yaw = 180.f - TO_DEG(asinf(-c->front->z));
    }

    c->angles->pitch = -TO_DEG(asinf(c->front->y));

    c->velocity = 0.6f;
    c->sensitivity = 0.2f;
    c->fov = 45.f;
    c->far = 1000.f;
    c->near = 0.1f;
    c->dist = 20.f;

    c->cursor[0] = x;
    c->cursor[1] = y;

    camera_update(c);
}

void camera_init(struct camera *c, vec3_t *pos)
{
    WindowSize w;
    window_size(&w);
    _camera_init(c, pos, w.w/2.f, w.h/2.f);
}

struct camera *camera_create(vec3_t *pos)
{
    struct camera *c = malloc(sizeof(struct camera));
    camera_init(c, pos);
    return c;
}

void camera_destroy(struct camera *c)
{
    free(c);
}

void camera_update(struct camera *c)
{
    Cursor m;
    window_cursor_position(&m);

    c->angles->yaw += (m.x - c->cursor[0]) * c->sensitivity;
    c->angles->pitch += (c->cursor[1] - m.y) * c->sensitivity;
    c->cursor[0] = m.x;
    c->cursor[1] = m.y;
    c->angles->pitch = clamp(c->angles->pitch, -89.f, 89.f);

    const float yaw = TO_RAD(c->angles->yaw);
    const float pitch = TO_RAD(c->angles->pitch);
    const float cospitch = cosf(pitch);

    /* newx = cosf(yaw) * cospitch
       newy = sinf(pitch)
       newz = sinf(yaw) * cospitch
       theta corresponds to pitch
       phi   corresponds to yaw
       psi   corresponds to roll */
    vec3_init(c->front, cosf(yaw) * cospitch, sinf(pitch), sinf(yaw) * cospitch);
    vec3_set(c->forward, c->front);
    c->forward->y = 0.f;
    vec3normalize(c->forward);
}

/*
 * c->front == cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch)
 *  c->right = c->front x c->world
 *     c->up = c->right x tmp
 * c->target = c->pos + (front scaled by dist)
 */
static inline void _camera_update_vectors(struct camera *c)
{
    vec3cross(vec3set(c->right, c->front), c->world);
    vec3cross(vec3set(c->up, c->right), c->front);
    vec3_t tmp = vec3copyMulScalar(c->front, c->dist);
    vec3add(vec3set(c->target, c->pos), &tmp);
}

vec3_t _camera_get_updated_target(struct camera *c)
{
    Vec3 front = vec3copyMulScalar(c->front, c->dist);
    vec3cross(vec3set(c->right, c->front), c->world);
    vec3cross(vec3set(c->up, c->right), &front);
    return vec3copyAdd(c->pos, &front);
}

mat4_t *camera_get_view_matrix(struct camera *c, mat4_t *view_mat)
{
    _camera_update_vectors(c);
    setCameraTransformMat4(view_mat, c->pos, c->target, c->up);
    vec3normalize(c->right);
    return view_mat;
}

mat4_t *camera_get_lookat_matrix(struct camera *c, mat4_t *view_mat)
{
    vec3add(vec3set(c->target, c->pos), c->front);
    return setLookAtMat4(view_mat, c->pos, c->target, c->up);
}

mat4_t *camera_get_perspective_matrix(struct camera *c, mat4_t *p)
{
    return setPerspectiveMat4(p, c->fov, window_aspect_ratio(), c->near, c->far);
}

vec3_t *camera_get_pos(struct camera *c)
{
    return c->pos;
}

vec3_t *camera_get_target(struct camera *c)
{
    return c->target;
}

/* vec3_t tmp = c->front scaled by distance between camera pos and src pos
 * return c->pos + tmp
 *
 * Return vector of a point on the ray of camera's line of sight, where
 * the distance from the point and the camera's position is the same as
 * the distance between src pos and the camera's position.
 */
vec3_t camera_target_from_pos(struct camera *c, const vec3_t *pos)
{
    vec3_t tmp = vec3copyMulScalar(c->front, vec3distance(c->pos, pos));
    return vec3copyAdd(c->pos, &tmp);
}

float *camera_get_resolution(struct camera *c)
{
    WindowSize w;
    window_size(&w);
    c->window[0] = w.w;
    c->window[1] = w.h;
    return &c->window[0];
}

float *camera_get_mouse_pos(struct camera *c)
{
    return &c->cursor[0];
}

void camera_set_dist(struct camera *c, float d)
{
    c->dist = d;
}

void camera_init_movement_control_callbacks(struct camera *c)
{
    void *cam = (void *)c;
    set_backend_key_callbacks(_camF_callback, cam, KEY_W);
    set_backend_key_callbacks(_camB_callback, cam, KEY_S);
    set_backend_key_callbacks(_camL_callback, cam, KEY_A);
    set_backend_key_callbacks(_camR_callback, cam, KEY_D);
    set_backend_key_callbacks(_camU_callback, cam, KEY_SPACE);
    set_backend_key_callbacks(_camD_callback, cam, KEY_LSHIFT);
}

void _cameraMoveLeft(struct camera *c) { vec3sub(c->pos, c->right); }
void _cameraMoveRight(struct camera *c) { vec3add(c->pos, c->right); }
void _cameraMoveDown(struct camera *c) { c->pos->y -= c->velocity; }
void _cameraMoveUp(struct camera *c) { c->pos->y += c->velocity; }
// static inline void _camera_add_pos(struct camera *c, const float x, const float z)
// {
//     c->pos->x += x;
//     c->pos->z += z;
// }

void _camera_pos_forward(struct camera *c)
{
    c->pos->x += c->forward->x;
    c->pos->z += c->forward->z;
}

void _camera_pos_backward(struct camera *c)
{
    c->pos->x -= c->forward->x;
    c->pos->z -= c->forward->z;
}


void _camD_callback(void *c) { _cameraMoveDown((struct camera *)c); }
void _camU_callback(void *c) { _cameraMoveUp((struct camera *)c); }
void _camL_callback(void *c) { _cameraMoveLeft((struct camera *)c); }
void _camR_callback(void *c) { _cameraMoveRight((struct camera *)c); }
void _camF_callback(void *c) { _camera_pos_forward((struct camera *)c); }
void _camB_callback(void *c) { _camera_pos_backward((struct camera *)c); }
// z = exp(-(x^2+y^2)) * cos(0.25*x) * sin(y) * cos(2*(x^2+y^2)).

