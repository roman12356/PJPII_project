#include "functions.h"
#include "globals.h"

void Events()
{
	while (SDL_PollEvent(&ev) != 0)
	{
		MouseEvents();


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

			if (InterfaceType == I_WATER && ev.key.keysym.sym == SDLK_RETURN  && InitDataText[DTWater][1] != '\0')
			{
				InterfaceType = I_COUNT_ANIM_WATER;
			}

			if (ev.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (ActiveInitField == DTWater)
				{
					if (strlen(InitDataText[DTWater]) > 0)
					{
						InitDataText[DTWater][strlen(InitDataText[DTWater]) - 1] = '\0';
					}
				}
				else if (ActiveInitField == DTThrowVelocity)
				{
					if (strlen(InitDataText[DTThrowVelocity]) > 0)
					{
						InitDataText[DTThrowVelocity][strlen(InitDataText[DTThrowVelocity]) - 1] = '\0';
						InitData[DTThrowVelocity] = atoi(InitDataText[DTThrowVelocity]);
					}
				}
				else if (ActiveInitField == DTThrowAngle)
				{
					if (strlen(InitDataText[DTThrowAngle]) > 0)
					{
						InitDataText[DTThrowAngle][strlen(InitDataText[DTThrowAngle]) - 1] = '\0';
						InitData[DTThrowAngle] = atoi(InitDataText[DTThrowAngle]);
					}
				}
			}

			if (InterfaceType == I_ANIM_WATER || InterfaceType == I_ANIM_THROW)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_KP_PLUS:
					if (KRscale < 1.0f)
						KRscale += 0.1f;
					break;

				case SDLK_EQUALS:
					if (ev.key.keysym.mod == KMOD_LSHIFT)
					{
						if (KRscale < 1.0f)
							KRscale += 0.1f;
					}
					break;

				case SDLK_KP_MINUS:
					if (KRscale > 0.2f)
						KRscale -= 0.1f;
					break;

				case SDLK_MINUS:
					if (KRscale > 0.2f)
						KRscale -= 0.1f;
					break;

				default:
					break;
				}
			}
			break;

		case SDL_TEXTINPUT:
			if (InterfaceType == I_WATER)
			{
				if (strlen(InitDataText[DTWater]) < 5)
				{
					strncpy(buffer, ev.text.text, 1);

					if (buffer[0] > 47 && buffer[0] < 58)
					{
						strcat(InitDataText[DTWater], buffer);
					}
				}

				if (InitDataText[DTWater][1] == 48)
				{
					InitDataText[DTWater][1] = '\0';
				}

				InitData[DTWater] = atoi(InitDataText[DTWater]);

			}


			if (InterfaceType == I_THROW)
			{
				switch (ActiveInitField)
				{

				case DTThrowVelocity:
					if (strlen(InitDataText[DTThrowVelocity]) < 4)
					{
						strncpy(buffer, ev.text.text, 1);

						if (buffer[0] > 47 && buffer[0] < 58)
						{
							strcat(InitDataText[DTThrowVelocity], buffer);
						}
					}


					InitData[DTThrowVelocity] = atoi(InitDataText[DTThrowVelocity]);
					break;

				case DTThrowAngle:
					if (strlen(InitDataText[DTThrowAngle]) < 3)
					{
						strncpy(buffer, ev.text.text, 1);

						if (InitData[DTThrowAngle] == 0 && buffer[0] > 48 && buffer[0] < 58)
						{
							strcat(InitDataText[DTThrowAngle], buffer);
						}
						else if (InitData[DTThrowAngle] == 9 && buffer[0] == 48)
						{
							strcat(InitDataText[DTThrowAngle], buffer);
						}
						else if (InitData[DTThrowAngle] > 0 && InitData[DTThrowAngle] < 9 && buffer[0] > 47 && buffer[0] < 58)
						{
							strcat(InitDataText[DTThrowAngle], buffer);
						}
					}


					InitData[DTThrowAngle] = atoi(InitDataText[DTThrowAngle]);
					break;



				default:
					break;
				}

			}

		default:
			break;
		}
	}

}