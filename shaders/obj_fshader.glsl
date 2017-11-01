// Object Fshader
#version 330 core

struct DirLight_t {
    vec3 color;
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
};

out vec4 FragColor;
uniform sampler2D uTexture; // model colors
uniform DirLight_t uDirLight;

in vec3 vNormal;
in vec2 vTexCoords;

void main()
{
    vec3 ambientLighting = uDirLight.color * uDirLight.ambientIntensity;
    float diffuseFactor = max(dot(normalize(vNormal), -uDirLight.direction), 0.0f);
    vec3 diffuseLighting = uDirLight.color * uDirLight.diffuseIntensity * diffuseFactor;
    vec4 texcolor = texture(uTexture, vTexCoords);
    vec3 lighting = (ambientLighting + diffuseLighting);
    FragColor = vec4(lighting, 1.0f) * texcolor;
}


// end
