#include "Scene.h"
#include "meshdata.h"
#include "texture.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

static void _initModels(Scene *s);
static bool _initSceneBufferData(Scene *s);
static const float DefaultYPos = 0.0f;

bool initScene(Scene *s)
{
    s->projectionMatrix = newMat4();
    s->viewMatrix = newMat4();
    Vec3 pos = (Vec3){ 0.0f, 0.0f, -10.0f };
    s->camera = newCamera(&pos);
    setCameraCallbacks(s->camera);
    cameraSetView(s->camera, s->viewMatrix);
    cameraSetPerspective(s->camera, s->projectionMatrix);

    if (!_initSceneBufferData(s))
        return false;

    s->colorList = newRenderList(RENDER_COLOR);
    s->textureList = newRenderList(RENDER_TEXTURE);
    s->highlightList = newRenderList(RENDER_HIGHLIGHT);
    s->noRenderList = newRenderList(RENDER_INVISIBLE);

    _initModels(s);

    s->camTarget = newSceneObject(&s->sphereData);
    vec3set(&s->camTarget->position, getCameraTarget(s->camera));
    s->camTarget->position = (Vec3){ 0.0f, 0.0f, 0.0f };
    s->camTarget->scale = (Vec3){ 0.3f, 0.3f, 0.3f };
    s->camTarget->color = (Vec3){ 0.0f, 1.0f, 0.0f };
    setTranslationMat4(s->camTarget->drawMatrix, &s->camTarget->position);
    addSceneObjectTexture(s->camTarget, 2);
    s->camTarget->permanent = true;
    pushSceneObject(s->textureList, s->camTarget);

    Vec3 *camPos = getCameraPosition(s->camera);
    updateCamDists(s->colorList, camPos);
    updateCamDists(s->textureList, camPos);
    updateCamDists(s->highlightList, camPos);

    s->frustum = newFrustum(s->viewMatrix, s->projectionMatrix);

    calcBoundingRadii(s->colorList);
    calcBoundingRadii(s->textureList);
    calcBoundingRadii(s->highlightList);
    return true;
}

void finalizeScene(Scene *s)
{
    destroyMat4(s->projectionMatrix);
    destroyMat4(s->viewMatrix);
    destroyCamera(s->camera);
    bufferDataDestroy(&s->cubeData);
    bufferDataDestroy(&s->texCubeData);
    bufferDataDestroy(&s->pyramidData);
    bufferDataDestroy(&s->landscapeData);
    bufferDataDestroy(&s->sphereData);
    destroyRenderList(s->colorList);
    destroyRenderList(s->textureList);
    destroyRenderList(s->highlightList);
    destroyRenderList(s->noRenderList);
    destroyFrustum(s->frustum);
}

void updateScene(Scene *s, bool needsUpdate)
{
    if (!needsUpdate)
        return;
    cameraUpdateEvent(s->camera);
    cameraSetView(s->camera, s->viewMatrix);
    cameraSetPerspective(s->camera, s->projectionMatrix);

    // Vec3 *camPos = getCameraPosition(s->camera);
    // updateCamDists(s->colorList, camPos);
    // updateCamDists(s->highlightList, camPos);
    // updateCamDists(s->textureList, camPos);

    Vec3 *targetPos = getCameraTarget(s->camera);
    vec3set(&s->camTarget->position, targetPos);
    setTranslationMat4(s->camTarget->drawMatrix, targetPos);
    scaleMat4(s->camTarget->drawMatrix, &s->camTarget->scale);


    bool intersection = false;
    if (checkPointInRadiusCollisions(s->colorList, targetPos) ||
        checkPointInRadiusCollisions(s->highlightList, targetPos) ||
        checkPointInRadiusCollisions(s->textureList, targetPos))
        intersection = true;

    if (intersection) {
        compareAndUpdateList(s->highlightList, s->colorList);
        compareAndUpdateList(s->highlightList, s->textureList);
    } else if (!isEmpty(s->highlightList)) {
        compareAndUpdateList(s->colorList, s->highlightList);
        compareAndUpdateList(s->textureList, s->highlightList);
    }

}

void _setMaterial(Material *dest, Material *src)
{
    vec3set(&dest->ambient, &src->ambient);
    vec3set(&dest->diffuse, &src->diffuse);
    vec3set(&dest->specular, &src->specular);
    dest->shininess = src->shininess;
}

static void _initModels(Scene *s)
{

    Material m = (Material){
        (Vec3){ 1.0f, 0.5f, 0.31f }, // ambient color
        (Vec3){ 1.0f, 0.5f, 0.31f }, // diffuse color
        (Vec3){ 0.5f, 0.5f, 0.50f }, // specular color
        32.0f // shininess
    };

    SceneObject *temp= newSceneObject(&s->landscapeData);
    addSceneObjectTexture(temp, 0);
    temp->position = (Vec3) { 0.0f, 0.0f, 10.0f };
    setRotXMat4(temp->drawMatrix, 90.0f);
    translateMat4(temp->drawMatrix, &temp->position);
    temp->permanent = true;
    temp->name = malloc(sizeof(char) * 100);
    strcpy(temp->name, "landscape");
    // memcpy(&temp->material, &m, sizeof(Material));
    _setMaterial(&temp->material, &m);

    pushSceneObject(s->textureList, temp);

    // pyramid
    {
        temp = newSceneObject(&s->pyramidData);
        temp->position = (Vec3){ 10.0f, 0.0f, 10.0f };
        temp->scale = (Vec3){ 4.0f, 4.0f, 4.0f };
        setTranslationMat4(temp->drawMatrix, &temp->position);
        scaleMat4(temp->drawMatrix, &temp->scale);
        temp->name = malloc(sizeof(char) * 100);
        strcpy(temp->name, "pyramid");
        pushSceneObject(s->colorList, temp);
        _setMaterial(&temp->material, &m);
    }

    // cube
    {
        temp = newSceneObject(&s->cubeData);
        temp->position = (Vec3){ 10.0f, DefaultYPos, 40.0f };
        temp->scale = (Vec3){ 3.0f, 3.0f, 3.0f };
        setTranslationMat4(temp->drawMatrix, &temp->position);
        scaleMat4(temp->drawMatrix, &temp->scale);
        temp->name = malloc(sizeof(char) * 100);
        strcpy(temp->name, "gray cube");
        pushSceneObject(s->colorList, temp);
        memcpy(&temp->material, &m, sizeof(Material));
    }

    // cube texture
    {
        temp = newSceneObject(&s->texCubeData);
        temp->position = (Vec3){ 30.0f, DefaultYPos, 5.0f };
        temp->scale = (Vec3){ 6.0f, 6.0f, 6.0f };
        setTranslationMat4(temp->drawMatrix, &temp->position);
        scaleMat4(temp->drawMatrix, &temp->scale);
        addSceneObjectTexture(temp, 1);
        temp->name = malloc(sizeof(char) * 100);
        strcpy(temp->name, "striped cube");
        pushSceneObject(s->textureList, temp);
        memcpy(&temp->material, &m, sizeof(Material));
    }

    // cube texture
    {
        temp = newSceneObject(&s->texCubeData);
        temp->position = (Vec3){ -30.0f, DefaultYPos, 5.0f };
        temp->scale = (Vec3){ 6.0f, 6.0f, 6.0f };
        setTranslationMat4(temp->drawMatrix, &temp->position);
        scaleMat4(temp->drawMatrix, &temp->scale);
        addSceneObjectTexture(temp, 1);
        temp->name = malloc(sizeof(char) * 100);
        strcpy(temp->name, "hl cube");
        // pushSceneObject(s->highlightList, temp);
        pushSceneObject(s->textureList, temp);
        memcpy(&temp->material, &m, sizeof(Material));
    }

    // sphere texture
    {
        temp = newSceneObject(&s->sphereData);
        temp->position = (Vec3){ 23.0f, 0.0f, 67.0f };
        temp->scale = (Vec3){ 7.0f, 7.0f, 7.0f };
        temp->color = (Vec3){ 1.0f, 0.0f, 0.0f };
        setTranslationMat4(temp->drawMatrix, &temp->position);
        scaleMat4(temp->drawMatrix, &temp->scale);
        addSceneObjectTexture(temp, 2);
        temp->name = malloc(sizeof(char) * 100);
        strcpy(temp->name, "spherical cube");
        pushSceneObject(s->textureList, temp);
        memcpy(&temp->material, &m, sizeof(Material));
    }

}

static bool _initSceneBufferData(Scene *s)
{
    bufferDataInitPrimitive(&s->cubeData, BDP_CUBE);
    bufferDataInitPrimitive(&s->texCubeData, BDP_TEX_CUBE);
    bufferDataInitPrimitive(&s->pyramidData, BDP_PYRAMID);
    if (!bufferDataInitFromFile(&s->landscapeData, findObjPath("grid")))
        exit(EXIT_FAILURE);
    // if (!bufferDataInitFromFile(&s->sphereData, findObjPath("sphere")))
    //     exit(EXIT_FAILURE);
    bufferDataInitPrimitive(&s->sphereData, BDP_TEX_SPHERE);
    return true;
}

void passViewMatrix(Scene *s, GLint uView)
{
    glUniformMatrix4fv(uView, 1, GL_FALSE, s->viewMatrix->data);
}

void passProjectionMatrix(Scene *s, GLint uProjection)
{
    glUniformMatrix4fv(uProjection, 1, GL_FALSE, s->projectionMatrix->data);
}

RenderMode sceneHasHighlightObjects(Scene *s)
{
    if (isEmpty(s->highlightList))
        return 0;
    return (getRenderListRoot(s->highlightList))->renderMode;
    // return s->highlightList->root->object->renderMode;
}
