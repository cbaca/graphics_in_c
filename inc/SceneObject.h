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
    Mat4 *modelMatrix;
    Mat4 *worldMatrix;
    Mat4 *drawMatrix;

    Vec3 position;
    Vec3 scale;

    float distFromCam;
    float boundingRadius;
    Vec3 boundingBox[3];
    bool_t highLight;
    bool_t permanent;


    // appearance
    Material material;
    Vec3 color;

    GLuint texture;
    GLenum activeTexture;
    GLint textureIndex;

    BufferData *bufferData;
    char *name; // What is this useful for
};

SceneObject *newSceneObject(const BufferData *data);
SceneObject *newSceneObjectFromSceneObject(SceneObject *src);
void destroySceneObject(SceneObject *sn);

void calcBoundingBox(SceneObject *sn);
void calcBoundingRadius(SceneObject *sn);

void updateObjectDistFromCam(SceneObject *sm, Vec3 *camPos);

void setSceneObjectWorldFromSceneObject(SceneObject *dest, SceneObject *src);
void setSceneObjectWorldFromModel(SceneObject *so);
void updateSceneObjectWorldMatrix(SceneObject *sn);
void updateSceneObjectMatrices(SceneObject *sn);

void addSceneObjectTexture(SceneObject *sn, size_t index);
int compareCameraDists(SceneObject *a, SceneObject *b);
bool_t pointInSceneObjectRadius(SceneObject *so, Vec3 *pt);

#endif /* SCENENODE_H */
