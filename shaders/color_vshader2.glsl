// Lighting Vshader
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormals;

layout (std140) uniform u {
    mat4 view;
    mat4 projection;
};

uniform mat4 uModel;

out VOUT {
    vec3 normal;
    vec3 worldPos;
} v;

void main()
{
    v.worldPos = vec3(uModel * vec4(aPosition, 1.0f));
    v.normal = mat3(transpose(inverse(uModel))) * aNormals;
    gl_Position = projection * view * vec4(v.worldPos, 1.0f); // uModel * vec4(aPosition, 1.0f);
}

// end
