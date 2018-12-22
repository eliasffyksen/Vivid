#version 330 core

// Output data
layout(location = 0) out vec4 color;

in DATA {
    vec3 position;
    vec2 texCoords;
    vec4 color;
} vertex_in;

uniform sampler2D textureSampler;

void main() {
//	color = fs_in.color;
	color = texture(textureSampler, vertex_in.texCoords);
}
