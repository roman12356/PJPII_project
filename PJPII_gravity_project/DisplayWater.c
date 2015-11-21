#include "globals.h"

void DisplayWater()
{

	SDL_BlitSurface(InterfaceSurface[I_WATER], NULL, gScreenSurface, NULL);

	SDL_UpdateWindowSurface(window);

	Events();





}