#ifndef SHADERTYPES_H
#define SHADERTYPES_H
#include "types.h"
#include <GL/glew.h>

/**
 * https://learnopengl.com/#!Lighting/Light-casters
 * Dist  | Const |  Linear  | Quadratic
 * ------|-------|----------|-----------
 *    7  |  1.0  |  0.7     |  1.8
 *   13  |  1.0  |  0.35    |  0.44
 *   20  |  1.0  |  0.22    |  0.20
 *   32  |  1.0  |  0.14    |  0.07
 *   50  |  1.0  |  0.09    |  0.032
 *   65  |  1.0  |  0.07    |  0.017
 *  100  |  1.0  |  0.045   |  0.0075
 *  160  |  1.0  |  0.027   |  0.0028
 *  200  |  1.0  |  0.022   |  0.0019
 *  325  |  1.0  |  0.014   |  0.0007
 *  600  |  1.0  |  0.007   |  0.0002
 * 3250  |  1.0  |  0.0014  |  0.000007
 */

typedef GLuint program_t;
typedef GLuint attrib_t;
typedef GLint uniform_t;

// Data
typedef struct material_t {
    Vec3 ambient, diffuse, specular;
    float shininess;
} Material;

typedef struct dirlight_t {
    Vec3 color;
    Vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
} DirLight;

typedef struct pointlight_t {
    Vec3 position;
    Vec3 ambient, diffuse, specular;
    float Kc, Kl, Kq;
} PointLight;

typedef struct spotlight_t {
    Vec3  direction;
    float ambientIntensity, diffuseIntensity;
    float inner_cutoff, outer_cutoff;
} SpotLight;


// Data location

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
    uniform_t position;
    uniform_t ambient, diffuse, specular;
    uniform_t Kc, Kl, Kq;
} PointLightUniforms;

typedef struct SpotLightUniforms {
    uniform_t direction;
    uniform_t ambientIntensity, diffuseIntensity;
    uniform_t inner_cutoff, outer_cutoff;
} SpotLightUniforms;
#endif // SHADERTYPES_H
