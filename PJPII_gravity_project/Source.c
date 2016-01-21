#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"



int main(int argc, char * argv[])
{
	int j;



	InitData[DTWater] = 0;


	if (!init())
	{
		printf("Failed to initialize!\n");
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	

	if (!loadMedia())
	{
			printf("Failed to load media!\n");
	}


	//While app is running
	while (!quit)
	{
		StartTimer = SDL_GetTicks();

		DisplayFunc();

		if (1000 / FPS > SDL_GetTicks() - StartTimer)
		{
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - StartTimer));
		}


	}

	close();


	return 0;
}