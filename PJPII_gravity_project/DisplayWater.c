#include "Header.h"

void DisplayWater()
{

	

	glClearColor(136.0f / 255.0f, 0.0f, 21.0f / 255.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	glColor4f(1.0, 0.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


		if (InitDataText[DTWater][0] == '\0')
	{
		InitDataText[DTWater][0] = ' ';
		InitDataText[DTWater][1] = '\0';
	}

		for (i = 0; i < strlen(InitDataText[DTWater]); i++)
		{
			//printf("\nstring: %i", InitDataText[DTWater][i]);
		}

		//getch();


	InitDataTexture[DTWater] = LoadFromRenderedText("fonts/arial.ttf", InitDataText[DTWater], 20, &textColor);


	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, InterfaceSurface[I_WATER]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(0.0, 600.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(800.0, 600.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(800.0, 0.0);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glBindTexture(GL_TEXTURE_2D, AdditionalTextures[back]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(600.0, 100.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(600.0, 200.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(700.0, 200.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(700.0, 100.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(200.0, 100.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(200.0, 200.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(100.0, 200.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(100.0, 100.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, AdditionalTextures[water]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(550.0, 250.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(550.0, 500.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(750.0, 500.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(750.0, 250.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, InitDataTexture[DTWater].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(270.0, 440.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(270.0, 440.0 - InitDataTexture[DTWater].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(270.0 + InitDataTexture[DTWater].w, 440.0 - InitDataTexture[DTWater].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(270.0 + InitDataTexture[DTWater].w, 440.0);
	glEnd();

	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);


	//SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	//printf("Count: %i\n", count++);

	//height1 = 10;
	//height2 = 0;
	angle = 0;

	

//	SDL_PumpEvents();
//	if (SDL_WaitEvent(&ev))
//	{

//		printf("Error: %s", SDL_GetError());

		Events();

		//MouseEvents();

//	}





}