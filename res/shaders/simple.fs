#version 330 core

// Output data
layout (location = 0) out vec4 color;

in DATA
{
    vec3 position;
    vec4 color;
} fs_in;

void main()
{
	//color = uColor;
	color = fs_in.color;
}