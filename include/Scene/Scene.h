#ifndef SCENEOBJ_H
#define SCENEOBJ_H
#include "RenderList.h"
#include "Camera.h"
#include "Frustum.h"
#include "Shader.h"

typedef struct Scene {
    // gl array buffers
    BufferData sphereData;
    BufferData cubeData;
    BufferData texCubeData;
    BufferData pyramidData;
    BufferData landscapeData;

    // model/mesh data structures
    RenderList *colorList;
    RenderList *textureList;
    RenderList *highlightList;
    RenderList *noRenderList;
    RenderList *allObjectsList;

    // camera controls and calculations
    Camera_t *camera;
    SceneObject *camTarget;
    Frustum *frustum;

    Mat4 *projectionMatrix;
    Mat4 *viewMatrix;

} Scene;

bool initScene(Scene *s);
void updateVisibility(Scene *s);
void finalizeScene(Scene *s);
void updateScene(Scene *s, bool needsUpdate);
void passViewMatrix(Scene *s, GLint uView);
void passProjectionMatrix(Scene *s, GLint uProjection);
RenderMode sceneHasHighlightObjects(Scene *s);

// void drawSceneColor(Scene *s, GLint uModel, GLint uColor);
// void drawSceneColor(Scene *s, MaterialShader *sh, Vec3 *campos);
// void drawSceneHighlightColor(Scene *s, MaterialShader *sh, Vec3 *campos);
// void drawSceneTexture(Scene *s, GLint uModel, GLint uTexture);
// void drawSceneHighlightTexture(Scene *s, GLint uModel, GLint uTexture);
// void drawSceneHighlight(Scene *s, GLint uModel);

#endif // SCENEOBJ_H
