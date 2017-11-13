#include "BufferData.h"
#include "meshdata.h"
#include "texture.h"
// #include "types.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct multisample_buffer_t {
    GLuint fbo; // frame buffer object
    GLuint tex; // texture object
    GLuint rbo; // render buffer object
    GLsizei w, h;
} MultisampleBuffer;

MultisampleBuffer *_init_multisample_buffer(MultisampleBuffer *mb, WindowSize *ws)
{
    mb->w = (GLsizei)ws->w;
    mb->h = (GLsizei)ws->h;
    glGenTextures(1, &mb->tex);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, mb->tex);
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGB, mb->w, mb->h, GL_TRUE);

    glGenFramebuffers(1, &mb->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, mb->fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, mb->tex, 0);

    // renderbuffer
    // {
    //     glGenRenderbuffers(1, &mb->rbo);
    //     glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, ws->w, ws->h);
    //     glBindRenderbuffer(GL_RENDERBUFFER, 0);
    //     glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mb->rbo);
    //     glBindFramebuffer(GL_FRAMEBUFFER, 0);
    // }

    // texture
    // {
        // glGenTextures(1, &mb->texture);
        // glBindTexture(GL_TEXTURE_2D, mb->texture);
        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ws->w, ws->h, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mb->texture, 0);
    // }

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) return nil;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return mb;
}

void draw_multisample_buffer(MultisampleBuffer *mb)
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, mb->fbo);
    glDrawBuffer(GL_BACK);
    glBlitFramebuffer(0, 0, mb->w, mb->h, 0, 0, mb->w, mb->h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
}

BufferData *_bufferDataGenGLBuffers(BufferData *b, GLfloat *vertices, GLfloat *normals, GLuint *indices, GLfloat *uvs)
{
    /*
    glGenVertexArrays(1, &b->vao);
    glGenBuffers(1, &b->vbo);
    glGenBuffers(1, &b->ebo);

    glBindVertexArray(b->vao);
    glBindBuffer(GL_ARRAY_BUFFER, b->vbo);

    glBufferSubData(GL_ARRAY_BUFFER, 0, b->vboSize, vertices);
    glBufferSubData(GL_ARRAY_BUFFER, b->vboSize, b->nboSize, normals);

    if (b->withTexture) {
        glBufferSubData(GL_ARRAY_BUFFER, b->vboSize + b->nboSize, b->uvoSize, uvs);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, b->eboSize, indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
    */

    glGenVertexArrays(1, &b->vao);
    glGenBuffers(1, &b->vbo);
    glGenBuffers(1, &b->nbo);
    glGenBuffers(1, &b->ebo);
    if (b->withTexture) glGenBuffers(1, &b->uvo);
    glBindVertexArray(b->vao);

    glBindBuffer(GL_ARRAY_BUFFER, b->vbo);
    glBufferData(GL_ARRAY_BUFFER, b->vboSize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, b->nbo);
    glBufferData(GL_ARRAY_BUFFER, b->nboSize, normals, GL_STATIC_DRAW);

    if (b->withTexture)
        glBindBuffer(GL_ARRAY_BUFFER, b->uvo),
        glBufferData(GL_ARRAY_BUFFER, b->uvoSize, uvs, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, b->eboSize, indices, GL_STATIC_DRAW);
    glBindVertexArray(0);

    return b;
}

BufferData *_bufferDataInitFromMeshdata(BufferData *b, meshdata_t *md)
{
    return bufferDataInit(b, md->vertices, md->normals, md->indices, md->uvs,
        md->lenVertices, md->lenNormals, md->lenIndices, md->lenUvs);
}

BufferData *bufferDataInit(BufferData *b,
    GLfloat *vertices, GLfloat *normals, GLuint *indices, GLfloat *uvs,
    size_t vLen, size_t nLen, size_t iLen, size_t uvLen)
{
    b->dimensions = 3;
    b->stride = 3 * (GLsizei)sizeof(GLfloat);
    b->vboSize = (GLsizeiptr)(sizeof(GLfloat) * vLen);
    b->nboSize = (GLsizeiptr)(sizeof(GLfloat) * nLen);
    b->eboSize = (GLsizeiptr)(sizeof(GLuint) * iLen);
    b->elementCount = (GLsizei)iLen;
    if (uvLen > 0 && uvs != NULL) {
        b->uvoSize = (GLsizeiptr)(sizeof(GLfloat) * uvLen);
        b->withTexture = yes;
    } else {
        b->withTexture = no;
        b->uvoSize = 0;
    }

    return _bufferDataGenGLBuffers(b, vertices, normals, indices, uvs);
}

BufferData *bufferDataInitPrimitive(BufferData *b, BufferDataPrim_t bdp)
{
    b->withTexture = bdp & BDP_W_TEXTURE ? yes : no;
    bdp &= BDP_WO_TEXTURE;

    GLfloat *vertices, *normals, *uvs = NULL;
    GLuint *indices;
    size_t vLen, nLen, iLen, uvLen = 0;

    switch (bdp) {
        case BDP_CUBE:
            vertices = getCubeVertexArray(&vLen);
            normals = getCubeNormalArray(&nLen);
            indices = getCubeIndexArray(&iLen);
            if (b->withTexture)
                uvs = getCubeUVArray(&uvLen);
            break;
        case BDP_PYRAMID:
            vertices = getPyramidVertexArray(&vLen);
            normals = getPyramidNormalArray(&nLen);
            indices = getPyramidIndexArray(&iLen);
            if (b->withTexture)
                uvs = getPyramidUVArray(&uvLen);
            break;
        case BDP_SPHERE:
            vertices = getSphereVertexArray(&vLen);
            normals = getSphereNormalArray(&nLen);
            indices = getSphereIndexArray(&iLen);
            if (b->withTexture)
                uvs = getSphereUVArray(&uvLen);
            break;
        case BDP_QUAD:
            vertices = get_quad_vertex_array(&vLen);
            normals = get_quad_normal_array(&nLen);
            indices = get_quad_index_array(&iLen);
            if (b->withTexture)
                uvs = get_quad_uv_array(&uvLen);
            break;
        default:
            fprintf(stderr, "Erroneous primitive enum value 0x%x for BufferData\n", bdp);
            return NULL;
    }

    b->vboSize = (GLsizeiptr)(sizeof(GLfloat) * vLen);
    b->nboSize = (GLsizeiptr)(sizeof(GLfloat) * nLen);
    b->eboSize = (GLsizeiptr)(sizeof(GLuint) * iLen);
    b->uvoSize = (GLsizeiptr)(sizeof(GLfloat) * uvLen);
    b->elementCount = (GLsizei)iLen;
    b->dimensions = 3;
    b->stride = 3 * (GLsizei)sizeof(GLfloat);
    return _bufferDataGenGLBuffers(b, vertices, normals, indices, uvs);
}

BufferData *bufferDataInitFromFile(BufferData *b, const char *path)
{
    meshdata_t meshdata;
    if (!genMeshdataFromFile(path, &meshdata)) {
        fprintf(stderr, "Failed to generate meshdata from file: %s\n", path);
        return NULL;
    }
    _bufferDataInitFromMeshdata(b, &meshdata);
    meshdata_destroy(&meshdata);
    return b;
}

void bufferDataDestroy(BufferData *b)
{
    glDeleteVertexArrays(1, &b->vao);
    glDeleteBuffers(1, &b->vbo);
    glDeleteBuffers(1, &b->nbo);
    if (b->uvoSize)
        glDeleteBuffers(1, &b->uvo);
    glDeleteBuffers(1, &b->ebo);
}

void bufferDataUseVbo(BufferData *m)
{
    glBindVertexArray(m->vao);
    glBindBuffer(GL_ARRAY_BUFFER, m->vbo);
    glVertexAttribPointer(A_POSITION, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glEnableVertexAttribArray(A_POSITION);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->ebo);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

static const GLsizei SIZEOF_FLOAT_2X = 2 * (GLsizei)sizeof(GLfloat);
void bufferDataUse(BufferData *m)
{
    /*
    glBindVertexArray(m->vao);
    glBindBuffer(GL_ARRAY_BUFFER, m->vbo);
    glVertexAttribPointer(A_POSITION, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glVertexAttribPointer(A_NORMALS, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)m->vboSize);
    if (m->withTexture)
        glVertexAttribPointer(A_UVS, 2, GL_FLOAT, GL_FALSE, SIZEOF_FLOAT_2X, (void *)(m->vboSize + m->nboSize));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->ebo);
    */

    glBindVertexArray(m->vao);
    glBindBuffer(GL_ARRAY_BUFFER, m->vbo);
    glVertexAttribPointer(A_POSITION, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glEnableVertexAttribArray(A_POSITION);
    glBindBuffer(GL_ARRAY_BUFFER, m->nbo);
    glVertexAttribPointer(A_NORMALS, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glEnableVertexAttribArray(A_NORMALS);

    if (m->withTexture) {
        glBindBuffer(GL_ARRAY_BUFFER, m->uvo);
        glVertexAttribPointer(A_UVS, 2, GL_FLOAT, GL_FALSE, SIZEOF_FLOAT_2X, (void *)0);
        glEnableVertexAttribArray(A_UVS);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->ebo);
}

/*
void bufferDataUseTex(BufferData *m)
{
    glBindVertexArray(m->vao);
    glBindBuffer(GL_ARRAY_BUFFER, m->vbo);
    glVertexAttribPointer(A_POSITION, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glEnableVertexAttribArray(A_POSITION);
    glBindBuffer(GL_ARRAY_BUFFER, m->nbo);
    glVertexAttribPointer(A_NORMALS, m->dimensions, GL_FLOAT, GL_FALSE, m->stride, (void *)0);
    glEnableVertexAttribArray(A_NORMALS);

    glBindBuffer(GL_ARRAY_BUFFER, m->uvo);
    glVertexAttribPointer(A_UVS, m->dimensions, GL_FLOAT, GL_FALSE, 2 * (GLsizei)sizeof(GLfloat), (void *)0);
    glEnableVertexAttribArray(A_UVS);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->ebo);
}
*/

void bufferDataFinish(void)
{
    glBindVertexArray(0);
}

void bufferDataDraw(BufferData *m)
{
    glDrawElements(GL_TRIANGLES, m->elementCount, GL_UNSIGNED_INT, 0);
}

PickingData *pickingInit(PickingData *p, int windowWidth, int windowHeight)
{
    glGenFramebuffers(1, &p->fbo);
    glGenTextures(1, &p->texture);
    glGenTextures(1, &p->depthTexture);

    glBindFramebuffer(GL_FRAMEBUFFER, p->fbo);

    glBindTexture(GL_TEXTURE_2D, p->texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, windowWidth, windowHeight, 0, GL_RGB, GL_FLOAT, NULL);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, p->texture, 0);

    glBindTexture(GL_TEXTURE_2D, p->depthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, windowWidth, windowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, p->depthTexture, 0);

    glReadBuffer(GL_NONE);

    glDrawBuffer(GL_COLOR_ATTACHMENT0);

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    if (status != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "Error initializing framebuffer memory");
        return NULL;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return p;
}

PickingData *pickingEnable(PickingData *p)
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, p->fbo);
    return p;
}

PickingData *pickingDisable(PickingData *p)
{
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    return p;
}

PickingData *pickingReadPixel(PickingData *p, int x, int y)
{
    glBindFramebuffer(GL_READ_FRAMEBUFFER, p->fbo);
    glReadBuffer(GL_COLOR_ATTACHMENT0);

    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, p->data);

    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    return p;
}
