#include "Header.h"

void close()
{
//	int i;

	glDeleteTextures(I_TOTAL, InterfaceSurface);

/*	for (i = 0; i < I_TOTAL; i++)
	{
		InterfaceSurface[i] = NULL;
	}*/



	SDL_DestroyWindow(window);
	window = NULL;

	free(WaterPosition);
//	free(RangeTexture);

	SDL_Quit();
}