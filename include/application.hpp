#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include "model.hpp"
#include "simple.hpp"
#include "texture.hpp"

class Application
{
public:
    virtual ~Application() = default;

	virtual void time_step() = 0;
	virtual void draw_frame() = 0;
	virtual void handle_key_up(const SDL_KeyboardEvent &event) = 0;
	virtual void handle_key_down(const SDL_KeyboardEvent &event) = 0;
};

class TestApplication : public Application
{
protected:
    TextRenderer ui_renderer;
    Texture font_texture;
    Model text_model;
public:
    TestApplication();
    ~TestApplication() override;

    void time_step() override;
    void draw_frame() override;
    void handle_key_up(const SDL_KeyboardEvent &event) override;
    void handle_key_down(const SDL_KeyboardEvent &event) override;
};

void Application_Initialise();

void Application_Cleanup();

void Application_TimeStep();

void Application_DrawFrame();

void Application_HandleKeyPress(const SDL_KeyboardEvent* event);

void Application_HandleKeyRelease(const SDL_KeyboardEvent* event);

#endif
