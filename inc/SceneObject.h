#ifndef SCENENODE_H
#define SCENENODE_H
#include "BufferData.h"
#include "Shader.h"
#include "types.h"
#include <GL/glew.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct SceneObject SceneObject;

// #define RENDER_ERROR     0x0000
// #define RENDER_COLOR     0x0001
// #define RENDER_TEXTURE   0x0002
// #define RENDER_HIGHLIGHT 0x0004
// #define NO_RENDER        0x0008
// #define MAX_RENDER_TYPE  0x0010
enum {
    NO_RENDER = 0,
    RENDER_COLOR =     0x0001,
    RENDER_TEXTURE =   0x0002,
    RENDER_HIGHLIGHT = 0x0004,
    RENDER_INVISIBLE = 0x0100,
};

typedef int32_t RenderMode;

struct SceneObject {
    // header
    RenderMode renderMode;

    // physics
    mat4_t *modelMatrix;
    mat4_t *worldMatrix;
    mat4_t *drawMatrix;

    vec3_t position;
    vec3_t scale;
    // quat_t rot;

    float distFromCam;
    float boundingRadius;
    vec3_t boundingBox[3];
    bool_t highLight;
    bool_t permanent;


    // appearance
    Material material;
    vec3_t color;

    GLuint texture;
    GLenum activeTexture;
    GLint textureIndex;

    BufferData *bufferData;
    char *name; // What is this useful for
};

SceneObject *newSceneObject(const BufferData *data);
SceneObject *newSceneObjectFromSceneObject(SceneObject *src);
void destroySceneObject(SceneObject *sn);

/*
 * update
 */
int compareCameraDists(SceneObject *a, SceneObject *b);

/* */
void sceneobject_add_texture(SceneObject *sn, size_t index);

/* */
bool_t pointInSceneObjectRadius(SceneObject *so, vec3_t *pt);

/*
void updateSceneObjectWorldMatrix(SceneObject *sn)
{
    mulMat4(so->worldMatrix, so->modelMatrix);
}
void updateSceneObjectMatrices(SceneObject *sn)
{
    setMat4(sn->drawMatrix, sn->worldMatrix);
    scaleMat4(sn->drawMatrix, &sn->scale);
}
static void setSceneObjectWorldFromSceneObject(SceneObject *dest,
    SceneObject *src)
{
    setMat4(dest->worldMatrix, src->worldMatrix);
}
static void setSceneObjectWorldFromModel(SceneObject *so)
{
    setMat4(so->worldMatrix, so->modelMatrix);
}
*/


#endif /* SCENENODE_H */
