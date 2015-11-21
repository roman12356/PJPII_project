#include "functions.h"
#include "globals.h"

void DisplayMain()
{


	SDL_BlitSurface(InterfaceSurface[I_MAIN], NULL, gScreenSurface, NULL);

	SDL_UpdateWindowSurface(window);

	Events();






}