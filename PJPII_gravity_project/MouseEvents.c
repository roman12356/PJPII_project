#include "Header.h"

void MouseEvents()
{
	if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button ==  SDL_BUTTON_LEFT)
	{
		//Get Mouse Position
		SDL_GetMouseState(&mousex, &mousey);
		printf("x: %i y: %i\n", mousex, mousey);

		switch (InterfaceType)
		{
			case I_MAIN:
				if (CheckButton(&Button_Main1))
				{
					InterfaceType = I_WATER;
				}

				if (CheckButton(&Button_Main2))
				{
					InterfaceType = I_THROW;
				}

				if (CheckButton(&Button_Main3))
				{
					InterfaceType = I_ORBIT;
				}

				break;

			case I_WATER:
				if (CheckButton(&Button_Back))
				{
					InterfaceType = I_MAIN;
				}
				else
				if (CheckButton(&Button_Next))
				{
					InterfaceType = I_ANIM_WATER;
				}
				break;

			case I_THROW:
				if (CheckButton(&Button_Back))
				{
					InterfaceType = I_MAIN;
				}
				break;


			default:
				printf("nie\n");
				printf("x: %i y: %i width: %i height: %i\n", Button_Main1.x, Button_Main1.y, Button_Main1.width, Button_Main1.height);
				break;


		}

	}












}