#ifndef SHADERS_H
#define SHADERS_H
// #include <GL/glew.h>
#include "ShaderTypes.h"

typedef enum shaderdef_t {
    NULL_SHADER  = 0x0000,

    BASIC_SHADER    = 0x0001,
    MVP_UNIFORM     = 0x0002,
    NORMALS_ATTRIB  = 0x0004,
    UV_ATTRIB       = 0x0008,

    MARCHING_SHADER = 0x0010,
    TUNNEL_SHADER   = 0x0020,
    WAVES_SHADER    = 0x0040,
    LIGHTING_SHADER = 0x0080,

    MAX_SHADER   = 0xffff,
} shaderdef_t;

typedef struct toyshader_t {
    shaderdef_t st;
    program_t  program;
    attrib_t  aPosition;
    uniform_t uTexture, uTime, uMouse, uResolution;
    uniform_t uModel; // , uView, uProjection;
    GLuint uMatrices;
} ToyShader;

typedef struct lightingshader_t {
    shaderdef_t       st;
    program_t        program;
    attrib_t         aPosition, aNormals;
    uniform_t        uModel, uCamPos; // , uView, uProjection;
    MaterialUniforms   uMaterial;
    LightUniforms      uDirLight;
    PointLightUniforms uPointLight;
    SpotLightUniforms  uSpotLight;
    GLuint uMatrices;

    uniform_t u0;
    attrib_t a0;
} LightingShader;

LightingShader *init_texture_shader(LightingShader *s);
LightingShader *init_color_shader(LightingShader *s);
ToyShader *init_marching_shader(ToyShader *s);
ToyShader *init_tunnel_shader(ToyShader *s);
ToyShader *init_highlight_shader(ToyShader *s);

program_t compileShaderFromSource(const char *vpath, const char *fpath);

void setMaterialUniforms(MaterialUniforms *mu, Material *ma);
void setLightUniforms(LightUniforms *lu, DirLight *dl);
void setSpotLightUniforms(SpotLightUniforms *su, SpotLight *sl);
void setPointLightUniforms(PointLightUniforms *pu, PointLight *pl);

// #define USE_SHADER(s) glUseProgram(s->program)
// PickingShader *pickingShaderInit(PickingShader *s);
// BasicShader   *init_basic_shader(BasicShader  *s);
/*
typedef struct BufferShader {
    shaderdef_t st;
    program_t  program;
    attrib_t  aPosition;
    attrib_t aUVs;
    uniform_t uScreenTex;
} BufferShader;
typedef struct InstancedShader {
    shaderdef_t st;
    program_t  program;
    attrib_t  aPosition;
    attrib_t aOffsets;
} InstancedShader;
*/

/*
typedef struct PickingShader {
    shaderdef_t st;
    program_t program;
    attrib_t  aPosition, PADDING;
    uniform_t uModel, uView, uProjection;
    // GLint uDrawIndex;
    // GLint uObjectIndex;
    GLint uColor;
} PickingShader;
*/


#endif /* SHADERS_H */
