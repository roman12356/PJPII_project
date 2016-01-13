#include "Header.h"

bool CheckButton(Button_S *button)
{
	bool success = false;
	if (mousex > (*button).x && mousex < (*button).x + (*button).width
		&& mousey >(*button).y && mousey < (*button).y + (*button).height)
	{
		success = true;
	}

		while (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT)
		{
			ev.type = NULL;
			ev.button.button = NULL;

		}


	return success;
}