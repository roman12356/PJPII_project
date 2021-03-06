#include "functions.h"
#include "globals.h"

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Antyaliasing
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 2);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 6);

		
		//Use OpenGL 3.1 core
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		//Create window

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		/* Enable smooth shading */
		glShadeModel(GL_SMOOTH);

		/* Set the background red */

		/* Depth buffer setup */
		glClearDepth(1.0f);

		/* Enables Depth Testing */
		glEnable(GL_DEPTH_TEST);

		/* The Type Of Depth Test To Do */
		glDepthFunc(GL_LEQUAL);


		window = SDL_CreateWindow("Grawitacja dla gimnazjum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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

			glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -20.0, 20.0);

		}



	}

	InitDataText = (char**)malloc(sizeof(char*)*DTTotal);
	for (i = 0; i < DTTotal; i++)
		InitDataText[i] = (char*)malloc(sizeof(char)* 5);

	int j;

	for (i = 0; i < DTTotal; i++)
	{
		for (j = 0; j < 5; j++)
			InitDataText[i][j] = 0;
	}

	return success;
}