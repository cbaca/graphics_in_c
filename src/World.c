#include "World.h"
#include "types.h"
#include "Camera.h"
#include "Shader.h"
#include "Vec3.h"
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

/**
Distance 	Constant 	Linear 	Quadratic
7 	    1.0 	0.7 	1.8
13 	    1.0 	0.35 	0.44
20 	    1.0 	0.22 	0.20
32 	    1.0 	0.14 	0.07
50 	    1.0 	0.09 	0.032
65 	    1.0 	0.07 	0.017
100 	1.0 	0.045 	0.0075
160 	1.0 	0.027 	0.0028
200 	1.0 	0.022 	0.0019
325 	1.0 	0.014 	0.0007
600 	1.0 	0.007 	0.0002
3250 	1.0 	0.0014 	0.000007
 */

void updateDirlightDirection(DirLight *dl, float inc);
void updateDirlightColor(DirLight *dl, float inc);

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
    w->dirLight.color = vec3construct(2.f, 2.f, 2.f);
    w->dirLight.direction = vec3construct(0.f, 0.f, -1.f);
    w->dirLight.ambientIntensity = 1.0f;
    w->dirLight.diffuseIntensity = 1.0f;

    w->pointLight.position = vec3construct(-50.f, 2.0f, 200.0f);
    w->pointLight.ambient = vec3construct(1.0f, 0.5f, 0.31f);
    w->pointLight.diffuse = vec3construct(1.0f, 0.5f, 0.31f);
    w->pointLight.specular = vec3construct(0.5f, 0.5f, 0.5f);
    w->pointLight.Kc = 1.0f;
    w->pointLight.Kl = 0.045f; // 0.09f;
    w->pointLight.Kq = 0.0075f; // 0.032f;

    w->spotLight.direction = (Vec3){ 0.6f, 2.0f, -0.2f };
    w->spotLight.ambientIntensity = 1.0f;
    w->spotLight.diffuseIntensity = 1.0f;
    w->spotLight.inner_cutoff = 0.91f;
    w->spotLight.outer_cutoff = 0.2530f;
    updateDirlightDirection(&w->dirLight, w->lastTime);
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

void updateDirlightDirection(DirLight *dl, float inc)
{
    float cur1 = cosf(inc);
    float cur2 = (sinf(inc) * 0.5f + 0.5f);
    dl->direction.y = cur2;
    dl->direction.z = cur1;
}

void updateDirlightColor(DirLight *dl, float inc)
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

