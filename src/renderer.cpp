#include "renderer.hpp"
#include <iostream>

Renderer::Renderer() :
	vertex_shader(GL_VERTEX_SHADER),
	fragment_shader(GL_FRAGMENT_SHADER)
{

}

bool Renderer::initialise(const char vertex[], const char fragment[])
{
	if (!vertex_shader.load(vertex))
	{
		std::cerr << vertex_shader.infoLog() << std::endl;
		return false;
	}

	if (!fragment_shader.load(fragment))
	{
		std::cerr << fragment_shader.infoLog() << std::endl;
		return false;
	}

	if (!program.link(vertex_shader, fragment_shader))
	{
		std::cerr << program.infoLog() << std::endl;
		return false;
	}

	return true;
}

void Renderer::begin()
{
	program.use();
}