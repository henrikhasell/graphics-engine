#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec3 normal;
	glm::vec2 uv;
};

class Model
{
public:
	Model();
	~Model();
	void draw() const;
	void data(
		const Vertex vertex_data[],
		const GLuint index_data[],
		GLuint vertex_count,
		GLuint index_count);
protected:
	GLuint vertex_buffer;
	GLuint index_buffer;
	GLuint index_count;
};

#endif