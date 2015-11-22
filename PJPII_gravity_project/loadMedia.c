#include "globals.h"
#include "functions.h"

bool loadMedia()
{

	bool success = true;

	if (!(LoadGLTextures(&texture, "bmp/Happy_face.bmp")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
	}



	InterfaceSurface[I_MAIN] = loadSurface("bmp/interface1.bmp");
	if (InterfaceSurface[I_MAIN] == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "bmp/interface1.bmp", SDL_GetError());
		success = false;
	}

	InterfaceSurface[I_WATER] = loadSurface("bmp/interface2.bmp");
	if (InterfaceSurface[I_WATER] == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "bmp/interface2.bmp", SDL_GetError());
		success = false;
	}

	


	return success;
}