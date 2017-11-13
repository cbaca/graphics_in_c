#ifndef SCENEOBJ_H
#define SCENEOBJ_H
// #include "RenderList.h"
// #include "Camera.h"
// #include "Frustum.h"
// #include "Shader.h"
#include "types.h"
#include "RenderList.h"

typedef struct camera_t Camera;
typedef struct Frustum Frustum;
typedef struct Mat4 Mat4;

typedef struct Scene {
    // gl array buffers
    BufferData sphereData;
    BufferData cubeData;
    BufferData texCubeData;
    BufferData pyramidData;
    BufferData landscapeData;
    BufferData quadData;


    // model/mesh data structures
    RenderList *colorList;
    RenderList *textureList;
    RenderList *highlightColorList;
    RenderList *highlightTextureList;
    RenderList *noRenderList;

    // camera controls and calculations
    Camera *camera;
    SceneObject *camTarget;
    Frustum *frustum;

    Mat4 *viewMatrix;
    Mat4 *projectionMatrix;

} Scene;

bool_t initScene(Scene *s);

void updateVisibility(Scene *s);

void finalizeScene(Scene *s);

void updateScene(Scene *s, bool_t needs_update);

int sceneHasHighlightObjects(Scene *s);

// void drawSceneColor(Scene *s, GLint uModel, GLint uColor);
// void drawSceneColor(Scene *s, MaterialShader *sh, Vec3 *campos);
// void drawSceneHighlightColor(Scene *s, MaterialShader *sh, Vec3 *campos);
// void drawSceneTexture(Scene *s, GLint uModel, GLint uTexture);
// void drawSceneHighlightTexture(Scene *s, GLint uModel, GLint uTexture);
// void drawSceneHighlight(Scene *s, GLint uModel);

#endif // SCENEOBJ_H
