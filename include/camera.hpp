#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glew.h>
#include <glm/vec3.hpp>

struct Camera
{
	enum Direction { Forward, Back, Left, Right };

	Camera();
	void look(const glm::vec3 &target);
	void move(Direction direction, GLfloat amount);
	glm::vec3 position;
	GLfloat pitch;
	GLfloat yaw;
};

#endif