// Lighting Vshader
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormals;
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vNormal;

void main()
{
    // vNormal = vec4(uModel * vec4(aNormals, 0.0f)).xyz;
    vNormal = mat3(transpose(inverse(uModel))) * aNormals;
    gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
}

// end
