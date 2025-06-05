#version 330 core

out vec4 outColor;

uniform vec4 u_color;

void main() 
{
    outColor = vec4(u_color);
}
