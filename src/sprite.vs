#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

// transforms world-space coordinates into normalised device coordinates
// single scene game, no need for a camera/view matrix

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}