// Waves fragment shader
#version 330 core

out vec4 FragColor;

uniform sampler2D uTexture;
uniform float uTime;
uniform vec2 uResolution;
uniform vec2 uMouse;

const float Coef = 1.0f / 500.0f;
void main()
{
    vec2 uv = (gl_FragCoord.xy / uResolution.xy) - 0.5f;
    vec3 color = vec3(0.0f);
    for (float i = 0.0f; i < 10.0f; ++i) {
        uv.y += sin(uv.x * (i) + (uTime * i * i * 0.1f)) * 0.15f;
        float raydir = abs(1.0f / uv.y * Coef);
        color += (0.5 + 0.5 * sin(i + uTime * 5.0)) * vec3(raydir * (8.0 - i) / 7.0, raydir * i / 10.0, pow(raydir, 1.0) * 1.5);
    };

    FragColor = vec4(color, 1.0f);
}

// end
