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

	// Output color = red 
	//color = vec3(1,0,0);
	color = fs_in.color;

}