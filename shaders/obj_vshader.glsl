// Object Vshader
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aTexCoords;
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vNormal;
out vec2 vTexCoords;

void main()
{
    // vNormal = vec4(uModel * vec4(aNormals, 0.0f)).xyz;
    vTexCoords = aTexCoords;
    vNormal = mat3(transpose(inverse(uModel))) * aNormals;
    gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
}

// end
