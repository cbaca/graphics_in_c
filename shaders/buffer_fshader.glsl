#version 330 core

out vec4 FragColor;
in vec2 UVs;

uniform sampler2D uScreenTex;

void main()
{
    vec3 color = texture(uScreenTex, UVs).rgb;
    float grayscale = 0.2126 * color.r + 0.7152 * color.g + 0.07222 * color.b;
    FragColor = vec4(vec3(grayscale), 1.0);
}
