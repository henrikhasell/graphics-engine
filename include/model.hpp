#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex3D
{
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec3 normal;
	glm::vec2 uv;
};

struct Vertex2D
{
    glm::vec2 position;
    glm::vec2 uv;
};

class Model
{
public:
	Model();
	~Model();
	void draw() const;

    template <typename T=Vertex3D>
	void data(
		const T vertex_data[],
		const GLuint index_data[],
		GLuint vertex_count,
		GLuint index_count)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(T), vertex_data, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count * sizeof(GLuint), index_data, GL_STATIC_DRAW);

        this->index_count = index_count;
    }
protected:
	GLuint vertex_buffer;
	GLuint index_buffer;
	GLuint index_count;
};

#endif