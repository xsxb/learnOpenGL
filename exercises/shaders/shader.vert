#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float yOffset;
  
out vec3 ourColor;

vec3 newPos;

void main()
{
    newPos = vec3(aPos.x, 0.0 - aPos.y + yOffset, aPos.z);
    gl_Position = vec4(newPos, 1.0);
    ourColor = newPos;
}       