#include "functions.h"
#include "globals.h"

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		
		//Use OpenGL 3.1 core
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		//Create window

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		/* Enable smooth shading */
		glShadeModel(GL_SMOOTH);

		/* Set the background red */
		//glClearColor(136.0f / 255.0f, 0.0f, 21.0f / 255.0f, 1.0f);

		/* Depth buffer setup */
		glClearDepth(1.0f);

		/* Enables Depth Testing */
		glEnable(GL_DEPTH_TEST);

		/* The Type Of Depth Test To Do */
		glDepthFunc(GL_LEQUAL);

		/* Really Nice Perspective Calculations */
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create context
			gContext = SDL_GL_CreateContext(window);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize GLEW
				glewExperimental = GL_TRUE;
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK)
				{
					printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
				}

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else

				//use Vsync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}
				else
				if (TTF_Init() == -1)
				{
					printf("TTF_Init: %s\n", TTF_GetError());
					success = false;
				}
			}

			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(window);

			glMatrixMode(GL_PROJECTION);

			glLoadIdentity();

			glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -2.0, 2.0);
		}



	}

	return success;
}