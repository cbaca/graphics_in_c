
#version 330 core

layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec3 gAlbedo;

in vec2 UVs;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D uTextureDiffuse1;
uniform sampler2D uTextureSpecular1;

void main()
{
    gPosition = FragPos;
    gNormal = normalize(Normal);
    gAlbedo.rgb = texture(uTextureDiffuse1, UVs).rgb;
    gAlbedo.a = texture(uTextureSpecular1, UVs).r;
}
