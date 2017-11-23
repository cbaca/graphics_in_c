
#include "shaders.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

SOAShader_t *shaderSetObject(Shader_t *s, const size_t id)
{
    assert(id < s->numObjects);
    s->curObject = id;
    glBindVertexArray(s->vao[id]);

    glBindBuffer(GL_ARRAY_BUFFER, s->vbo[id]);
    glVertexAttribPointer(s->aPosition, s->dimensions, GL_FLOAT, GL_FALSE, s->stride (void *)0);
    glEnableVertexAttribArray(s->aPosition);

    glBindBuffer(GL_ARRAY_BUFFER, s->cbo[id]);
    glVertexAttribPointer(s->aColor, s->dimensions, GL_FLOAT, GL_FALSE, s->stride (void *)0);
    glEnableVertexAttribArray(s->aColor);

    glBindBuffer(GL_ARRAY_BUFFER, s->uvo[id]);
    glVertexAttribPointer(s->aTexCoords, s->dimensions, GL_FLOAT, GL_FALSE, s->stride (void *)0);
    glEnableVertexAttribArray(s->aTexCoords);

    glBindBuffer(GL_ARRAY_BUFFER, s->nbo[id]);
    glVertexAttribPointer(s->aNormals, s->dimensions, GL_FLOAT, GL_FALSE, s->stride (void *)0);
    glEnableVertexAttribArray(s->aNormals);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->ebo);
}

Shader_t *setProgram(Shader_t *s, const size_t id)
{
    assert(id < s->numPrograms);
    glUseProgram(s->program[id]);
    s->curProgram = id;
    return s;
}

Shader_t *shaderAddObject(Shader_t *s,
    const GLfloat *vertices, const GLfloat *colors, const GLfloat *normals
    const GLfloat *texCoords, const GLuint *indices,
    const size_t numVertices, const size_t numColors, const size_t numNormals,
    const size_t numTexCoords, const size_t numIndices)
{
    if (!(++s->numObjects < s->maxObjects)) {
        fprintf(stderr, "Exceded limit of allocated object memory\n");
        return NULL;
    }

    size_t i = s->numObjects;

    glGenVertexArrays(1, &s->vao[i]);
    glGenBuffers(1, &s->vbo[i]);
    glGenBuffers(1, &s->cbo[i]);
    glGenBuffers(1, &s->uvo[i]);
    glGenBuffers(1, &s->nbo[i]);
    glGenBuffers(1, &s->ebo[i]);

    glBindVertexArray(s->vao[i]);

    glBindBuffer(GL_ARRAY_BUFFER, s->vbo);
    glBufferData(GL_ARRAY_BUFFER, s->vsize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, s->cbo);
    glBufferData(GL_ARRAY_BUFFER, s->csize, colors , GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, s->uvo);
    glBufferData(GL_ARRAY_BUFFER, s->tsize, texCoords, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, s->nbo);
    glBufferData(GL_ARRAY_BUFFER, s->nsize, normals, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, s->isize, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return s;
}

Shader_t *shaderInit(Shader_t *s, size_t numPrograms, size_t numObjects)
{
    s->maxPrograms = numPrograms;
    s->maxObjects = numObjects;
    s->curProgram = s->numPrograms = 0;
    s->curObject = s->numObjects = 0;

    s->program = malloc(sizeof(GLuint) * numPrograms); //  *program;
    s->vao = malloc(sizeof(GLuint) * numObjects); // ) * numObjects);
    s->vbo = malloc(sizeof(GLuint) * numObjects); //  *vbo;
    s->cbo = malloc(sizeof(GLuint) * numObjects); //  *cbo;
    s->ebo = malloc(sizeof(GLuint) * numObjects); //  *ebo;
    s->uvo = malloc(sizeof(GLuint) * numObjects); //  *uvo;
    s->nbo = malloc(sizeof(GLuint) * numObjects); //  *nbo;
    // s->aPosition  = malloc(sizeof(GLuint) * numObjects); //  *aPosition; // glVertexAttribPointer arg0
    // s->aColor     = malloc(sizeof(GLuint) * numObjects); //  *aColor;
    // s->aTexCoords = malloc(sizeof(GLuint) * numObjects); //  *aTexCoords;
    // s->aNormals   = malloc(sizeof(GLuint) * numObjects); //  *aNormals;
    // s->stride       = malloc(sizeof(GLsizei) * numObjects); //  *stride; // glVertexAttribPointer arg4
    // s->dimensions   = malloc(sizeof(GLint) * numObjects); // *dimensions; // glVertexAttribPointer arg1
    s->elementCount = malloc(sizeof(GLsizei) numObjects); // *elementCount;

    s->vsize = malloc(sizeof(GLsizeiptr) * numObjects); //  *vsize; // long int
    s->csize = malloc(sizeof(GLsizeiptr) * numObjects); //  *csize;
    s->tsize = malloc(sizeof(GLsizeiptr) * numObjects); //  *tsize;
    s->nsize = malloc(sizeof(GLsizeiptr) * numObjects); //  *nsize;
    s->isize = malloc(sizeof(GLsizeiptr) * numObjects); //  *isize; // long int

    s->aPosition = 0;
    s->aColor = 1;
    s->aTexCoords = 2;
    s->aNormals = 3;

    s->dimensions = 3;
    s->stride = 3 * (GLsizei)sizeof(GLfloat);

    return s;
}

Shader_t *shaderAddProgram(Shader_t *s, const GLchar *vpath, const GLchar *fpath)
{
    if (!(++s->numPrograms < s->maxPrograms)) {
        fprintf(stderr, "Exceded limit of allocated program memeory\n");
        return NULL;
    }

    s->program[s->numPrograms] = compileShaderFromSource(vpath, fpath);
    return s;
}

void shaderDestroy(Shader_t *s)
{
    if (s->program)
        free(s->program);
    if (s->vao)
        free(s->vao);
    if (s->vbo)
        free(s->vbo);
    if (s->cbo)
        free(s->cbo);
    if (s->uvo)
        free(s->uvo);
    if (s->nbo)
        free(s->nbo);

    if (s->aPosition)
        free(s->aPosition);
    if (s->aColor)
        free(s->aColor);
    if (s->aTexCoords)
        free(s->aTexCoords);
    if (s->aNormals)
        free(s->aNormals);
    if (s->stride)
        free(s->stride);
    if (s->elementCount)
        free(s->elementCount);
    if (s->dimensions)
        free(s->dimensions);
}
