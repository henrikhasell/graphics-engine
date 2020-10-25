#version 420
in vec3 in_Position;
in vec3 in_Colour;
in vec3 in_Normal;
in vec2 in_UV;

out vec3 ex_Position;
out vec3 ex_Colour;
out vec3 ex_Normal;
out vec2 ex_UV;

uniform mat4 projectionMatrix = mat4(1.0);
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
	ex_Position = (modelMatrix * vec4(in_Position, 1.0)).xyz;
	ex_Colour = in_Colour;
	ex_Normal = normalize(mat3(modelMatrix) * in_Normal);
	ex_UV = in_UV;
}