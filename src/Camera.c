#include "local/camera.h"
#include "Backend.h"
#include <string.h> // memcpy
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

struct Camera_t {
    Vec3 position, front, forward, up, world, right, target, ray;
    float dist, yaw, pitch, velocity, sensitivity, lastX, lastY, fov, far, near;
    float winW, winH;
};

// local ray normal
Vec3 *getCameraRay(Camera_t *c)
{
    Window_t w;
    eventGetWindowSize(&w);
    c->ray = (Vec3){ ((c->position.x / w.w) * 2.0f - 1.0f) * w.w,
                     -c->near,
                     ((1.0f - (c->position.y / w.h)) * 2.0f - 1.0f) * w.h
                     };
    return vec3normalize(&c->ray);
}

Camera_t *newCamera(Vec3 *pos)
{
    Window_t w;
    eventGetWindowSize(&w);
    Camera_t *cam = malloc(sizeof(Camera_t));
    return _cameraInit(cam, pos, w.w/2.0f, w.h/2.0f);
}

void destroyCamera(Camera_t *cam) { free(cam); }

Camera_t *cameraUpdateEvent(Camera_t *c)
{
    Mouse_t m;
    eventGetMousePos(&m);

    c->yaw += (m.x - c->lastX) * c->sensitivity;
    c->pitch += (c->lastY - m.y) * c->sensitivity;
    c->lastX = m.x;
    c->lastY = m.y;
    if (c->pitch > 89.0f) c->pitch = 89.0f;
    if (c->pitch < -89.0f) c->pitch = -89.0f;

    const float yaw = TO_RAD(c->yaw);
    const float pitch = TO_RAD(c->pitch);
    const float cospitch = cosf(pitch);


    c->front = (Vec3){ cosf(yaw) * cospitch, sinf(pitch), sinf(yaw) * cospitch };

    {
        vec3set(&c->forward, &c->front);
        c->forward.y = 0.0f;
        vec3normalize(&c->forward);
    }

    vec3multScalar(&c->front, c->dist);
    vec3cross(vec3set(&c->right, &c->front), &c->world);
    vec3cross(vec3set(&c->up, &c->right), &c->front);
    return c;
}

void setCameraCallbacks(Camera_t *c)
{
    void *cam = (void *)c;
    backendSetCallback(_camF_callback, cam, KEY_W);
    backendSetCallback(_camB_callback, cam, KEY_S);
    backendSetCallback(_camL_callback, cam, KEY_A);
    backendSetCallback(_camR_callback, cam, KEY_D);
    backendSetCallback(_camU_callback, cam, KEY_SPACE);
    backendSetCallback(_camD_callback, cam, KEY_LSHIFT);
}

void cameraSetLookAt(Camera_t *c, Mat4 *viewMatrix)
{
    vec3add(vec3set(&c->target, &c->position), &c->front);
    setLookAtMat4(viewMatrix, &c->position, &c->target, &c->up);
}

Camera_t *cameraSetView(Camera_t *c, Mat4 *viewMatrix)
{
    vec3add(vec3set(&c->target, &c->position), &c->front);
    setCameraTransformMat4(viewMatrix, &c->position, &c->target, &c->up);
    // vec3normalize(&c->front);
    vec3normalize(&c->right);
    return c;
}

void cameraSetPerspective(Camera_t *c, Mat4 *p)
{
    setPerspectiveMat4(p, c->fov, eventGetAspectRatio(), c->near, c->far);
}

Vec3 *getCameraTarget(Camera_t *c) { return &c->target; }
Vec3 *getCameraPosition(Camera_t *c) { return &c->position; }

Camera_t *_cameraInit(Camera_t *c, Vec3 *pos, float x, float y)
{
    c->yaw = 0.0f;
    c->pitch = 0.0f;
    c->velocity = 0.6f;
    c->sensitivity = 0.2f;
    c->fov = 45.0f;
    c->far = 1000.0f;
    c->near = 0.1f;
    c->dist = 20.0f;

    c->lastX = x;
    c->lastY = y;

    vec3set(&c->position, pos);
    c->front.x = 0.0f; c->front.y = 0.0f; c->front.z = 0.0f;
    c->up.x    = 0.0f; c->up.y    = 1.0f; c->up.z    = 0.0f;
    c->world.x = 0.0f; c->world.y = 1.0f; c->world.z = 0.0f;

    Vec3 tar = { c->front.x, 0.0f, c->front.z };
    if (tar.z >= 0.0f) {
        if (tar.x >= 0.0f) c->yaw = 360.f - TO_DEG(asinf(tar.z));
        else c->yaw = 180.f + TO_DEG(asinf(tar.z));
    } else {
        if (tar.x >= 0.0f) c->yaw = TO_DEG(asinf(-tar.z));
        else c->yaw = 180.f - TO_DEG(asinf(-tar.z));
    }
    c->pitch = -TO_DEG(asinf(c->front.y));

    // setCameraCallbacks(c);

    return cameraUpdateEvent(c);
}

void _cameraMoveForward(Camera_t *c)
{
    c->position.x += c->forward.x;
    c->position.z += c->forward.z;
}
void _cameraMoveBackward(Camera_t *c)
{
    c->position.x -= c->forward.x;
    c->position.z -= c->forward.z;
}
void _cameraMoveLeft(Camera_t *c) { vec3sub(&c->position, &c->right); }
void _cameraMoveRight(Camera_t *c) { vec3add(&c->position, &c->right); }
void _cameraMoveDown(Camera_t *c) { c->position.y -= c->velocity; }
void _cameraMoveUp(Camera_t *c) { c->position.y += c->velocity; }

void _camD_callback(void *c) { _cameraMoveDown((Camera_t *)c); }
void _camU_callback(void *c) { _cameraMoveUp((Camera_t *)c); }
void _camL_callback(void *c) { _cameraMoveLeft((Camera_t *)c); }
void _camR_callback(void *c) { _cameraMoveRight((Camera_t *)c); }
void _camF_callback(void *c) { _cameraMoveForward((Camera_t *)c); }
void _camB_callback(void *c) { _cameraMoveBackward((Camera_t *)c); }

 // z = exp(-(x^2+y^2)) * cos(0.25*x) * sin(y) * cos(2*(x^2+y^2)).
