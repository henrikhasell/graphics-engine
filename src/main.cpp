#include <cstdio>
#ifdef _WIN32
#   include <Windows.h>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include "application.hpp"

#define WINDOW_TITLE "Example OpenGL Context"
#define WINDOW_W 800
#define WINDOW_H 600
#define TIME_STEP 200

bool load_submodules()
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG)
        {
            return true;
        }
        else
        {
            fprintf(stderr, "IMG_Init: %s\n", IMG_GetError());
        }

        SDL_Quit();
    }
    else
    {
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
    }

    return false;
}

int main(int argc, char* argv[])
{
	SDL_version version;
	SDL_GetVersion(&version);

	printf("Linked against SDL version %d.%d.%d\n",
		version.major,
		version.minor,
		version.patch
	);

	SDL_Window* window = NULL;
	SDL_GLContext context = NULL;

	if (load_submodules())
	{
		window = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WINDOW_W,
			WINDOW_H,
			SDL_WINDOW_OPENGL
		);

		if (window)
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

			context = SDL_GL_CreateContext(window);

			if (context)
			{
				GLenum glewStatus = glewInit();

				if (glewStatus == GLEW_OK)
				{
					Uint32 time_prev = SDL_GetTicks();
					Uint32 time_curr;

					bool finished = false;
					Application_Initialise();

					while (!finished)
					{
						SDL_Event event;

						while (SDL_PollEvent(&event) != 0)
						{
							if (event.type == SDL_QUIT)
							{
								finished = true;
							}
							else if (event.type == SDL_KEYUP)
							{
								Application_HandleKeyRelease(&event.key);
							}
							else if (event.type == SDL_KEYDOWN)
							{
								Application_HandleKeyPress(&event.key);
							}
						}

						for (time_curr = SDL_GetTicks(); time_curr - time_prev > TIME_STEP; time_prev += TIME_STEP)
						{
							Application_TimeStep();
						}

						glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
						Application_DrawFrame();
						SDL_GL_SwapWindow(window);
					}

					Application_Cleanup();
				}
				else
				{
					fprintf(stderr, "glewInit: %s\n", glewGetErrorString(glewStatus));
				}

				SDL_GL_DeleteContext(context);
			}
			else
			{
				fprintf(stderr, "SDL_GL_CreateContext: %s\n", SDL_GetError());
			}

			SDL_DestroyWindow(window);
		}
		else
		{
			fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError());
		}

		IMG_Quit();
		SDL_Quit();
	}

	return (window && context) ? EXIT_SUCCESS : EXIT_FAILURE;
}
