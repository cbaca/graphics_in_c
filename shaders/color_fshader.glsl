// Color Lighting Fshader
#version 330 core

#include "lighting.glsl"

out vec4 FragColor;

uniform vec3 uCamPos;
uniform DirLight_t uDirLight;
uniform Material_t uMaterial;
uniform PointLight_t uPointLight;
uniform SpotLight_t uSpotLight;

uniform vec3 uColor;

in vec3 vNormal;
in vec3 vWorldPos;

void main()
{
    vec3 unit_normal = normalize(vNormal);

    vec3 spec_light_path = normalize(uCamPos - vWorldPos);

    vec3 result = getDirLight(uDirLight, uMaterial, unit_normal, spec_light_path, vWorldPos, uColor) +
                  getSpotLight(uSpotLight, uPointLight, uMaterial, unit_normal, spec_light_path, vWorldPos, uColor);
    FragColor = vec4(result, 1.0f);
}

// end
