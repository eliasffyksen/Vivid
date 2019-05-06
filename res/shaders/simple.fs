#version 330 core

// Output data
layout(location = 0) out vec4 color;

in DATA {
    vec3 position;
    vec2 texCoords;
    vec4 colour;
} fs_in;

uniform sampler2D textureSampler;

void main() {
	vec4 tex_colour = texture(textureSampler, fs_in.texCoords);
	color = vec4((1 - fs_in.colour.a) * tex_colour.xyz + fs_in.colour.a * fs_in.colour.xyz, tex_colour.a);
}
