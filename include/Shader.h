#ifndef SHADERS_H
#define SHADERS_H
#include <GL/glew.h>

typedef GLuint Program_t;

typedef enum ShaderType {
    HIGHLIGHT_SHADER,
    MATERIAL_SHADER,
    PICKING_SHADER
} ShaderType;

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

typedef struct MatUniforms { // hurry and kill this
    GLint model;
    GLint view;
    GLint projection;
} MatUniforms;

typedef struct shaderHeader {
    ShaderType type;
    Program_t program;
} shaderHeader;

typedef struct PickingShader {
    shaderHeader header;
    GLuint aPosition;
    MatUniforms uMat;
    // GLint uDrawIndex;
    // GLint uObjectIndex;
    GLint uColor;
} PickingShader;

typedef struct HighlightShader {
    shaderHeader header;
    GLuint aPosition;
    MatUniforms uMat;
    GLint uTime;
    GLint uResolution;
} HighlightShader;

typedef struct MaterialShader {
    ShaderType st;
    Program_t program;

    GLuint aPosition;
    GLuint aNormals;

    GLint uModel;
    GLint uView;
    GLint uProjection;
    GLint uWorldPos;

    GLint uCamPos;
    LightUniforms uDirLight;
    MaterialUniforms uMaterial;

    // GLint uTime;
    // GLint uResolution;
    // GLint uDrawIndex;
    // GLint uObjIndex;

} MaterialShader;

typedef struct GenericShader {
    ShaderType shadertype;
    GLuint program;
    GLuint aPosition;
    GLuint aNormals;
    GLuint aColor;
    GLuint aTexCoords;
    GLint uModel;
    GLint uView;
    GLint uProjection;
    GLint uColor;
    GLint uTime;
    GLint uResolution;
    GLint uDirLight_color;
    GLint uDirLight_direction;
    GLint uDirLight_ambientIntensity;
    GLint uDirLight_diffuseIntensity;
    GLint uDrawIndex;
    GLint uObjIndex;

} GenericShader;

typedef struct Shader_t {
    Program_t program;
    GLint uModel;
    GLint uView;
    GLint uProjection;
} Shader_t;

typedef struct ObjShader {
    Shader_t shader;
    GLint uTexture;
    LightUniforms uLight;
} ObjShader;

// glBindVertexArray        -- mesh         meshUse()
// glBindBuffer(vbo/nbo...) -- mesh         meshUse()
// glBindBuffer(ebo)        -- mesh         meshUse()
// glUse Program            -- shader       shaderUse()
// glUniform...             -- shader, model
// glDrawElements           -- mesh         meshDraw()


MaterialShader *materialShaderInit(MaterialShader *s);
HighlightShader *highlightShaderInit(HighlightShader *s);
PickingShader *pickingShaderInit(PickingShader *s);
ObjShader *newObjShader(void);
void shaderUse(Shader_t *s);

Program_t compileShaderFromSource(const char *vpath, const char *fpath);

#endif /* SHADERS_H */
