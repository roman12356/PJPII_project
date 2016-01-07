#include "Header.h"

void MouseEvents()
{

	if (ev.type == SDL_MOUSEMOTION && ev.button.button == SDL_BUTTON_LEFT && (InterfaceType == I_ANIM_WATER || InterfaceType == I_ANIM_THROW))
	{		
		if ((xrel <= 200) && (xrel >= -(AmountOfRange * 100)))
		{
			xrel += ev.motion.xrel;
		}
	}


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
					InterfaceType = I_COUNT_ANIM_WATER;
				}
				if (CheckButton(&Button_Data_Water))
				{
					printf("dobszWater\n");
					SDL_StartTextInput();
					ActiveInitField = DTWater;
				}
				else
				{
					SDL_StopTextInput();
					printf("stopText\n");
				}
				break;

			case I_THROW:
				if (CheckButton(&Button_Back))
				{
					InterfaceType = I_MAIN;
				}

				else if (CheckButton(&Button_Data_ThrowWeight))
				{
					printf("dobszWeiht\n");
					SDL_StartTextInput();
					ActiveInitField = DTThrowWeight;
				}
				else if (CheckButton(&Button_Data_ThrowVelocity))
				{
					printf("dobszVelo\n");
					SDL_StartTextInput();
					ActiveInitField = DTThrowVelocity;
				}
				else if (CheckButton(&Button_Data_ThrowAngle))
				{
					printf("dobszAngle\n");
					SDL_StartTextInput();
					ActiveInitField = DTThrowAngle;
				}
				else if (CheckButton(&Button_Next))
				{
					InterfaceType = I_COUNT_ANIM_THROW;
				}
				else
				{
					CheckButton(&Button_Empty);
					SDL_StopTextInput();
					printf("stopText\n");
				}
				break;

			case I_ANIM_WATER:
				if (CheckButton(&Button_Powrot))
				{
					InterfaceType = I_MAIN;
				}
				else if (CheckButton(&Button_Slowmo))
				{
					if (SlowMotion == SLOWMO_TRUE)
					{
						SlowMotion = SLOWMO_FALSE;
					}
					else
					{
						SlowMotion = SLOWMO_TRUE;
					}
				}
				else if (CheckButton(&Button_Start))
				{
					scaleflag = false;
					xrel = 0;
					KRscale = 1.0f;
					tempint = 0;
					start = true;
				}

				break;

			case I_ANIM_THROW:

				if (CheckButton(&Button_Powrot))
				{
					InterfaceType = I_MAIN;
				}
				else if (CheckButton(&Button_Slowmo))
				{
					if (SlowMotion == SLOWMO_TRUE)
					{
						SlowMotion = SLOWMO_FALSE;
					}
					else
					{
						SlowMotion = SLOWMO_TRUE;
					}
				}
				else if (CheckButton(&Button_Start))
				{
					scaleflag = false;
					xrel = 0;
					KRscale = 1.0f;
					tempint = 0;
					start = true;
				}

				break;


			default:
				printf("nie\n");
				CheckButton(&Button_Empty);
				break;


		}

	}












}