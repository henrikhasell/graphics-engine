#version 130

uniform sampler2D diffuseTexture;

in vec2 ex_UV;

out vec4 out_Colour;

void main()
{
    out_Colour = texture(diffuseTexture, ex_UV);
} 