#include "Header.h"



int main(int argc, char * argv[])
{


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
			
		//Events();


		DisplayFunc();

	}

	close();

	return 0;
}