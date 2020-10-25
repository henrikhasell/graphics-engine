#version 130

struct Light
{
	vec3 position;
	vec3 colour;
};

uniform sampler2D diffuseTexture;

uniform Light main_light = {
	{0, 1.5, 10}, {1, 0, 0}
};
uniform Light main_light2 = {
	{-5, 1.5, 10}, {0, 1, 0}
};
uniform Light main_light3 = {
	{5, 1.5, 10}, {0, 0, 1}
};

in vec3 ex_Position;
in vec3 ex_Colour;
in vec3 ex_Normal;
in vec2 ex_UV;

out vec4 out_Colour;

vec3 light_colour(Light light)
{
	vec3 light_direction = normalize(ex_Position - light.position);
	float light_amount = max(dot(ex_Normal, light_direction), 0);
	return light.colour * light_amount;
}

void main()
{
	vec3 total_light = light_colour(main_light) + light_colour(main_light2) + light_colour(main_light3);
    out_Colour = vec4(ex_Colour, 1) * texture(diffuseTexture, ex_UV) * vec4(total_light, 1);
} 