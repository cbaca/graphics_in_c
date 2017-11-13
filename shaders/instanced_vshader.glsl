
#version 330 core

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aOffset;

void main()
{
    gl_Position = vec4(aPosition + aOffset, 0.0, 1.0);
}
