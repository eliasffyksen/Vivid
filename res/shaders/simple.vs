#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 colour;

out DATA
{
    vec3 position;
    vec4 color;
} vs_out;

void main(){

    gl_Position.xyz = position;
    gl_Position.w = 1.0;
    vs_out.position = position;
    vs_out.color = colour;
}

