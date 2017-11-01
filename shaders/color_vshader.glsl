// Lighting Vshader
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormals;
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;
uniform vec3 uWorldPos;
out vec3 vNormal;
out vec3 vWorldPos;

void main()
{
    vWorldPos = vec3(uModel * vec4(aPosition, 1.0f));
    vNormal = mat3(transpose(inverse(uModel))) * aNormals;
    gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
}

// end
