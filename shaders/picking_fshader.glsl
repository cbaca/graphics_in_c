// Picking Fshader
#version 330 core
// uniform uint uDrawIndex;
// uniform uint uObjectIndex;
out vec4 FragColor;

uniform vec3 uColor;
void main()
{
    // FragColor = vec3(float(uObjectIndex), float(uDrawIndex), float(gl_PrimitiveID + 1));
    FragColor = vec4(uColor, 1.0f);
}
