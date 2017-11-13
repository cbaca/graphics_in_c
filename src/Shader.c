
#include "Shader.h"
#include "utils.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

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
    s->uCamPos = glGetUniformLocation(p, "uCamPos");

program_t _compileShaderFromText(const char *vtext, const char *ftext);
GLuint _handleShaderCompileError(GLuint fd, GLuint instance);
char *_eval_shader_text(const char *path);
static GLuint _compile_shader(const char *const *vShaderText, const char *const *fShaderText, int *err);

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

static GLuint _compile_shader(const char *const *vShaderText, const char *const *fShaderText, int *err)
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

char *_eval_shader_text(const char *path)
{
    long int filelen;
    char *text = readBinaryFile(path, &filelen);
    char *inc = strstr(text, "#include");

    if (!inc)
        return text;
    if (*(inc - 1) != ' ' && *(inc - 1) != '\n')
        return text;

    long int len;
    long int filelen2;
    long int header_len;
    char *inc2 = nil;
    char *del = nil;
    char *text2 = nil;
    char *ret = nil;
    char pathbuf[100];

    inc = index(inc, '\"');
    inc2 = index(inc + 1, '\"');
    len = inc2 - inc - 1;
    inc += 1;
    strcpy(pathbuf, path);

    del = index(pathbuf, '/') + 1;
    strncpy(del, inc, (size_t)len);
    del[len] = '\0';
    text2 = readBinaryFile(pathbuf, &filelen2);
    ret = malloc((size_t)filelen2 + (size_t)filelen + sizeof(char));
    header_len = strstr(text, "#include") - text;
    strncpy(ret, text, (size_t)header_len);
    ret[header_len++] = '\n';
    ret[header_len++] = '\0';
    strcat(ret, text2);
    strcat(ret, inc2 + 1);
    free(text);
    free(text2);
    return ret;

}

program_t _compileShaderFromText(const char *vtext, const char *ftext)
{
    assert(vtext != NULL);
    assert(ftext != NULL);
    const char *vShaderText[] = { vtext };
    const char *fShaderText[] = { ftext };

    int err;
    program_t program = _compile_shader(vShaderText, fShaderText, &err);
    if (!err)
        return program;

    if (err == 1) {
        fprintf(stderr, "vshader text:\n\n%s\n", vtext);
        return 0;
    }
    if (err == 2) {
        fprintf(stderr, "fshader text:\n\n%s\n", ftext);
        return 0;
    }
    return 0;
}

ToyShader *_init_toy_shader(ToyShader *s, const char *vpath, const char *fpath)
{
    s->program = compileShaderFromSource(vpath, fpath);
    if (!s->program) return nil;
    s->aPosition = 0;
    s->uTexture = glGetUniformLocation(s->program, "uTexture");
    s->uTime = glGetUniformLocation(s->program, "uTime");
    s->uResolution = glGetUniformLocation(s->program, "uResolution");
    s->uMouse = glGetUniformLocation(s->program, "uMouse");
    if (s->st & MVP_UNIFORM) {
        s->uModel = glGetUniformLocation(s->program, "uModel");
        s->uMatrices = glGetUniformBlockIndex(s->program, "uMatrices");
        return s;
    }
    s->uModel = -1;
    s->uMatrices = 0;
    return s;
}

LightingShader *_init_lighting_shader(LightingShader *s, const char *vpath, const char *fpath)
{
    char *vtext = _eval_shader_text(vpath);
    char *ftext = _eval_shader_text(fpath);
    s->program = _compileShaderFromText(vtext, ftext);
    if (!s->program) return NULL;
    s->aPosition = 0;
    s->aNormals = 1;

    s->uModel = glGetUniformLocation(s->program, "uModel");
    s->uMatrices = glGetUniformBlockIndex(s->program, "uMatrices");
    glUniformBlockBinding(s->program, s->uMatrices, 0);
    SET_POS_UNI(s, s->program);
    SET_MATERIAL_UNI(s, s->program);
    SET_DIRLIGHT_UNI(s, s->program);
    SET_SPOTLIGHT_UNI(s, s->program);
    SET_POINTLIGHT_UNI(s, s->program);
    s->a0 = 2;
    if (s->st & UV_ATTRIB)
        s->u0 = glGetUniformLocation(s->program, "uTexture");
    else
        s->u0 = glGetUniformLocation(s->program, "uColor");
    return s;

}

LightingShader *init_texture_shader(LightingShader *s)
{
    s->st = MVP_UNIFORM | NORMALS_ATTRIB | UV_ATTRIB | LIGHTING_SHADER;
    return _init_lighting_shader(s, "shaders/texture_vshader.glsl", "shaders/texture_fshader.glsl");
}

LightingShader *init_color_shader(LightingShader *s)
{
    s->st = MVP_UNIFORM | NORMALS_ATTRIB | LIGHTING_SHADER;
    return _init_lighting_shader(s, "shaders/color_vshader.glsl", "shaders/color_fshader.glsl");
}

ToyShader *init_marching_shader(ToyShader *s)
{
    s->st = BASIC_SHADER | MARCHING_SHADER;
    return _init_toy_shader(s, "shaders/basic_vshader.glsl", "shaders/marching_fshader.glsl");
}

ToyShader *init_tunnel_shader(ToyShader *s)
{
    s->st = BASIC_SHADER | TUNNEL_SHADER;
    return _init_toy_shader(s, "shaders/basic_vshader.glsl", "shaders/tunnel_fshader.glsl");
}

ToyShader *init_highlight_shader(ToyShader *s)
{
    s->st = MVP_UNIFORM | WAVES_SHADER;
    return _init_toy_shader(s, "shaders/mvp_vshader.glsl", "shaders/waves_fshader.glsl");
}

program_t compileShaderFromSource(const char *vpath, const char *fpath)
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
    program_t program = _compile_shader(vShaderText, fShaderText, &err);
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

void setMaterialUniforms(MaterialUniforms *mu, Material *ma)
{
    glUniform3fv(mu->ambient, 1, (float *)&ma->ambient);
    glUniform3fv(mu->diffuse, 1, (float *)&ma->diffuse);
    glUniform3fv(mu->specular, 1, (float *)&ma->specular);
    glUniform1f(mu->shininess, ma->shininess);
}

void setLightUniforms(LightUniforms *lu, DirLight *dl)
{
    glUniform3fv(lu->color, 1, (float *)&dl->color);
    glUniform3fv(lu->direction, 1, (float *)&dl->direction);
    glUniform1f(lu->ambientIntensity, dl->ambientIntensity);
    glUniform1f(lu->diffuseIntensity, dl->diffuseIntensity);
}

void setSpotLightUniforms(SpotLightUniforms *su, SpotLight *sl)
{
    glUniform3fv(su->direction, 1, (float *)&sl->direction);
    glUniform1f(su->ambientIntensity, sl->ambientIntensity);
    glUniform1f(su->diffuseIntensity, sl->diffuseIntensity);
    glUniform1f(su->inner_cutoff, sl->inner_cutoff);
    glUniform1f(su->outer_cutoff, sl->outer_cutoff);
}

void setPointLightUniforms(PointLightUniforms *pu, PointLight *pl)
{
    glUniform3fv(pu->position, 1, (float *)&pl->position);
    glUniform3fv(pu->ambient, 1, (float *)&pl->ambient);
    glUniform3fv(pu->diffuse, 1, (float *)&pl->diffuse);
    glUniform3fv(pu->specular, 1, (float *)&pl->specular);
    glUniform1f(pu->Kc, pl->Kc);
    glUniform1f(pu->Kl, pl->Kl);
    glUniform1f(pu->Kq, pl->Kq);
}

/*
PickingShader *pickingShaderInit(PickingShader *s)
{
    const char vpath[] = PICKING_VSHADER_PATH;
    const char fpath[] = PICKING_FSHADER_PATH;
    s->program = compileShaderFromSource(vpath, fpath);
    if (!s->program) return 0;
    s->aPosition = 0;
    program_t program = s->program;

    SET_MATRIX_UNI(s, program);
    s->uColor = glGetUniformLocation(program, "uColor");
    s->st = PICKING_SHADER;
    return s;
}
*/
