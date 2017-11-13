#ifndef BUFFERDAT_H
#define BUFFERDAT_H
#include "types.h"
#include <GL/glew.h>
#define A_POSITION 0
#define A_NORMALS 1
#define A_UVS 2

typedef enum BufferDataPrim_t {
    BDP_NIL         = 0x000,

    BDP_CUBE        = 0x001,
    BDP_PYRAMID     = 0x002,
    BDP_SPHERE      = 0x004,
    BDP_QUAD        = 0x008,

    BDP_WO_TEXTURE  = 0x0ff,
    BDP_W_TEXTURE   = 0x100,
    BDP_TEX_CUBE    = 0x101,
    BDP_TEX_PYRAMID = 0x102,
    BDP_TEX_SPHERE  = 0x104,
    BDP_MAX         = 0xffff,
} BufferDataPrim_t;

typedef struct PickingData {
    float data[4];
    GLuint fbo;
    GLuint texture;
    GLuint depthTexture;
} PickingData;

typedef struct BufferData {
    GLuint vao;
    GLuint vbo;
    GLuint nbo;
    GLuint ebo;
    GLuint uvo;

    GLsizeiptr vboSize;
    GLsizeiptr nboSize;
    GLsizeiptr eboSize;
    GLsizeiptr uvoSize;

    GLsizei elementCount;
    GLint dimensions;
    GLsizei stride;
    bool_t withTexture;
} BufferData;

typedef struct FramebufferData {
    GLuint fbo;
    GLuint txo;
    GLuint rbo;

    int fb_w;
    int fb_h;
    size_t texture_index;
} FramebufferData;

FramebufferData *framebufferInit(FramebufferData *fb);


// BufferData *newBufferData(GLfloat *vertices, GLfloat *normals, GLuint *indices, GLfloat *uvs,
//     size_t vLen, size_t nLen, size_t iLen, size_t uvLen);
BufferData *bufferDataInit(BufferData *b,
    GLfloat *vertices, GLfloat *normals, GLuint *indices, GLfloat *uvs,
    size_t vLen, size_t nLen, size_t iLen, size_t uvLen);

BufferData *bufferDataInitPrimitive(BufferData *b, BufferDataPrim_t bdp);
BufferData *bufferDataInitFromFile(BufferData *b, const char *path);

void bufferDataDestroy(BufferData *b);
void bufferDataUseVbo(BufferData *m);
void bufferDataUse(BufferData *m);
void bufferDataFinish(void);
void bufferDataDraw(BufferData *m);

PickingData *pickingInit(PickingData *p, int windowWidth, int windowHeight);
PickingData *pickingEnable(PickingData *p);
PickingData *pickingDisable(PickingData *p);
PickingData *pickingReadPixel(PickingData *p, int x, int y);
#endif /* BUFFERDAT_H */
