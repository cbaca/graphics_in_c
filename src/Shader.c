
#include "Shader.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#define TEX_VSHADER_PATH "shaders/texture_vshader.glsl"
#define TEX_FSHADER_PATH "shaders/texture_fshader.glsl"
#define COLOR_VSHADER_PATH "shaders/color_vshader.glsl"
#define COLOR_FSHADER_PATH "shaders/color_fshader.glsl"
#define HL_VSHADER_PATH "shaders/highlight_vshader.glsl"
#define HL_FSHADER_PATH "shaders/highlight_fshader.glsl"
#define PICKING_VSHADER_PATH "shaders/picking_vshader.glsl"
#define PICKING_FSHADER_PATH "shaders/picking_fshader.glsl"

#define SET_MATRIX_UNI(s,p) \
    s->uModel = glGetUniformLocation(p, "uModel"); \
    s->uView = glGetUniformLocation(p, "uView"); \
    s->uProjection = glGetUniformLocation(p, "uProjection");

#define SET_DIRLIGHT_UNI(s,p) \
    s->uDirLight.color = glGetUniformLocation(p, "uDirLight.color"); \
    s->uDirLight.direction = glGetUniformLocation(p, "uDirLight.direction"); \
    s->uDirLight.ambientIntensity = glGetUniformLocation(p, "uDirLight.ambientIntensity"); \
    s->uDirLight.diffuseIntensity = glGetUniformLocation(p, "uDirLight.diffuseIntensity");

#define SET_MATERIAL_UNI(s,p) \
    s->uMaterial.ambient = glGetUniformLocation(p, "uMaterial.ambient"); \
    s->uMaterial.diffuse = glGetUniformLocation(p, "uMaterial.diffuse"); \
    s->uMaterial.specular = glGetUniformLocation(p, "uMaterial.specular"); \
    s->uMaterial.shininess = glGetUniformLocation(p, "uMaterial.shininess");

#define SET_SPOTLIGHT_UNI(s,p) \
    s->uSpotLight.direction = glGetUniformLocation(p, "uSpotLight.direction"); \
    s->uSpotLight.ambientIntensity = glGetUniformLocation(p, "uSpotLight.ambientIntensity"); \
    s->uSpotLight.diffuseIntensity = glGetUniformLocation(p, "uSpotLight.diffuseIntensity"); \
    s->uSpotLight.inner_cutoff = glGetUniformLocation(p, "uSpotLight.inner_cutoff"); \
    s->uSpotLight.outer_cutoff = glGetUniformLocation(p, "uSpotLight.diffuseIntensity");

#define SET_POINTLIGHT_UNI(s,p) \
    s->uPointLight.position = glGetUniformLocation(p, "uPointLight.position"); \
    s->uPointLight.ambient = glGetUniformLocation(p, "uPointLight.ambient"); \
    s->uPointLight.diffuse = glGetUniformLocation(p, "uPointLight.diffuse"); \
    s->uPointLight.specular = glGetUniformLocation(p, "uPointLight.specular"); \
    s->uPointLight.Kc = glGetUniformLocation(p, "uPointLight.Kc"); \
    s->uPointLight.Kl = glGetUniformLocation(p, "uPointLight.Kl"); \
    s->uPointLight.Kq = glGetUniformLocation(p, "uPointLight.Kq");

#define SET_POS_UNI(s,p) \
    s->uWorldPos = glGetUniformLocation(p, "uWorldPos"); \
    s->uCamPos = glGetUniformLocation(p, "uCamPos");

static char **shader_paths;
static size_t num_shader_files;

static GLuint _compileShader(const char *const *vShaderText, const char *const *fShaderText, int *err);

int initShaderData(const char *dirpath)
{
    shader_paths = readDirFiles(dirpath, &num_shader_files);
    if (!shader_paths)
        return 0;
    sortStringArray(shader_paths, num_shader_files);
    return 1;
}

void printShaderFiles(void)
{
    printStringArray("Shader files:", shader_paths, num_shader_files);
}

void destroyShaderData(void)
{
    size_t i;
    for (i = 0; i < num_shader_files; ++i)
        free(shader_paths[i]);
    free(shader_paths);
}

ColorShader *initColorShader(ColorShader *s)
{
    const char vpath[] = COLOR_VSHADER_PATH;
    const char fpath[] = COLOR_FSHADER_PATH;

    Program_t program = compileShaderFromSource(vpath, fpath);
    if (!program) return NULL;
    s->aPosition = 0;
    s->aNormals = 1;

    SET_MATRIX_UNI(s, program);
    SET_POS_UNI(s, program);
    SET_MATERIAL_UNI(s, program);
    SET_DIRLIGHT_UNI(s, program);
    SET_SPOTLIGHT_UNI(s, program);
    SET_POINTLIGHT_UNI(s, program);
    s->uColor = glGetUniformLocation(program, "uColor");

    s->program = program;
    s->st = COLOR_SHADER;
    return s;
}

TexShader *initTexShader(TexShader *s)
{
    const char vpath[] = TEX_VSHADER_PATH;
    const char fpath[] = TEX_FSHADER_PATH;

    Program_t program = compileShaderFromSource(vpath, fpath);
    if (!program) return NULL;
    s->aPosition = 0;
    s->aNormals = 1;

    SET_MATRIX_UNI(s, program);
    SET_POS_UNI(s, program);
    SET_MATERIAL_UNI(s, program);
    SET_DIRLIGHT_UNI(s, program);
    SET_SPOTLIGHT_UNI(s, program);
    SET_POINTLIGHT_UNI(s, program);

    s->aUVs = 2;
    s->uTexture = glGetUniformLocation(program, "uTexture");

    s->program = program;
    s->st = TEX_SHADER;
    return s;
}

HighlightShader *initHighlightShader(HighlightShader *s)
{
    const char vpath[] = HL_VSHADER_PATH;
    const char fpath[] = HL_FSHADER_PATH;
    s->program = compileShaderFromSource(vpath, fpath);
    if (!s->program) return NULL;
    s->st = HIGHLIGHT_SHADER;
    s->aPosition = 0;
    Program_t program = s->program;
    SET_MATRIX_UNI(s, program);
    s->uTime = glGetUniformLocation(program, "uTime");
    s->uResolution = glGetUniformLocation(program, "uResolution");
    return s;
}


PickingShader *pickingShaderInit(PickingShader *s)
{
    const char vpath[] = PICKING_VSHADER_PATH;
    const char fpath[] = PICKING_FSHADER_PATH;
    s->program = compileShaderFromSource(vpath, fpath);
    if (!s->program) return 0;
    s->aPosition = 0;
    Program_t program = s->program;

    SET_MATRIX_UNI(s, program);
    s->uColor = glGetUniformLocation(program, "uColor");
    s->st = PICKING_SHADER;
    return s;
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

void shaderUse(BaseShader *s)
{
    glUseProgram(s->program);
}
