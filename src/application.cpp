#include "application.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "simple.hpp"
#include "model.hpp"
#include "loader.hpp"
#include "configuration.hpp"
#include "bitmap_text.hpp"

SimpleRenderer *main_renderer;
Renderer *text_renderer;
Texture *blank_texture;
Texture *font_texture;
Camera *camera;
Model *square;
Model *teapot;
Model *test_model;

TestApplication::TestApplication()
{
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.4f, 0.4f, 1.0f, 1.0f);

    ui_renderer.initialise("shaders/2d_vertex.glsl", "shaders/2d_fragment.glsl");
    font_texture.load("font.png");

    BitmapText::Factory text_factory(256, 144, BitmapText::simple_bitmap_text);
    text_factory.addRow(0, 0, "Hello, world!");
    text_factory.addRow(0, 20, "Second row.");

    text_factory.updateModel(text_model);
}

TestApplication::~TestApplication() = default;

void TestApplication::time_step()
{

}

void TestApplication::draw_frame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui_renderer.begin();
    text_model.draw(ui_renderer);
    ui_renderer.end();
}

void TestApplication::handle_key_up(const SDL_KeyboardEvent &event)
{

}

void TestApplication::handle_key_down(const SDL_KeyboardEvent &event)
{

}

void Application_Initialise()
{
	glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    main_renderer = new SimpleRenderer();
    main_renderer->initialise("shaders/simple_vertex.glsl", "shaders/simple_fragment.glsl");

    text_renderer = new TextRenderer();
    text_renderer->initialise("shaders/2d_vertex.glsl", "shaders/2d_fragment.glsl");

    blank_texture = new Texture();

    font_texture = new Texture();
    font_texture->load("font.png");

	BitmapText::Factory meshBuilder(256, 144, BitmapText::simple_bitmap_text);

    const Vertex2D vertices_square[] = {
        {{ 20.0f, 120.0f }, { 0.0f, 1.0f}},
        {{ 120.0f, 120.0f }, { 1.0f, 1.0f}},
        {{ 120.0f, 20.0f }, { 1.0f, 0.0f}},
        {{ 20.0f, 20.0f }, { 0.0f, 0.0f}}
    };

    const Vertex2D H[] = {
        {{ 0.0f, 0.0f }, { 0.5f, 0.333333f }},
        {{ 12.0f, 0.0f }, { 0.546875f, 0.333333f }},
        {{ 0.0f, 20.0f }, { 0.5f, 0.472222f }},
        {{ 12.0f, 20.0f }, { 0.546875, 0.472222 }}
    };

    const GLuint H_indices[] = {
        0, 1, 2, 1, 3, 2
    };


    const GLuint indices_square[] = { 0, 1, 3, 1, 2, 3 };

    test_model = new Model();
    meshBuilder.addRow(0, 0 , "This, is a test! This; is a test. :)");
    meshBuilder.updateModel(*test_model);


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

    glBindTexture(GL_TEXTURE_2D, 0);
    blank_texture->bind();

	main_renderer->begin();

    blank_texture->bind();
    teapot->draw(*main_renderer);

    main_renderer->end();

    glClear(GL_DEPTH_BUFFER_BIT);

    text_renderer->begin();

        blank_texture->bind();
        square->draw(*text_renderer);

        font_texture->bind();
        test_model->draw(*text_renderer);

    text_renderer->end();

    // printf("Error: %d\n", glGetError());
}

void Application_HandleKeyPress(const SDL_KeyboardEvent* event)
{
    switch(event->keysym.sym)
    {
        case SDL_SCANCODE_W:
            break;
        case SDL_SCANCODE_S:
            break;
        case SDL_SCANCODE_A:
            break;
        case SDL_SCANCODE_D:
            break;
    }
}

void Application_HandleKeyRelease(const SDL_KeyboardEvent* event)
{

}
