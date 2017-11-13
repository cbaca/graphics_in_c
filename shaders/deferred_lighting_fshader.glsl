#version 330 core
out vec4 FragColor;
in vec2 UVs;
uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;

struct Light {
    vec3 position;
    vec3 color;
};

const int NR_LIGHTS = 32;
uniform Light uLights[NR_LIGHTS];
uniform vec3 uViewPos;

void main()
{
    vec3 position = texture(gPosition, UVs).rgb;
    vec3 normal = texture(gNormal, UVs).rgb;
    vec3 albedo = texture(gAlbedo, UVs).rgb;
    float specular = texture(gAlbedo, UVs).a;

    vec3 lighting = albedo * 0.1;
    vec3 view_dir = normalize(uViewPos - position);
    int i;
    for (i = 0; i < NR_LIGHTS; ++i) {
        vec3 light_dir = normalize(lights[i].position - position);
        vec3 diffuse = max(dot(normal, light_dir), 0.0) * albedo, *lights[i].color;
        lighting += diffuse;
    }

    FragColor = vec4(lighting, 1.0);
}
