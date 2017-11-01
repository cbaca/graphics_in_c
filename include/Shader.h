#ifndef SHADERS_H
#define SHADERS_H
#include <GL/glew.h>
#include "ShaderTypes.h"

typedef GLuint Program_t;
typedef GLuint Attrib_t;
typedef GLint Uniform_t;

typedef enum ShaderType { COLOR_SHADER, TEX_SHADER, HIGHLIGHT_SHADER, PICKING_SHADER } ShaderType;

/*
 * typedef struct Material { Vec3 ambient; Vec3 diffuse; Vec3 specular; float shininess; } Material;
 * setMaterialUniforms(LightUniforms *lu, Material *m);
 */
typedef struct MaterialUniforms {
    GLint ambient; // vec3
    GLint diffuse; // vec3
    GLint specular; // vec3
    GLint shininess; // float
} MaterialUniforms;

/*
 * typedef struct DirLight{ Vec3 color, direction; float ambientIntensity, diffuseIntensity; } DirLight;
 * setDirLightUniforms(LightUniforms *lu, DirLight *dl)
 * {
 *     glUniform3fv(lu->color, 1, dl->color);
 *     glUniform3fv(lu->direction, 1, dl->direction);
 *     glUniform1f(lu->ambientIntensity, dl->ambientIntensity);
 *     glUniform1f(lu->diffuseIntensity, dl->diffuseIntensity);
 * }
 */
typedef struct LightUniforms {
    GLint color;
    GLint direction;
    GLint ambientIntensity;
    GLint diffuseIntensity;
} LightUniforms;

typedef struct PointLightUniforms {
    Uniform_t position;
    Uniform_t ambient, diffuse, specular;
    Uniform_t Kc, Kl, Kq;
} PointLightUniforms;

typedef struct SpotLightUniforms {
    Uniform_t direction;
    Uniform_t ambientIntensity, diffuseIntensity;
    Uniform_t inner_cutoff, outer_cutoff;
} SpotLightUniforms;

typedef struct ColorShader {
    ShaderType       st;
    Program_t        program;
    Attrib_t         aPosition, aNormals;
    Uniform_t        uModel, uView, uProjection;
    Uniform_t        uCamPos, uWorldPos;
    MaterialUniforms   uMaterial;
    LightUniforms      uDirLight;
    PointLightUniforms uPointLight;
    SpotLightUniforms  uSpotLight;

    Uniform_t uColor;
} ColorShader;

typedef struct TexShader {
    ShaderType       st;
    Program_t        program;
    Attrib_t         aPosition, aNormals;
    Uniform_t        uModel, uView, uProjection;
    Uniform_t        uCamPos, uWorldPos;
    MaterialUniforms   uMaterial;
    LightUniforms      uDirLight;
    PointLightUniforms uPointLight;
    SpotLightUniforms  uSpotLight;

    Uniform_t uTexture;
    Attrib_t  aUVs;

} TexShader;

typedef struct HighlightShader {
    /* shaderHeader header;
    GLuint aPosition;
    MatUniforms uMat;
    GLint uTime;
    GLint uResolution; */
    ShaderType st;
    Program_t program;
    Attrib_t  aPosition, PADDING;
    Uniform_t uModel, uView, uProjection;
    Uniform_t uTime, uResolution;
} HighlightShader;

typedef struct BaseShader {
    ShaderType st;
    Program_t program;
    Attrib_t  a0, a1;
    Uniform_t u0, u1, u2;
} BaseShader;

typedef union GenericShader {
    BaseShader b;
    ColorShader c;
    TexShader t;
    HighlightShader hl;
} GenericShader;

typedef struct PickingShader {
    ShaderType st;
    Program_t program;
    Attrib_t  aPosition, PADDING;
    Uniform_t uModel, uView, uProjection;
    // GLint uDrawIndex;
    // GLint uObjectIndex;
    GLint uColor;
} PickingShader;

int initShaderData(const char *dirpath);
void printShaderFiles(void);
void destroyShaderData(void);

ColorShader *initColorShader(ColorShader *s);
TexShader *initTexShader(TexShader *s);
HighlightShader *initHighlightShader(HighlightShader *s);
PickingShader *pickingShaderInit(PickingShader *s);
void shaderUse(BaseShader *s);

Program_t compileShaderFromSource(const char *vpath, const char *fpath);

#endif /* SHADERS_H */
