// Stencil Fshader
#version 330 core
out vec4 FragColor;
uniform float uTime;
uniform vec2 uResolution;
const float Coef = 1.0f / 500.0f;
void main()
{
    vec2 uv = (gl_FragCoord.xy / uResolution.xy) - 0.5f;
    vec3 color = vec3(0.0f);
    float intensity = 10.0f;
    for (float i = 0.0f; i < intensity; ++i) {
        uv.y += sin(uv.x * (i) + (uTime * i * i * 0.1f)) * 0.15f;
        float raydir = abs(1.0f / uv.y * Coef);
        float brightness =  (0.5f + 0.5f * sin(i + uTime * 5.0f));
        float red = raydir * (8.0f - i) / 7.0f;
        float green = raydir * i / 10.0f;
        float blue = pow(raydir, 1.0f) * 1.5f;
        color += vec3(red, green, blue) * brightness;
// color += (0.5f + 0.5f * sin(i + uTime * 5.0f)) * vec3(raydir * (8.0f - i) / 7.0f, raydir * i / 10.0f, pow(raydir, 1.0f) * 1.5f);
    };
    FragColor = vec4(color, 1.0f);
}

// end
