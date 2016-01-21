#include "Header.h"

void close()
{

	glDeleteTextures(I_TOTAL, InterfaceSurface);



	SDL_DestroyWindow(window);
	window = NULL;

	free(WaterPosition);
	free(ThrowPositionY);
	free(ThrowPositionX);

	for (i = 0; i < DTTotal; i++)
	{
		free(InitDataText[i]);
	}
	free(InitDataText);

	SDL_Quit();
}