#include "model.hpp"

Model::Model() : index_count(0)
{
	glGenBuffers(1, &vertex_buffer);
	glGenBuffers(1, &index_buffer);
}

Model::~Model()
{
	glDeleteBuffers(1, &vertex_buffer);
	glDeleteBuffers(1, &index_buffer);
}

void Model::draw() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, (GLvoid*)0);
}

void Model::data(
	const Vertex vertex_data[],
	const GLuint index_data[],
	GLuint vertex_count,
	GLuint index_count)
{
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(Vertex), vertex_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count * sizeof(GLuint), index_data, GL_STATIC_DRAW);

	this->index_count = index_count;
}