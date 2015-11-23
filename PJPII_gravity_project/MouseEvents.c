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
				if (mousex > Button_Main1.x && mousex < Button_Main1.x + Button_Main1.width
					&& mousey > Button_Main1.y && mousey < Button_Main1.y + Button_Main1.height)
				{
					InterfaceType = I_WATER;
				}

				if (mousex > Button_Main2.x && mousex < Button_Main2.x + Button_Main2.width
					&& mousey > Button_Main2.y && mousey < Button_Main2.y + Button_Main2.height)
				{
					InterfaceType = I_THROW;
				}

				if (mousex > Button_Main3.x && mousex < Button_Main3.x + Button_Main3.width
					&& mousey > Button_Main3.y && mousey < Button_Main3.y + Button_Main3.height)
				{
					InterfaceType = I_ORBIT;
				}

				break;

			case I_WATER:
				if (mousex > Button_Back.x && mousex < Button_Back.x + Button_Back.width
					&& mousey > Button_Back.y && mousey < Button_Back.y + Button_Back.height)
				{
					InterfaceType = I_MAIN;
				}
				break;

			case I_THROW:
				if (mousex > Button_Back.x && mousex < Button_Back.x + Button_Back.width
					&& mousey > Button_Back.y && mousey < Button_Back.y + Button_Back.height)
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