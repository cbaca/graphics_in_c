#ifndef SHADERTYPES_H
#define SHADERTYPES_H
#include "Maths.h"

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

typedef struct Material_t Material;
typedef struct DirLight_t DirLight;
typedef struct PointLight_t PointLight;
typedef struct SpotLight_t SpotLight;

struct Material_t {
    Vec3 ambient, diffuse, specular;
    float shininess;
};

struct DirLight_t {
    Vec3 color;
    Vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
};

struct PointLight_t {
    Vec3 position;
    Vec3 ambient, diffuse, specular;
    float Kc, Kl, Kq;
};

struct SpotLight_t {
    Vec3  direction;
    float ambientIntensity, diffuseIntensity;
    float inner_cutoff, outer_cutoff;
};
#endif // SHADERTYPES_H
