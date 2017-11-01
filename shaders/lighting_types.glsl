
#version 330 core

struct Material_t {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct DirLight_t {
    vec3 color;
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
};

struct PointLight_t {
    vec3 position;
    vec3 color;
    float ambientIntensity;
    float diffuseIntensity;

    float Kc; // const term
    float Kl; // linear term
    float Kq; // quadratic term
};

struct FlashLight_t {
    vec3 position;
    vec3 direction;
    float curOff;
};
