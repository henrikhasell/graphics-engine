#include "simple.hpp"
#include "model.hpp"

#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

bool SimpleRenderer::initialise(const char vertex[], const char fragment[])
{
	if (!Renderer::initialise(vertex, fragment))
	{
		return false;
	}

	uniform_projectionMatrix = program.getUniformLocation("projectionMatrix");
	uniform_modelMatrix = program.getUniformLocation("modelMatrix");
	uniform_viewMatrix = program.getUniformLocation("viewMatrix");

	program.bindAttributeLocation(0, "in_Position");
	program.bindAttributeLocation(1, "in_Colour");
	program.bindAttributeLocation(2, "in_Normal");
	program.bindAttributeLocation(3, "in_UV");

	const glm::mat4 projection_matrix = glm::perspective(
		45.0f,
		800.0f / 600.0f,
		0.1f,
		100.0f
	);

	const glm::mat4 view_matrix = glm::lookAt(
		glm::vec3(0.0f, 1.5f, 5.0f),
		glm::vec3(0.0f, 1.5f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	program.use();

	glUniformMatrix4fv(
		uniform_projectionMatrix,
		1, GL_FALSE, &projection_matrix[0][0]
	);

	glUniformMatrix4fv(
		uniform_viewMatrix,
		1, GL_FALSE, &view_matrix[0][0]
	);

	return true;
}

void SimpleRenderer::begin()
{
	Renderer::begin();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
}

void SimpleRenderer::end()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
}