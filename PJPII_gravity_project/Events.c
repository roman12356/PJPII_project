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
				else if (ActiveInitField == DTThrowWeight)
				{
					if (strlen(InitDataText[DTThrowWeight]) > 0)
					{
						InitDataText[DTThrowWeight][strlen(InitDataText[DTThrowWeight]) - 1] = '\0';
					}
				}
				else if (ActiveInitField == DTThrowVelocity)
				{
					if (strlen(InitDataText[DTThrowVelocity]) > 0)
					{
						InitDataText[DTThrowVelocity][strlen(InitDataText[DTThrowVelocity]) - 1] = '\0';
					}
				}
				else if (ActiveInitField == DTThrowAngle)
				{
					if (strlen(InitDataText[DTThrowAngle]) > 0)
					{
						InitDataText[DTThrowAngle][strlen(InitDataText[DTThrowAngle]) - 1] = '\0';
					}
				}
			}

			if (InterfaceType == I_ANIM_WATER)
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
						printf("\nScale: %f", KRscale);
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

				

				printf("%c, %i\n", buffer[0], InitData[DTWater]);
			}


			if (InterfaceType == I_THROW)
			{
				switch (ActiveInitField)
				{
				case DTThrowWeight:
					if (strlen(InitDataText[DTThrowWeight]) < 5)
					{
						strncpy(buffer, ev.text.text, 1);

						if (buffer[0] > 47 && buffer[0] < 58)
						{
							strcat(InitDataText[DTThrowWeight], buffer);
						}
					}


					InitData[DTThrowWeight] = atoi(InitDataText[DTThrowWeight]);

					printf("%ThrowWeight: %c, %i\n", buffer[0], InitData[DTThrowWeight]);
					break;

				case DTThrowVelocity:
					if (strlen(InitDataText[DTThrowVelocity]) < 5)
					{
						strncpy(buffer, ev.text.text, 1);

						if (buffer[0] > 47 && buffer[0] < 58)
						{
							strcat(InitDataText[DTThrowVelocity], buffer);
						}
					}


					InitData[DTThrowVelocity] = atoi(InitDataText[DTThrowVelocity]);

					printf("%ThrowVelocity: %c, %i\n", buffer[0], InitData[DTThrowVelocity]);
					break;

				case DTThrowAngle:
					if (strlen(InitDataText[DTThrowAngle]) < 3)
					{
						strncpy(buffer, ev.text.text, 1);

						if (buffer[0] > 47 && buffer[0] < 58)
						{
							//if (InitData[DTThrowAngle] == 0)
							strcat(InitDataText[DTThrowAngle], buffer);
						}
					}


					InitData[DTThrowAngle] = atoi(InitDataText[DTThrowAngle]);

					printf("%ThrowAngle: %c, %i\n", buffer[0], InitData[DTThrowAngle]);
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