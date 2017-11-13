#ifndef WORLD_H
#define WORLD_H
#include "Shader.h"
// #include "Camera.h"
#include "ShaderTypes.h"

typedef struct World_t {
    DirLight dirLight;
    PointLight pointLight;
    SpotLight spotLight;
    float deltaTime;
    float lastTime;
} World_t;

void finalizeWorld(World_t *w);
World_t *initWorld(World_t *w);
void worldUpdate(World_t *w, float lastTime);
float *getWorldBGColor(World_t *w);

#endif /* WORLD_H */
