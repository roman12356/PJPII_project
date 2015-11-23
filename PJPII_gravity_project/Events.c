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



		}
				


	}


}