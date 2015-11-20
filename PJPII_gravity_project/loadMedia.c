#include "globals.h"
#include "functions.h"

bool loadMedia(char * filename)
{

	bool success = true;


	gHelloWorld = SDL_LoadBMP(filename);
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}