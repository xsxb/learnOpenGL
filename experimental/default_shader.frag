#version 330 core
out vec4 FragColor;

in vec3 color;
//in vec2 TexCoord;

uniform float time;
//uniform sampler2D texture1;
//uniform sampler2D texture2;

void main()
{
    //FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
    //FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    FragColor = vec4(color, 1.0f);
}