
#include "Shader.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#define OBJ_VSHADER_PATH "shaders/obj_vshader.glsl"
#define OBJ_FSHADER_PATH "shaders/obj_fshader.glsl"
#define MATERIAL_VSHADER_PATH "shaders/material_vshader.glsl"
#define MATERIAL_FSHADER_PATH "shaders/material_fshader.glsl"
#define HL_VSHADER_PATH "shaders/highlight_vshader.glsl"
#define HL_FSHADER_PATH "shaders/highlight_fshader.glsl"
#define PICKING_VSHADER_PATH "shaders/picking_vshader.glsl"
#define PICKING_FSHADER_PATH "shaders/picking_fshader.glsl"

static GLuint _compileShader(const char *const *vShaderText, const char *const *fShaderText, int *err);

PickingShader *pickingShaderInit(PickingShader *s)
{
    const char vpath[] = PICKING_VSHADER_PATH;
    const char fpath[] = PICKING_FSHADER_PATH;
    s->header.program = compileShaderFromSource(vpath, fpath);
    if (!s->header.program) return 0;
    s->aPosition = 0;
    Program_t program = s->header.program;

    s->uMat.model = glGetUniformLocation(program, "uModel");
    s->uMat.view = glGetUniformLocation(program, "uView");
    s->uMat.projection = glGetUniformLocation(program, "uProjection");
    s->uColor = glGetUniformLocation(program, "uColor");
    s->header.type = PICKING_SHADER;
    return s;
}

HighlightShader *highlightShaderInit(HighlightShader *s)
{
    const char vpath[] = HL_VSHADER_PATH;
    const char fpath[] = HL_FSHADER_PATH;
    s->header.program = compileShaderFromSource(vpath, fpath);
    if (!s->header.program) return 0;
    s->aPosition = 0;
    Program_t program = s->header.program;

    s->uMat.model = glGetUniformLocation(program, "uModel");
    s->uMat.view = glGetUniformLocation(program, "uView");
    s->uMat.projection = glGetUniformLocation(program, "uProjection");
    s->uTime = glGetUniformLocation(program, "uTime");
    s->uResolution = glGetUniformLocation(program, "uResolution");
    s->header.type = HIGHLIGHT_SHADER;
    return s;
}

MaterialShader *materialShaderInit(MaterialShader *s)
{
    const char vpath[] = MATERIAL_VSHADER_PATH;
    const char fpath[] = MATERIAL_FSHADER_PATH;

    Program_t program = compileShaderFromSource(vpath, fpath);
    if (!program) return 0;
    s->aPosition = 0;
    s->aNormals = 1;

    s->uModel = glGetUniformLocation(program, "uModel");
    s->uView = glGetUniformLocation(program, "uView");
    s->uProjection = glGetUniformLocation(program, "uProjection");
    s->uWorldPos = glGetUniformLocation(program, "uWorldPos");

    s->uCamPos = glGetUniformLocation(program, "uCamPos");
    s->uDirLight.color = glGetUniformLocation(program, "uDirLight.color");
    s->uDirLight.direction = glGetUniformLocation(program, "uDirLight.direction");
    s->uDirLight.ambientIntensity = glGetUniformLocation(program, "uDirLight.ambientIntensity");
    s->uDirLight.diffuseIntensity = glGetUniformLocation(program, "uDirLight.diffuseIntensity");

    s->uMaterial.ambient = glGetUniformLocation(program, "uMaterial.ambient");
    s->uMaterial.diffuse = glGetUniformLocation(program, "uMaterial.diffuse");
    s->uMaterial.specular = glGetUniformLocation(program, "uMaterial.specular");
    s->uMaterial.shininess = glGetUniformLocation(program, "uMaterial.shininess");

    s->program = program;
    s->st = MATERIAL_SHADER;
    return s;
}

ObjShader *newObjShader(void)
{
    const char vpath[] = OBJ_VSHADER_PATH;
    const char fpath[] = OBJ_FSHADER_PATH;
    Program_t program = compileShaderFromSource(vpath, fpath);
    if (!program) {
        fprintf(stderr, "ObjShader program null\n");
        return NULL;
    }
    ObjShader *os = malloc(sizeof(ObjShader));

    Shader_t *sh = (Shader_t *)os;
    sh->program = program;
    sh->uModel = glGetUniformLocation(program, "uModel");
    sh->uView = glGetUniformLocation(program, "uView");
    sh->uProjection = glGetUniformLocation(program, "uProjection");

    os->uTexture = glGetUniformLocation(program, "uTexture");
    if (!os->uTexture)
        fprintf(stderr, "Failed to retreive uTexture location\n");
    os->uLight.color = glGetUniformLocation(program, "uDirLight.color");
    os->uLight.direction = glGetUniformLocation(program, "uDirLight.direction");
    os->uLight.ambientIntensity = glGetUniformLocation(program, "uDirLight.ambientIntensity");
    os->uLight.diffuseIntensity = glGetUniformLocation(program, "uDirLight.diffuseIntensity");
    return os;
}

Program_t compileShaderFromSource(const char *vpath, const char *fpath)
{
    assert(vpath != NULL);
    assert(fpath != NULL);
    long int vfilesize;
    long int ffilesize;
    char *vShaderTextBuffer = readBinaryFile(vpath, &vfilesize);
    if (!vShaderTextBuffer) {
        perror("_readBinaryFile");
        fprintf(stderr, "%s\n%s\n", vpath, strerror(errno));
        exit(EXIT_FAILURE);
    }
    char *fShaderTextBuffer = readBinaryFile(fpath, &ffilesize);
    if (!fShaderTextBuffer) {
        perror("_readBinaryFile");
        fprintf(stderr, "%s\n%s\n", fpath, strerror(errno));
        exit(EXIT_FAILURE);
    }

    const char *vShaderText[] = { vShaderTextBuffer };
    const char *fShaderText[] = { fShaderTextBuffer };

    int err;
    Program_t program = _compileShader(vShaderText, fShaderText, &err);
    if (err) {
        if (err == 1)
            printFileError(vfilesize, vpath, vShaderTextBuffer);
        else if (err == 2)
            printFileError(ffilesize, fpath, fShaderTextBuffer);
        return 0;
    }
    if (vShaderTextBuffer) free(vShaderTextBuffer);
    if (fShaderTextBuffer) free(fShaderTextBuffer);
    return program;
}

GLuint _handleShaderCompileError(GLuint fd, GLuint instance)
{
    GLsizei loglen;
    char *logbuf;

    if (instance > 2) {
        glGetProgramiv(fd, GL_INFO_LOG_LENGTH, &loglen);
        if (!loglen) return 0;
        logbuf = malloc(sizeof(char) * (size_t)loglen);
        glGetProgramInfoLog(fd, loglen, &loglen, logbuf);
        fprintf(stderr, "Failed to link shader program: \n%s\n", logbuf);
        free(logbuf);
        return 0;
    }

    glGetShaderiv(fd, GL_INFO_LOG_LENGTH, &loglen);
    if (!loglen) return 0;
    logbuf = malloc(sizeof(char) * (size_t)loglen);
    glGetShaderInfoLog(fd, loglen, &loglen, logbuf);
    fprintf(stderr, "Failed to compile %s shader %u:\n%s\n\n", instance < 2 ? "vertex" : "fragment", fd, logbuf);
    free(logbuf);
    return 0;
}

static GLuint _compileShader(const char *const *vShaderText, const char *const *fShaderText, int *err)
{
    int shaderCompileSuccess;
    GLuint program;
    GLuint vertexShader;
    GLuint fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, vShaderText, NULL);
    glShaderSource(fragmentShader, 1, fShaderText, NULL);

    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderCompileSuccess);

    if (shaderCompileSuccess == GL_FALSE) {
        *err = 1;
        return _handleShaderCompileError(vertexShader, 1);
    }

    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &shaderCompileSuccess);

    if (shaderCompileSuccess == GL_FALSE) {
        *err = 2;
        return _handleShaderCompileError(fragmentShader, 2);
    }

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &shaderCompileSuccess);

    if (shaderCompileSuccess == GL_FALSE)
        return _handleShaderCompileError(program, 3);

    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    *err = 0;
    return program;
}

void shaderUse(Shader_t *s)
{
    glUseProgram(s->program);
}
