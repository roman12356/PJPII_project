#include "Header.h"



int main(int argc, char * argv[])
{
	int j;

	InitDataText = (char**)malloc(sizeof(char*)*DTTotal);
	for (i = 0; i < DTTotal; i++)
		InitDataText[i] = (char*)malloc(sizeof(char)* 5);

	for (i = 0; i < DTTotal; i++)
	{
		for (j = 0; j < 5; j++)
			InitDataText[i][j] = 0;
	}

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
			
		Events();


		DisplayFunc();

	}

	close();

	return 0;
}