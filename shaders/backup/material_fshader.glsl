// Lighting Fshader
#version 330 core

struct DirLight_t {
    vec3 color;
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
};

out vec4 FragColor;
uniform vec3 uColor; // model colors
uniform DirLight_t uDirLight;

in vec3 vNormal;

void main()
{
    vec3 ambientLighting = uDirLight.color * uDirLight.ambientIntensity;
    float diffuseFactor = max(dot(normalize(vNormal), -uDirLight.direction), 0.0f);

    vec3 diffuseLighting = uDirLight.color * uDirLight.diffuseIntensity * diffuseFactor;
    // if (diffuseFactor > 0.0f) {
    //     diffuseLighting = uDirLight.color * uDirLight.diffuseIntensity * diffuseFactor;
    // } else {
    //     diffuseLighting = vec3(0.0f, 0.0f, 0.0f);
    // }

    vec3 result = uColor * (ambientLighting + diffuseLighting);
    FragColor = vec4(result, 1.0f);
}


// end
