#version 330 core
out vec4 FragColor;


in vec3 ourColor;
in vec2 TexCoord;

uniform float mix_val;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    float tex2_x = 1.0 - TexCoord.x;
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(tex2_x, TexCoord.y)), mix_val);
    //FragColor = texture(texture2, TexCoord);
    //FragColor = vec4(ourColor, 1.0);
}