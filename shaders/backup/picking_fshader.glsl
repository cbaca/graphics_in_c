// Picking Fshader
#version 330 core
uniform uint uDrawIndex;
uniform uint uObjectIndex;

out vec3 FragColor;
void main()
{
    FragColor = vec3(float(uObjectIndex), float(uDrawIndex), float(gl_PrimitiveId + 1));
}
