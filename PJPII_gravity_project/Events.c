#include "functions.h"
#include "globals.h"

void Events()
{
	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.type == SDL_QUIT)
		{
			quit = true;
		}

		else

		if (ev.type == SDL_KEYDOWN)
		{
			if (ev.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}

			else

			if (InterfaceType == I_MAIN)
			{
				switch (ev.key.keysym.sym)
				{

				case SDLK_RIGHT:
					InterfaceType = I_WATER;
					break;

				default:
					break;

				}
			}

			else

			if (InterfaceType == I_WATER)
			{
				switch (ev.key.keysym.sym)
				{

				case SDLK_LEFT:
					InterfaceType = I_MAIN;
					break;

				default:
					break;

				}
			}



		}
				


	}


}