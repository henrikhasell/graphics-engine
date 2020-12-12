#version 420
in vec2 in_Position;
in vec2 in_UV;

out vec2 ex_UV;

uniform mat4 projectionMatrix = mat4(1.0);

void main()
{
    gl_Position = projectionMatrix * vec4(in_Position, 0.0, 1.0);
	ex_UV = in_UV;
}