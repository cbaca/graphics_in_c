// Object Fshader
#version 330 core

#include "lighting.glsl"

out vec4 FragColor;

uniform vec3 uCamPos;
uniform DirLight_t uDirLight;
uniform Material_t uMaterial;
uniform PointLight_t uPointLight;
uniform SpotLight_t uSpotLight;

uniform sampler2D uTexture;

in VOUT {
    vec3 normal;
    vec3 worldPos;
    vec2 UVs;
} v;

void main()
{
    vec3 unit_normal = normalize(v.normal);

    vec3 spec_light_path = normalize(uCamPos - v.worldPos);

    vec4 color = texture(uTexture, v.UVs);

    vec3 result = getDirLight(uDirLight, uMaterial, unit_normal, spec_light_path, v.worldPos, vec3(color)) +
                  getSpotLight(uSpotLight, uPointLight, uMaterial, unit_normal, spec_light_path, v.worldPos, vec3(color));

    FragColor = vec4(result, color.a);
    // gl_FragColor = vec4(result, color.a);
}
// end
