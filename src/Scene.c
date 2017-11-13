#include "Scene.h"
#include "Frustum.h"
#include "meshdata.h"
#include "Camera.h"
#include "Mat4.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

static void _initModels(Scene *s);
static bool_t _initSceneBufferData(Scene *s);

void updateScene(Scene *s, bool_t needs_update)
{
    if (!needs_update) return;

    update_camera(s->camera);
    get_camera_view_matrix(s->camera, s->viewMatrix);
    get_camera_perspective_matrix(s->camera, s->projectionMatrix);
    Vec3 *targetPos = get_camera_target(s->camera);
    vec3set(&s->camTarget->position, targetPos);
    setTranslationMat4(s->camTarget->drawMatrix, targetPos);
    scaleMat4(s->camTarget->drawMatrix, &s->camTarget->scale);

    // updateFrustum(s->frustum, s->viewMatrix, s->projectionMatrix);
    // compareAndUpdateList(s->colorList,s->noRenderList);
    // compareAndUpdateList(s->textureList, s->noRenderList);
    // if (checkFrustumCollision(s->colorList, s->frustum) ||
    //     checkFrustumCollision(s->textureList, s->frustum) ||
    //     checkFrustumCollision(s->highlightColorList, s->frustum) ||
    //     checkFrustumCollision(s->highlightTextureList, s->frustum) ||
    //     checkFrustumCollision(s->noRenderList, s->frustum)) {

    //     compareAndUpdateList(s->noRenderList, s->colorList);
    //     compareAndUpdateList(s->noRenderList, s->textureList);
    //     printf("\n\n");
    // }

    if (checkPointInRadiusCollisions(s->colorList, s->camera) ||
        checkPointInRadiusCollisions(s->textureList, s->camera) ||
        checkPointInRadiusCollisions(s->highlightColorList, s->camera) ||
        checkPointInRadiusCollisions(s->highlightTextureList, s->camera)) {

        compareAndUpdateList(s->highlightColorList, s->colorList);
        compareAndUpdateList(s->highlightTextureList, s->textureList);

    } else if (!isEmpty(s->highlightColorList) || !isEmpty(s->highlightTextureList)) {

        compareAndUpdateList(s->colorList, s->highlightColorList);
        compareAndUpdateList(s->textureList, s->highlightTextureList);
    }
}


bool_t initScene(Scene *s)
{
    s->projectionMatrix = newMat4();
    s->viewMatrix = newMat4();

    // camera init
    {
        Vec3 pos = vec3construct(0.0f, 0.0f, -40.0f);
        s->camera = new_camera(&pos);
        // setCameraCallbacks(s->camera);
        init_camera_movement_control_callbacks(s->camera);
        get_camera_view_matrix(s->camera, s->viewMatrix);
        get_camera_perspective_matrix(s->camera, s->projectionMatrix);
        // cameraSetView(s->camera, s->viewMatrix);
        // cameraSetPerspective(s->camera, s->projectionMatrix);
    }

    if (!_initSceneBufferData(s))
        return no;

    s->colorList = newRenderList(RENDER_COLOR);
    s->textureList = newRenderList(RENDER_TEXTURE);
    s->highlightColorList = newRenderList(RENDER_HIGHLIGHT);
    s->highlightTextureList = newRenderList(RENDER_HIGHLIGHT);
    s->noRenderList = newRenderList(RENDER_INVISIBLE);

    _initModels(s);

    // Vec3 *camPos = getCameraPosition(s->camera);
    Vec3 *camPos = get_camera_position(s->camera);
    updateCamDists(s->colorList, camPos);
    updateCamDists(s->textureList, camPos);
    updateCamDists(s->highlightColorList, camPos);
    updateCamDists(s->highlightTextureList, camPos);

    s->frustum = newFrustum(s->viewMatrix, s->projectionMatrix);

    calcBoundingRadii(s->colorList);
    calcBoundingRadii(s->textureList);
    calcBoundingRadii(s->highlightColorList);
    calcBoundingRadii(s->highlightTextureList);

    return yes;
}

void finalizeScene(Scene *s)
{
    destroyMat4(s->projectionMatrix);
    destroyMat4(s->viewMatrix);
    destroy_camera(s->camera);

    bufferDataDestroy(&s->cubeData);
    bufferDataDestroy(&s->texCubeData);
    bufferDataDestroy(&s->pyramidData);
    bufferDataDestroy(&s->sphereData);
    // bufferDataDestroy(&s->landscapeData);

    destroyRenderList(s->noRenderList);
    destroyRenderList(s->highlightColorList);
    destroyRenderList(s->highlightTextureList);
    destroyRenderList(s->colorList);
    destroyRenderList(s->textureList);

    destroyFrustum(s->frustum);
}

void _setMaterial(Material *dest, Material *src)
{
    vec3set(&dest->ambient, &src->ambient);
    vec3set(&dest->diffuse, &src->diffuse);
    vec3set(&dest->specular, &src->specular);
    dest->shininess = src->shininess;
}

#define MAKE_TEXTURED_SCENE_OBJECT(t, qd, p0, p1, p2, sc, co, p, ti, n, tl) \
    t = newSceneObject(qd); \
    t->position = vec3construct((p0), (p1), (p2)); \
    t->scale = vec3construct(sc, sc, sc); \
    t->color = vec3construct(co, co, co); \
    t->permanent = p; \
    addSceneObjectTexture(t, ti); \
    t->name = malloc(sizeof(n) + 1); \
    strcpy(t->name, (n)); \
    t->material.ambient = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.diffuse = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.specular = vec3construct(1.f, 1.f, 1.f); \
    t->material.shininess = 32.f; \
    setTranslationMat4(t->drawMatrix, &t->position); \
    scaleMat4(t->drawMatrix, &t->scale); \
    pushRenderList(tl, t)

#define MAKE_COLOR_SCENE_OBJECT(t, qd, p0, p1, p2, sc, co, p, n, tl) \
    t = newSceneObject(qd); \
    t->position = vec3construct((p0), (p1), (p2)); \
    t->scale = vec3construct(sc, sc, sc); \
    t->color = vec3construct(co, co, co); \
    t->permanent = p; \
    t->name = malloc(sizeof(n) + 1); \
    strcpy(t->name, (n)); \
    t->material.ambient = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.diffuse = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.specular = vec3construct(0.5f, 0.5f, 0.5f); \
    t->material.shininess = 32.f; \
    setTranslationMat4(t->drawMatrix, &t->position); \
    scaleMat4(t->drawMatrix, &t->scale); \
    pushRenderList(tl, t)

static void _initModels(Scene *s)
{

    SceneObject *temp;
    // pyramid
    {
        BufferData *bd = &s->pyramidData;
        MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f,  0.f,  80.f, 4.f, 1.f, false, "pyramid0", s->colorList);
        MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f, 20.f, 100.f, 4.f, 1.f, false, "pyramid1", s->colorList);
        MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f, 40.f, 200.f, 4.f, 1.f, false, "pyramid2", s->colorList);
    }

    // cube
    {
        BufferData *bd = &s->cubeData;
        MAKE_COLOR_SCENE_OBJECT(temp, bd, 50.f, 0.f, 200.f, 10.f, 1.f, false, "color cube 0", s->colorList);
    }

    // cube texture
    {
        const BufferData *bd = &s->texCubeData;
        MAKE_TEXTURED_SCENE_OBJECT(temp, bd, -50.f, 0.0f, 200.f, 10.f, 1.f, false, 0, "striped cube0", s->textureList);
        MAKE_TEXTURED_SCENE_OBJECT(temp, bd,  50.f, 0.0f, 100.f, 10.f, 1.f, false, 1, "striped cube1", s->textureList);
        MAKE_TEXTURED_SCENE_OBJECT(temp, bd, -50.f, 0.0f, 100.f, 10.f, 1.f, false, 1, "striped cube2", s->textureList);
    }

    // sphere texture
    // camera target
    {
        const BufferData *bd = &s->sphereData;
        MAKE_TEXTURED_SCENE_OBJECT(temp, bd, 0.f, 0.f, 100.f, 10.f, 1.f, false, 1, "sphere0", s->textureList);
        MAKE_TEXTURED_SCENE_OBJECT(s->camTarget, bd, 0.f, 0.f, 0.f, 0.3f, 1.f, true, 1, "cam target", s->textureList);
    }

    // quad texture
    {
        const BufferData *bd = &s->quadData;
        MAKE_TEXTURED_SCENE_OBJECT(temp, bd, 0.f, 0.f, 0.f, 10.f, 1.f, true, 2, "quad0", s->textureList);
    }

}

static bool_t _initSceneBufferData(Scene *s)
{
    bufferDataInitPrimitive(&s->cubeData, BDP_CUBE);
    bufferDataInitPrimitive(&s->texCubeData, BDP_TEX_CUBE);
    bufferDataInitPrimitive(&s->pyramidData, BDP_PYRAMID);
    bufferDataInitPrimitive(&s->quadData, BDP_QUAD | BDP_W_TEXTURE);
    // if (!bufferDataInitFromFile(&s->landscapeData, findObjPath("grid")))
    //     exit(EXIT_FAILURE);
    // if (!bufferDataInitFromFile(&s->sphereData, findObjPath("sphere")))
    //     exit(EXIT_FAILURE);
    bufferDataInitPrimitive(&s->sphereData, BDP_TEX_SPHERE);

    return yes;
}

int sceneHasHighlightObjects(Scene *s)
{
    if (isEmpty(s->highlightColorList) && isEmpty(s->highlightTextureList))
        return 0;
    return 1;
    // return s->highlightList->root->object->renderMode;
}
