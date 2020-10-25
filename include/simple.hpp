#ifndef SIMPLE_HPP
#define SIMPLE_HPP

#include "renderer.hpp"
#include "camera.hpp"

class SimpleRenderer : public Renderer
{
public:
	virtual bool initialise(const char vertex[], const char fragment[]);
	virtual void begin();
	virtual void end();
protected:
	GLuint uniform_projectionMatrix;
	GLuint uniform_modelMatrix;
	GLuint uniform_viewMatrix;
};

class TextRenderer : public Renderer
{
public:
	virtual bool initialise(const char vertex[], const char fragment[]);
	virtual void begin();
	virtual void end();
protected:
	GLuint uniform_projectionMatrix;
};

#endif
