#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
/*
class Application
{
public:
	Application();
	virtual ~Application() = default;
	virtual void time_step();
	virtual void draw_frame();
	virtual void handle_key_up(const SDL_KeyboardEvent* event);
	virtual void handle_key_down(const SDL_KeyboardEvent* event);
};
*/
void Application_Initialise();

void Application_Cleanup();

void Application_TimeStep();

void Application_DrawFrame();

void Application_HandleKeyPress(const SDL_KeyboardEvent* event);

void Application_HandleKeyRelease(const SDL_KeyboardEvent* event);

#endif
