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

void Model::draw(const Renderer &renderer) const
{
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);

	renderer.bindVAO();

	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, (GLvoid*)0);
}