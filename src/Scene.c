#include "Scene.h"
#include "meshdata.h"
#include "vecmath.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

static void _initModels(Scene *s);
static bool_t _initSceneBufferData(Scene *s);

void scene_update(Scene *s, bool_t needs_update)
{

    setTranslationMat4(s->obj->drawMatrix, &s->obj->position);
    scaleMat4(s->obj->drawMatrix, &s->obj->scale);
    // mat4_rotate_x(s->obj->drawMatrix, s->camera.angles->pitch);
    // mat4_rotate_y(s->obj->drawMatrix, s->camera.angles->yaw);
    quat_t q;
    quat_rotation_from_vector(&q, (vec3_t *)s->camera.angles, s->camera.pos->z);
    mat4_rot_from_quat(s->obj->worldMatrix, &q);
    mat4_mul(s->obj->drawMatrix, s->obj->worldMatrix);


    if (!needs_update) return;

    camera_update(&s->camera);
    camera_get_view_matrix(&s->camera, s->viewMatrix);
    camera_get_perspective_matrix(&s->camera, s->projectionMatrix);
    vec3_t *targetPos = camera_get_target(&s->camera);

    vec3set(&s->camTarget->position, targetPos);
    setTranslationMat4(s->camTarget->drawMatrix, targetPos);
    scaleMat4(s->camTarget->drawMatrix, &s->camTarget->scale);

    if (renderlist_has_point_radius_collisions(s->colorList, &s->camera) ||
        renderlist_has_point_radius_collisions(s->textureList, &s->camera) ||
        renderlist_has_point_radius_collisions(s->highlightColorList,
            &s->camera) ||
        renderlist_has_point_radius_collisions(s->highlightTextureList,
            &s->camera)) {

        renderlist_compare_and_update(s->highlightColorList, s->colorList);
        renderlist_compare_and_update(s->highlightTextureList, s->textureList);

    } else if (!renderlist_is_empty(s->highlightColorList) ||
        !renderlist_is_empty(s->highlightTextureList)) {

        renderlist_compare_and_update(s->colorList, s->highlightColorList);
        renderlist_compare_and_update(s->textureList, s->highlightTextureList);
    }
}


bool_t scene_init(Scene *s)
{
    s->projectionMatrix = newMat4();
    s->viewMatrix = newMat4();

    { // camera init
        vec3_t pos = vec3_construct(0.0f, 0.0f, -40.0f);
        camera_init(&s->camera, &pos);
        camera_init_movement_control_callbacks(&s->camera);
        camera_get_view_matrix(&s->camera, s->viewMatrix);
        camera_get_perspective_matrix(&s->camera, s->projectionMatrix);
    }

    if (!_initSceneBufferData(s))
        return no;

    s->colorList = renderlist_create(RENDER_COLOR);
    s->textureList = renderlist_create(RENDER_TEXTURE);
    s->highlightColorList = renderlist_create(RENDER_HIGHLIGHT);
    s->highlightTextureList = renderlist_create(RENDER_HIGHLIGHT);
    s->noRenderList = renderlist_create(RENDER_INVISIBLE);

    _initModels(s);

    vec3_t *cam_pos = camera_get_pos(&s->camera);
    renderlist_update_cam_dists(s->colorList, cam_pos);
    renderlist_update_cam_dists(s->textureList, cam_pos);
    renderlist_update_cam_dists(s->highlightColorList, cam_pos);
    renderlist_update_cam_dists(s->highlightTextureList, cam_pos);

    // s->frustum = newFrustum(s->viewMatrix, s->projectionMatrix);

    renderlist_calc_bounding_radii(s->colorList);
    renderlist_calc_bounding_radii(s->textureList);
    renderlist_calc_bounding_radii(s->highlightColorList);
    renderlist_calc_bounding_radii(s->highlightTextureList);

    return yes;
}

void scene_finalize(Scene *s)
{
    destroyMat4(s->projectionMatrix);
    destroyMat4(s->viewMatrix);

    bufferDataDestroy(&s->cubeData);
    bufferDataDestroy(&s->texCubeData);
    bufferDataDestroy(&s->pyramidData);
    bufferDataDestroy(&s->sphereData);

    renderlist_destroy(s->noRenderList);
    renderlist_destroy(s->highlightColorList);
    renderlist_destroy(s->highlightTextureList);
    renderlist_destroy(s->colorList);
    renderlist_destroy(s->textureList);

    // destroyFrustum(s->frustum);
}

#define MAKE_TEXTURED_SCENE_OBJECT(t, qd, p0, p1, p2, sc, co, p, ti, n, tl) \
    t = newSceneObject(qd); \
    t->position = vec3construct((p0), (p1), (p2)); \
    t->scale = vec3construct(sc, sc, sc); \
    t->color = vec3construct(co, co, co); \
    t->permanent = p; \
    sceneobject_add_texture(t, ti); \
    t->name = malloc(sizeof(n) + 1); \
    strcpy(t->name, (n)); \
    t->material.ambient = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.diffuse = vec3construct(1.f, 0.5f, 0.31f); \
    t->material.specular = vec3construct(1.f, 1.f, 1.f); \
    t->material.shininess = 32.f; \
    setTranslationMat4(t->drawMatrix, &t->position); \
    scaleMat4(t->drawMatrix, &t->scale); \
    renderlist_push(tl, t)

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
    renderlist_push(tl, t)

static void _initModels(Scene *s)
{
    SceneObject *temp;
    BufferData *bd;

    /* pyramids */
    bd = &s->pyramidData;
    MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f,  0.f,  80.f, 4.f, 1.f, false,
        "pyramid0", s->colorList);
    MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f, 20.f, 100.f, 4.f, 1.f, false,
        "pyramid1", s->colorList);
    MAKE_COLOR_SCENE_OBJECT(temp, bd, 10.f, 40.f, 200.f, 4.f, 1.f, false,
        "pyramid2", s->colorList);
    s->obj = temp;

    /* cubes */
    bd = &s->cubeData;
    MAKE_COLOR_SCENE_OBJECT(temp, bd, 50.f, 0.f, 200.f, 10.f, 1.f, false,
        "color cube 0", s->colorList);

    /* cube texture */
    bd = &s->texCubeData;
    MAKE_TEXTURED_SCENE_OBJECT(temp, bd, -50.f, 0.0f, 200.f, 10.f, 1.f,
        false, 0, "striped cube0", s->textureList);
    MAKE_TEXTURED_SCENE_OBJECT(temp, bd,  50.f, 0.0f, 100.f, 10.f, 1.f,
        false, 1, "striped cube1", s->textureList);
    MAKE_TEXTURED_SCENE_OBJECT(temp, bd, -50.f, 0.0f, 100.f, 10.f, 1.f,
        false, 1, "striped cube2", s->textureList);

    /* sphere texture */
    bd = &s->sphereData;
    MAKE_TEXTURED_SCENE_OBJECT(temp, bd, 0.f, 0.f, 100.f, 10.f, 1.f,
        false, 1, "sphere0", s->textureList);
    // camera target
    MAKE_TEXTURED_SCENE_OBJECT(s->camTarget, bd, 0.f, 0.f, 0.f, 0.3f, 1.f,
        true, 1, "cam target", s->textureList);

    /* quad texture */
    bd = &s->quadData;
    MAKE_TEXTURED_SCENE_OBJECT(temp, bd, 0.f, 0.f, 0.f, 10.f, 1.f,
        true, 2, "quad0", s->textureList);

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

int scene_has_highlight_objects(Scene *s)
{
    return !(renderlist_is_empty(s->highlightColorList) &&
            renderlist_is_empty(s->highlightTextureList));
    // if (renderlist_is_empty(s->highlightColorList) &&
    //         renderlist_is_empty(s->highlightTextureList))
    //     return 0;
    // return 1;
}
