#include "application.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "simple.hpp"
#include "model.hpp"
#include "loader.hpp"
#include "configuration.hpp"

Renderer *renderer;
Texture *texture;
Camera *camera;
Model *triangle;
Model *teapot;

void Application_Initialise()
{
	glEnable(GL_DEPTH_TEST);

	renderer = new SimpleRenderer();
	renderer->initialise("shaders/simple_vertex.glsl", "shaders/simple_fragment.glsl");

	texture = new Texture();

	const Vertex vertices[] = {
		{{-0.5f,-0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f}, { 0.0f, 0.0f }},
		{{ 0.5f,-0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f}, { 1.0f, 0.0f }},
	    {{ 0.0f, 0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f}, { 0.5f, 1.0f }}
	};

	const GLuint indices[] = { 0, 1, 2 };

	triangle = new Model();
	triangle->data(vertices, indices, 3, 3);

	teapot = new Model();
	Model_Load(teapot, "teapot.obj");

	camera = new Camera();

	load_configuration("configuration.yml");
}

void Application_Cleanup()
{
	delete teapot;
	delete triangle;
	delete texture;
	delete renderer;
	delete camera;
}

void Application_TimeStep()
{

}
void Application_DrawFrame()
{
	renderer->begin();
	teapot->draw();
	renderer->end();
}

void Application_HandleKeyPress(const SDL_KeyboardEvent* event)
{

}

void Application_HandleKeyRelease(const SDL_KeyboardEvent* event)
{

}
