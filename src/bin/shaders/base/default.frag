#version 330 core

// Input variables
in vec3 color;
in vec2 texCoord;

// Output variables
out vec4 FragColor;

// Global variables
uniform sampler2D tex0;

void main()
{
    FragColor = texture(tex0, texCoord);
}