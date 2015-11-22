#include "globals.h"
#include "functions.h"

bool loadMedia()
{

	bool success = true;

	if (!(LoadGLTextures(&InterfaceSurface[I_MAIN], "bmp/interface1.bmp")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}



	if (!(LoadGLTextures(&InterfaceSurface[I_WATER], "bmp/interface2.bmp")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}

	


	return success;
}