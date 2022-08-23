#version 330 core
in vec2 TexCoords;
out vec4 color;

// fragment shader, take a texture and apply a colour vector

uniform sampler2D sprite;
uniform vec3 spriteColor;

void main()
{
    
    color = vec4(spriteColor, 1.0) * texture(sprite, TexCoords);
}