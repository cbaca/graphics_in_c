#include "local/camera.h"
#include "backend.h"
#include "vecmath.h"
#include <string.h> // memcpy
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

typedef union loc {
    float v[2];
    Cursor p;
} loc_t;

typedef union win {
    float s[2];
    WindowSize w; }
win_t;

struct camera_t {
    Vec3  position,
          front, forward,
          up,      world,
          right,  target;

    float yaw, pitch, // roll,
          velocity, sensitivity,
          dist,
          far, near,
          fov;

    loc_t mouse;
    win_t window;

};

Camera *_cameraInit(Camera *c, Vec3 *pos, float x, float y)
{
    c->yaw = 0.0f;
    c->pitch = 0.0f;
    c->velocity = 0.6f;
    c->sensitivity = 0.2f;
    c->fov = 45.0f;
    c->far = 1000.0f;
    c->near = 0.1f;
    c->dist = 20.0f;

    c->mouse.p.x = x;
    c->mouse.p.y = y;

    vec3set(&c->position, pos);
    c->front = vec3construct(0.0f, 0.0f, 0.0f);
    c->up = vec3construct(0.0f, 1.0f, 0.0f);
    c->world = vec3construct(0.0f, 1.0f, 0.0f);
    Vec3 tar = vec3construct(c->front.x, 0.0f, c->front.z);
    if (tar.z >= 0.0f) {
        if (tar.x >= 0.0f)
            c->yaw = 360.f - TO_DEG(asinf(tar.z));
        else
            c->yaw = 180.f + TO_DEG(asinf(tar.z));
    } else {
        if (tar.x >= 0.0f)
            c->yaw = TO_DEG(asinf(-tar.z));
        else
            c->yaw = 180.f - TO_DEG(asinf(-tar.z));
    }
    c->pitch = -TO_DEG(asinf(c->front.y));

    return update_camera(c); // cameraUpdateEvent(c);
}

void _cameraMoveForward(Camera *c)
{
    c->position.x += c->forward.x;
    c->position.z += c->forward.z;
}
void _cameraMoveBackward(Camera *c)
{
    c->position.x -= c->forward.x;
    c->position.z -= c->forward.z;
}

Camera *new_camera(Vec3 *pos)
{
    WindowSize w;
    window_size(&w);
    Camera *cam = malloc(sizeof(Camera));
    return _cameraInit(cam, pos, w.w/2.0f, w.h/2.0f);
}

void destroy_camera(Camera *cam)
{
    free(cam);
}

Camera *update_camera(Camera *c)
{
    Cursor m;
    window_cursor_position(&m);

    c->yaw   += (m.x - c->mouse.p.x) * c->sensitivity;
    c->pitch += (c->mouse.p.y - m.y) * c->sensitivity;
    c->mouse.p.x = m.x;
    c->mouse.p.y = m.y;
    if (c->pitch > 89.0f) c->pitch = 89.0f;
    if (c->pitch < -89.0f) c->pitch = -89.0f;

    const float yaw = TO_RAD(c->yaw);
    const float pitch = TO_RAD(c->pitch);
    const float cospitch = cosf(pitch);

    // newx = cosf(yaw) * cospitch
    // newy = sinf(pitch)
    // newz = sinf(yaw) * cospitch
    c->front = vec3_construct(cosf(yaw) * cospitch, sinf(pitch), sinf(yaw) * cospitch);

    {
        c->forward = vec3copy(&c->front);
        c->forward.y = 0.0f;
        vec3normalize(&c->forward);
    }
    return c;
}

void init_camera_movement_control_callbacks(Camera *c)
{
    void *cam = (void *)c;
    set_backend_key_callbacks(_camF_callback, cam, KEY_W);
    set_backend_key_callbacks(_camB_callback, cam, KEY_S);
    set_backend_key_callbacks(_camL_callback, cam, KEY_A);
    set_backend_key_callbacks(_camR_callback, cam, KEY_D);
    set_backend_key_callbacks(_camU_callback, cam, KEY_SPACE);
    set_backend_key_callbacks(_camD_callback, cam, KEY_LSHIFT);
}

// void cameraSetLookAt(Camera *c, Mat4 *viewMatrix)
Mat4 *get_camera_lookat_matrix(Camera *c, Mat4 *viewMatrix)
{
    vec3add(vec3set(&c->target, &c->position), &c->front);
    return setLookAtMat4(viewMatrix, &c->position, &c->target, &c->up);
}

// void cameraSetPerspective(Camera *c, Mat4 *p)
Mat4  *get_camera_perspective_matrix(Camera *c, Mat4 *p)
{
    return setPerspectiveMat4(p, c->fov, window_aspect_ratio(), c->near, c->far);
}

/*
void updateCameraTarget(Camera *c)
{
    Vec3 front = vec3copyMulScalar(&c->front, c->dist);
    c->right = vec3copyCross(&front, &c->world);
    c->up = vec3copyCross(&c->right, &front);
    c->target = vec3copyAdd(&c->position, &front);
}

*/
Vec3 getUpdatedCameraTarget(Camera *c)
{
    Vec3 front = vec3copyMulScalar(&c->front, c->dist);
    c->right = vec3copyCross(&front, &c->world);
    c->up = vec3copyCross(&c->right, &front);
    return vec3copyAdd(&c->position, &front);
}

// Camera *cameraSetView(Camera *c, Mat4 *viewMatrix)
Mat4 *get_camera_view_matrix(Camera *c, Mat4 *viewMatrix)
{
    // Vec3 front = vec3copyMulScalar(&c->front, c->dist);
    // c->right = vec3copyCross(&front, &c->world);
    // c->up = vec3copyCross(&c->right, &front);
    // c->target = vec3copyAdd(&c->position, &front);
    c->target = getUpdatedCameraTarget(c);
    setCameraTransformMat4(viewMatrix, &c->position, &c->target, &c->up);
    vec3normalize(&c->right);
    return viewMatrix;
}

Vec3 *get_camera_position(Camera *c)
{
    return &c->position;
}

Vec3 *get_camera_target(Camera *c)
{
    return &c->target;
}

Vec3 get_camera_target_as(Camera *c, const Vec3 *obj_pos)
{
    Vec3 front = vec3copyMulScalar(&c->front, vec3distance(&c->position, obj_pos));
    return vec3copyAdd(&c->position, &front);
}

float *get_resolution_from_camera(Camera *c)
{
    window_size(&c->window.w);
    return c->window.s;
}

float *get_mouse_from_camera(Camera *c)
{
    return c->mouse.v;
}

void set_camera_dist(Camera *c, float d)
{
    c->dist = d;
}

void _cameraMoveLeft(Camera *c) { vec3sub(&c->position, &c->right); }
void _cameraMoveRight(Camera *c) { vec3add(&c->position, &c->right); }
void _cameraMoveDown(Camera *c) { c->position.y -= c->velocity; }
void _cameraMoveUp(Camera *c) { c->position.y += c->velocity; }

void _camD_callback(void *c) { _cameraMoveDown((Camera *)c); }
void _camU_callback(void *c) { _cameraMoveUp((Camera *)c); }
void _camL_callback(void *c) { _cameraMoveLeft((Camera *)c); }
void _camR_callback(void *c) { _cameraMoveRight((Camera *)c); }
void _camF_callback(void *c) { _cameraMoveForward((Camera *)c); }
void _camB_callback(void *c) { _cameraMoveBackward((Camera *)c); }
// z = exp(-(x^2+y^2)) * cos(0.25*x) * sin(y) * cos(2*(x^2+y^2)).

