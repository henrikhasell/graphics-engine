#ifndef PHONG_HPP
#define PHONG_HPP

#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "camera.hpp"

class PhongRenderer : public Renderer
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

#endif