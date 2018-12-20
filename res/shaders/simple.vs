#version 330 core

// Input vertex data
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoords;
layout(location = 2) in vec4 colour;

out DATA {
    vec3 position;
    vec2 texCoords;
    vec4 color;
} vs_out;

void main() {
    vs_out.position = position;
    vs_out.texCoords = texCoords;
    vs_out.color = colour;
    gl_Position = vec4(position, 1.0);
}
