#include "functions.h"
#include "globals.h"

void Display()
{


	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);









}