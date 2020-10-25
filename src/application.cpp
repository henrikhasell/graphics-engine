#include "application.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "simple.hpp"
#include "model.hpp"
#include "loader.hpp"
#include "configuration.hpp"
#include "bitmap_text.hpp"

Renderer *main_renderer;
Renderer *text_renderer;
Texture *blank_texture;
Texture *font_texture;
Camera *camera;
Model *square;
Model *teapot;

void Application_Initialise()
{
	glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    main_renderer = new SimpleRenderer();
    main_renderer->initialise("shaders/simple_vertex.glsl", "shaders/simple_fragment.glsl");

    text_renderer = new TextRenderer();
    text_renderer->initialise("shaders/text_vertex.glsl", "shaders/text_fragment.glsl");

    blank_texture = new Texture();

	font_texture = new Texture();
	font_texture->load("font.png");
/*
    const Vertex2D vertices_square[] = {
        {{-0.5f, 0.5f }, { 0.0f, 0.0f}},
        {{ 0.5f, 0.5f }, { 1.0f, 0.0f}},
        {{ 0.5f,-0.5f }, { 1.0f, 1.0f}},
        {{-0.5f,-0.5f }, { 0.0f, 1.0f}}
    };
*/
    const Vertex2D vertices_square[] = {
        {{ 0.0f, 400.0f }, { 0.0f, 1.0f}},
        {{ 400.0f, 400.0f }, { 1.0f, 1.0f}},
        {{ 400.0f, 0.0f }, { 1.0f, 0.0f}},
        {{ 0.0f, 0.0f }, { 0.0f, 0.0f}}
    };

    const GLuint indices_square[] = { 0, 1, 3, 1, 2, 3 };

	square = new Model();
	square->data<Vertex2D>(vertices_square, indices_square, 4, 6);

	teapot = new Model();
	Model_Load(teapot, "teapot.obj");

	camera = new Camera();

	load_configuration("configuration.yml");
}

void Application_Cleanup()
{
	delete teapot;
	delete square;
    delete blank_texture;
    delete font_texture;
	delete main_renderer;
	delete camera;
}

void Application_TimeStep()
{

}

void Application_DrawFrame()
{
	main_renderer->begin();
        blank_texture->bind(GL_TEXTURE0);
        //teapot->draw();
    main_renderer->end();

    glClear(GL_DEPTH_BUFFER_BIT);

    text_renderer->begin();
         font_texture->bind(GL_TEXTURE0);
         square->draw();
    text_renderer->end();
}

void Application_HandleKeyPress(const SDL_KeyboardEvent* event)
{

}

void Application_HandleKeyRelease(const SDL_KeyboardEvent* event)
{

}
