#include "Header.h"

void close()
{
	int i;

	for (i = 0; i < I_TOTAL; i++)
	{
		SDL_FreeSurface(InterfaceSurface[i]);
		InterfaceSurface[i] = NULL;
	}



	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}