#ifndef WORLD_H
#define WORLD_H
#include "Shader.h"
// #include "Camera.h"
#include "Maths.h"

typedef struct DirLight_t {
    Vec3 color;
    Vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
} DirLight_t;

typedef struct PointLight_t {
    Vec3 position;
    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;
    float Kc, Kl, Kq;
} PointLight_t;

typedef PointLight_t PointLight;
typedef DirLight_t DirLight;
typedef struct SpotLight {
    Vec3 position;
    Vec3 direction;

    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;

    float Kc, Kl, Kq;

    float cutoff_narrow;
    float cutoff_wide;

    float theta;
    float epsilon;
    float intensity;
} SpotLight;

typedef struct World_t {
    DirLight_t dirLight;
    float deltaTime;
    float lastTime;
} World_t;

void finalizeWorld(World_t *w);
World_t *initWorld(World_t *w);
void worldUpdate(World_t *w, float lastTime);
float *getWorldBGColor(World_t *w);

#endif /* WORLD_H */
