#ifndef SCENEOBJ_H
#define SCENEOBJ_H
#include "types.h"
#include "camera.h"
#include "RenderList.h"

typedef struct Scene {

    /*  data needed for context switching preloaded rendering data */
    BufferData      cubeData;
    BufferData      quadData;
    BufferData    sphereData;
    BufferData   texCubeData;
    BufferData   pyramidData;
    BufferData landscapeData;


    // model/mesh data structures
    RenderList *colorList;
    RenderList *textureList;
    RenderList *highlightColorList;
    RenderList *highlightTextureList;
    RenderList *noRenderList;

    // camera controls and calculations
    struct camera camera;
    SceneObject *camTarget;
    SceneObject *obj;

    mat4_t *viewMatrix;
    mat4_t *projectionMatrix;

} Scene;

bool_t  scene_init(Scene *s);

void    scene_finalize(Scene *s);

void    scene_update(Scene *s, bool_t needs_update);

int     scene_has_highlight_objects(Scene *s);

#endif // SCENEOBJ_H
