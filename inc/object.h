#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H
#include "BufferData.h"
#include "Shader.h"
#include "types.h"
#include <GL/glew.h>
#include <stdlib.h>
#include <stdint.h>

#define RENDER_NIL 0
#define RENDER_COLOR 0x1
#define RENDER_TEXTURE 0x2
#define RENDER_HIGHLIGHT 0x4
#define RENDER_INVISIBLE 0x100
typedef unsigned long int renderflags_t; /* 8 bytes */

struct object { /* renderobject, entity */

    /* Transformation matrices. */
    mat4_t *mmatrix; /* model transform matrix */ /* 8 bytes       */
    mat4_t *wmatrix; /* world transform matrix */ /* 8 bytes .. 16 */


    /* Current position. Used to update transformation matrix. */
    vec3_t  pos;      /* 16 bytes, .... 32 */
    vec3_t  scale;    /* 16 bytes, .... 48 */
    euler_t angles;   /* 12 bytes, .... 60 */

    /* For collision detection */
    float   radius; /* Bounding radius */

    /* Can be used as criteria sort object/renderlists */
    float           dist_from_cam;
    int             render_order;
    renderflags_t   rflags;       /* Indicate how to render this object. */


    /* Render with a highlight list if true.
       Not fully implemented.  */
    bool_t highlight;
    bool_t cast_shadow;


    /* If true, won't be moved to another list during updates. */
    bool_t permanent;


    Material    material; /* Color and lighting data for rendering / shader. */
    vec3_t      color;

    /* Texture descriptors to pass to the shader at render time.  */
    GLuint texture;
    GLenum activeTexture;
    GLint  textureIndex;


    /* Bufferdata to set openGL to the correct vertex buffers/data
       for this object. */
    BufferData *bufferData;
    char *name; // What is this useful for

    struct node _node;
    struct node *node;

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

#endif /* RENDEROBJECT_H */
