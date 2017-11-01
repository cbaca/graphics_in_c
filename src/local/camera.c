#include "camera.h"
#include "Backend.h"

/*
Camera_t *_cameraUpdateFront(Camera_t *c)
{
    const float yaw = TO_RAD(c->yaw);
    const float pitch = TO_RAD(c->pitch);
    const float cospitch = cosf(pitch);
    Vec3 f = { cosf(yaw) * cospitch, sinf(pitch), sinf(yaw) * cospitch };
    vec3set(&c->front, vec3normalize(&f));
    vec3normalize(vec3cross(vec3set(&c->right, &c->front), &c->world));
    vec3normalize(vec3cross(vec3set(&c->up, &c->right), &c->front));
    return c;
}
*/

Camera_t *_cameraInit(Camera_t *c, Vec3 *pos, float x, float y)
{
    // c->position.x = -10.0f; c->position.y = 0.0f; c->position.z = 0.0f;
    c->yaw = 0.0f;
    c->pitch = 0.0f;
    c->velocity = 0.6f;
    c->sensitivity = 0.2f;
    c->fov = 45.0f;
    c->far = 1000.0f;
    c->near = 0.1f;

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

    return cameraUpdateEvent(c, x, y);
}

void _cameraMoveForward(Camera_t *c)
{
    float y = c->position.y;
    Vec3 tmp;
    vec3add(&c->position, vec3multScalar(vec3set(&tmp, &c->front), c->velocity));
    c->position.y = y;
}
void _cameraMoveBackward(Camera_t *c)
{
    float y = c->position.y;
    Vec3 tmp;
    vec3sub(&c->position, vec3multScalar(vec3set(&tmp, &c->front), c->velocity));
    c->position.y = y;
}
void _cameraMoveLeft(Camera_t *c)
{
    Vec3 tmp;
    vec3sub(&c->position, vec3multScalar(vec3set(&tmp, &c->right), c->velocity));
}
void _cameraMoveRight(Camera_t *c)
{
    Vec3 tmp;
    vec3add(&c->position, vec3multScalar(vec3set(&tmp, &c->right), c->velocity));
}
void _cameraMoveDown(Camera_t *c) { c->position.y -= c->velocity; }
void _cameraMoveUp(Camera_t *c) { c->position.y += c->velocity; }

void _camD_callback(void *c) { _cameraMoveDown((Camera_t *)c); }
void _camU_callback(void *c) { _cameraMoveUp((Camera_t *)c); }
void _camL_callback(void *c) { _cameraMoveLeft((Camera_t *)c); }
void _camR_callback(void *c) { _cameraMoveRight((Camera_t *)c); }
void _camF_callback(void *c) { _cameraMoveForward((Camera_t *)c); }
void _camB_callback(void *c) { _cameraMoveBackward((Camera_t *)c); }
