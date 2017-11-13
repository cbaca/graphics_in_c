
#include "SceneObject.h"
#include "texture.h"
#include "vecmath.h"
#include <stdio.h>
#include <math.h>

static SceneObject *_initSceneObject(SceneObject *sn, const BufferData *data);

SceneObject *newSceneObject(const BufferData *data)
{
    SceneObject *sn = malloc(sizeof(SceneObject));
    sn->permanent = no;
    sn->name = NULL;
    return _initSceneObject(sn, data);
}

SceneObject *newSceneObjectFromSceneObject(SceneObject *src)
{
    SceneObject *sn = malloc(sizeof(SceneObject));

    sn->renderMode = src->renderMode;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    vec3set(&sn->position, &src->position);
    vec3set(&sn->scale, &src->scale);
    vec3set(&sn->color, &src->color);
    sn->permanent = no;
    sn->name = NULL;

    return sn;
}

void destroySceneObject(SceneObject *sn)
{
    destroyMat4(sn->modelMatrix);
    destroyMat4(sn->worldMatrix);
    destroyMat4(sn->drawMatrix);
    if (sn->name != NULL)
        free(sn->name);
}

void calcBoundingRadius(SceneObject *sn)
{
    if (!sn) return;
    sn->boundingRadius = vec3length(&sn->scale);
}

void updateObjectDistFromCam(SceneObject *sn, Vec3 *camPos)
{
    Vec3 p = vec3copy(&sn->position);
    sn->distFromCam = vec3dot(&p, camPos);
}

void setSceneObjectWorldFromSceneObject(SceneObject *dest, SceneObject *src)
{
    setMat4(dest->worldMatrix, src->worldMatrix);
}

void setSceneObjectWorldFromModel(SceneObject *so)
{
    setMat4(so->worldMatrix, so->modelMatrix);
}

void updateSceneObjectWorldMatrix(SceneObject *so)
{
    mulMat4(so->worldMatrix, so->modelMatrix);
}

void updateSceneObjectMatrices(SceneObject *sn)
{
    setMat4(sn->drawMatrix, sn->worldMatrix);
    scaleMat4(sn->drawMatrix, &sn->scale);
}

void addSceneObjectTexture(SceneObject *sn, size_t index)
{
    Texture *t = getTexture(index);
    sn->texture = t->tex;
    sn->activeTexture = t->activeTexture;
    sn->textureIndex = t->index;
    sn->renderMode = RENDER_TEXTURE;
}

int compareCameraDists(SceneObject *a, SceneObject *b)
{
    float dist_a = fabsf(a->distFromCam);
    float dist_b = fabsf(b->distFromCam);
    return dist_a > dist_b ? 1 : dist_b > dist_a ? -1 : 0;
}

static SceneObject *_initSceneObject(SceneObject *sn, const BufferData *data)
{
    sn->renderMode = RENDER_COLOR;
    sn->name = NULL;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    sn->position = vec3construct(0.0f, 0.0f, 0.0f);
    sn->scale = vec3construct(1.0f, 1.0f, 1.0f);
    sn->color = vec3construct(0.5f, 0.5f, 0.5f);
    sn->bufferData = (BufferData *)data;
    sn->permanent = no;
    return sn;
}

bool_t pointInSceneObjectRadius(SceneObject *so, Vec3 *pt)
{
    if (pointInSphere(pt, &so->position, so->boundingRadius) && !so->permanent) {
        so->renderMode |= RENDER_HIGHLIGHT;
        so->highLight = yes;
        return yes;
    }
    so->highLight = no;
    so->renderMode &= ~RENDER_HIGHLIGHT;
    return no;
}

