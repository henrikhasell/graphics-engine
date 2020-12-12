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
    virtual void bindVAO() const;
    void transform(const glm::vec3 &position);
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
	virtual void bindVAO() const;
protected:
	GLuint uniform_projectionMatrix;
};

#endif
