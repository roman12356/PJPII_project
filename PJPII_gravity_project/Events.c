#include "functions.h"
#include "globals.h"

void Events()
{
	while (SDL_PollEvent(&ev) != 0)
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		case SDL_KEYDOWN:
			if (ev.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}

			if (InterfaceType == I_WATER && ev.key.keysym.sym == SDLK_RETURN  && text[1] != '\0')
			{
				InterfaceType = I_ANIM_WATER;
			}

			if (ev.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (strlen(text)>0)
				{
					text[strlen(text) - 1] = '\0';
				}
			}
			break;

		case SDL_TEXTINPUT:
			if (InterfaceType == I_WATER)
			{
				if (strlen(text) < 5)
				{
					strncpy(buffer, ev.text.text, 1);

					if (buffer[0] > 47 && buffer[0] < 58)
					{
						strcat(text, buffer);
					}
				}


				height = atoi(text);

				printf("%c, %i\n", buffer[0], height);
			}
			break;

		default:
			break;


		}

		
				


	}


}