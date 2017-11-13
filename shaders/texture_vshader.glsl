// Object Vshader
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aUVs;

layout (std140) uniform uMatrices {
    mat4 uView;
    mat4 uProjection;
};
// uniform mat4 uView;
// uniform mat4 uProjection;

uniform mat4 uModel;

out VOUT {
    vec3 normal;
    vec3 worldPos;
    vec2 UVs;
} v;

void main()
{
    vec4 wp = uModel * vec4(aPosition, 1.0f);
    v.worldPos = vec3(wp) / wp.w;
    v.UVs= aUVs;
    v.normal = mat3(transpose(inverse(uModel))) * aNormals;
    gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
}

// end
