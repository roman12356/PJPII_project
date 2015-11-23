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

	if (!(LoadGLTextures(&InterfaceSurface[I_THROW], "bmp/interface3.bmp")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}


	if (!(LoadGLTexturesPNG(&AdditionalTextures[back], "png/next.png")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}

	if (!(LoadGLTexturesPNG(&AdditionalTextures[giggles], "png/giggles.png")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}

	if (!(LoadGLTexturesPNG(&AdditionalTextures[water], "png/glass.png")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
		success = false;
	}
	


	return success;
}