#ifndef SCENENODE_H
#define SCENENODE_H
#include "BufferData.h"
#include "Maths.h"
#include "Shader.h"
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

/*
struct ModelObject {
    Mat4 *modelMatrix;
    Mat4 *worldMatrix;
    Mat4 *drawMatrix;

    Vec3 position;
    Vec3 scale;
    float boundingRadius;
    float distFromCam;
};
struct SceneObject {
    ModelObject *mo;
    RenderMode renderMode;
    Vec3 color;
    bool highLight;
    bool permanent;
    GLuint texture;
    GLenum activeTexture;
    GLint textureIndex;
    char *name; // What is this useful for
    BufferData *bufferData;
};
*/

typedef struct Material {
    Vec3 ambient; // color of the object under ambient lighting
    Vec3 diffuse; // color of the object under diffuse lighting
    Vec3 specular; // specular sets the color impact a specular light has on the object
    float shininess; // scattering/radius of specular lightlight
} Material;

struct SceneObject {
    // header
    RenderMode renderMode;

    // physics
    Mat4 *modelMatrix;
    Mat4 *worldMatrix;
    Mat4 *drawMatrix;

    Vec3 position;
    Vec3 scale;

    float boundingRadius;
    float distFromCam;
    bool highLight;
    bool permanent;


    // appearance
    Material material;
    Vec3 color;

    GLuint texture;
    GLenum activeTexture;
    GLint textureIndex;

    BufferData *bufferData;
    char *name; // What is this useful for
};

SceneObject *newSceneObject(BufferData *data);
SceneObject *newSceneObjectFromSceneObject(SceneObject *src);
void destroySceneObject(SceneObject *sn);
void calcBoundingRadius(SceneObject *sn);

/*
void drawHighlightSceneObject(SceneObject *so, GLint uModel);
void drawTextureSceneObject(SceneObject *so, GLint uModel, GLint uTexture);
// void drawColorSceneObject(SceneObject *so, GLint uModel, GLint uColor);
void drawColorSceneObject(SceneObject *so, MaterialShader *sh, Vec3 *campos);
void drawDebugColorSceneObject(SceneObject *so, GLint uModel, GLint uColor);
void drawSceneObject(SceneObject *sn, GLint uModel, GLint uColor);
*/

void updateObjectDistFromCam(SceneObject *sm, Vec3 *camPos);

void setSceneObjectWorldFromSceneObject(SceneObject *dest, SceneObject *src);
void setSceneObjectWorldFromModel(SceneObject *so);
void updateSceneObjectWorldMatrix(SceneObject *sn);
void updateSceneObjectMatrices(SceneObject *sn);

void addSceneObjectTexture(SceneObject *sn, size_t index);
int compareCameraDists(SceneObject *a, SceneObject *b);
bool pointInSceneObjectRadius(SceneObject *so, Vec3 *pt);

#endif /* SCENENODE_H */
