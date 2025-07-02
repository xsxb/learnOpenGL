#version 330 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec2 aTexCoord;

//out vec2 TexCoord;
out vec3 color;

uniform vec3 baseColor;
uniform float time;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    //vec3 newPos = sin(time) / 5 + aPos;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    //gl_Position = projection * view * model * vec4(aPos.x, newY, aPos.z, 1.0);
    color = baseColor;

    //TexCoord = aTexCoord;
}