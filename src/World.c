#include "World.h"
#include "Camera.h"
#include "Shader.h"
#include <GL/glew.h>
#include <math.h>
#include <assert.h>

#include <stdio.h>
// #define LC_LATE_SUNSET  1.000f, 0.576f, 0.161f
// #define LC_MID_SUNSET   1.000f, 0.773f, 0.561f
// #define LC_EARLY_SUNSET 1.000f, 0.839f, 0.667f
// #define LC_EVENING      1.000f, 0.945f, 0.878f
// #define LC_AFTERNOON    1.000f, 0.980f, 0.957f
// #define LC_HIGHNOON     1.000f, 1.000f, 0.984f
// #define LC_OUTRUN_PINK  0.855f, 0.439f, 0.839f

#define VEC3SET(v, a, b, c) \
    v.x = a; \
    v.y = b; \
    v.z = c;

void updateDirlightDirection(DirLight_t *dl, float inc);
void updateDirlightColor(DirLight_t *dl, float inc);

float *getLightDirection(World_t *w)
{
    return (float *)&w->dirLight.direction;
}

void finalizeWorld(World_t *w)
{
    assert(w);
}

World_t *initWorld(World_t *w)
{
    VEC3SET(w->dirLight.color, 0.1f, 1.0f, 0.984f);
    VEC3SET(w->dirLight.direction, 0.3f, -1.0f, 1.0f);
    w->dirLight.ambientIntensity = 0.5f;
    w->dirLight.diffuseIntensity = 1.0f;
    return w;
}

void worldUpdate(World_t *w, float deltaTime)
{
    float tmp = deltaTime * 0.2f;
    w->lastTime += tmp;
    w->deltaTime = tmp;
    updateDirlightDirection(&w->dirLight, w->lastTime);
    updateDirlightColor(&w->dirLight, w->lastTime);
}

void updateDirlightDirection(DirLight_t *dl, float inc)
{
    float cur = cosf(inc);
    float cur2 = (sinf(inc) * 0.5f + 0.5f) * 0.5f;
    dl->direction.y = cur;
    dl->direction.z = cur2;
}

void updateDirlightColor(DirLight_t *dl, float inc)
{
    float cur = (sinf(inc) * 0.5f + 0.5f) * 0.2f + 0.1f;
    dl->color.x = cur;
    dl->color.y = cur;
    dl->color.z = cur + 0.2f;
}

float *getWorldBGColor(World_t *w)
{
    return (float *)&w->dirLight.color;
}

