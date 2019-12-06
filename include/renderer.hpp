#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "program.hpp"
#include "shader.hpp"

class Renderer
{
public:
	Renderer();
	virtual ~Renderer() = default;
	virtual bool initialise(const char vertex[], const char fragment[]);
	virtual void begin();
	virtual void end() = 0;
protected:
	Program program;
	Shader vertex_shader;
	Shader fragment_shader;
};

#endif