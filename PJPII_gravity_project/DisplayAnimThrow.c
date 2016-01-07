#include "Header.h"

void DisplayAnimThrow()
{

	//start = true;
	//SlowMotion = SLOWMO_TRUE;

	//printf("\n\nWeight: %i\nVelocity: %i\nAngle: %i\n", InitData[DTThrowWeight], InitData[DTThrowVelocity], InitData[DTThrowAngle]);

	glClearColor(153.0f / 255.0f,
		217.0f / 255.0f,
		234.0f / 255.0f,
		1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//ground
	glColor4f(34.0f / 255.0f,
		177.0f / 255.0f,
		76.0f / 255.0f,
		1.0f);


	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(800.0, 200.0);
	glVertex2f(800.0f, 0.0f);
	glEnd();
	//end ground



	//additional buttons and info for events of animation

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[BACK].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(30.0, 50.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(30.0, 50.0f - AdditionalTextTextures[BACK].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(30.0 + AdditionalTextTextures[BACK].w, 50.0 - AdditionalTextTextures[BACK].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(30.0 + AdditionalTextTextures[BACK].w, 50.0);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[SlowMotion].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(200.0, 550.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(200.0, 550.0f - AdditionalTextTextures[SlowMotion].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(200.0 + AdditionalTextTextures[SlowMotion].w, 550.0 - AdditionalTextTextures[SlowMotion].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(200.0 + AdditionalTextTextures[SlowMotion].w, 550.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[START].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(200.0, 500.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(200.0, 500.0f - AdditionalTextTextures[START].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(200.0 + AdditionalTextTextures[START].w, 500.0 - AdditionalTextTextures[START].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(200.0 + AdditionalTextTextures[START].w, 500.0);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[RANGE].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(570.0, 550.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(570.0, 550.0f - AdditionalTextTextures[RANGE].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(570.0 + AdditionalTextTextures[RANGE].w, 550.0 - AdditionalTextTextures[RANGE].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(570.0 + AdditionalTextTextures[RANGE].w, 550.0);
	glEnd();



	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	//end of additional buttons for events of animation



	if (start == true)
	{
		if (tempint < ThrowPositionAmount)
		{
			if (SlowMotion == SLOWMO_TRUE)
			{
				tempint += InitData[DTThrowVelocity] * 100 / FPS;
			}
			else
			{
				tempint += InitData[DTThrowVelocity] * 1000 / FPS;
			}
		}

		if (tempint > ThrowPositionAmount)
		{
			tempint = ThrowPositionAmount;
		}


		if (tempint > 3500 && tempint < ThrowPositionAmount)
		{
			glTranslatef(350 - (int)tempint / 10, 0.0, 0.0);
		}
	}

	//scalling with +- and moving with mouse
	if (tempint == ThrowPositionAmount && tempint > 3500)
	{
		if (scaleflag == false)
		{
			xrel = (int)-tempint / 10 + 350;
			scaleflag = true;
		}

		if (scaleflag == true)
		{
			if (xrel >= 200)
			{
				xrel = 200 - 1;
			}
			if ((float)xrel <= -(float)(AmountOfRange * 100.) * (float)KRscale)
			{
				xrel = (int)-(AmountOfRange * 100.) * KRscale + 1.;
			}

			glTranslatef((float)xrel, 0.0f, 0.0f);
			glScalef(KRscale, KRscale, KRscale);
		}

	}
	//end of scalling and moving





	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_MULTISAMPLE);



	glBegin(GL_LINES);

	//black
	glColor4f(0.0f,
		0.0f,
		0.0f,
		1.0f);

	glVertex2f(200.0f, 100.0f);
	glVertex2f(300.0f + ThrowPositionAmount / 10, 100.0f);

	for (i = 0; i < ThrowPositionAmount / 10 + 100; i += 100)
	{
		glVertex2f(200.0f + (float)i, 100.0f);
		glVertex2f(200.0f + (float)i, 90.0f);

	}

	glEnd();


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	glBindTexture(GL_TEXTURE_2D, Ball);
	glBegin(GL_QUADS);

	if (start == true)
	{

		if (tempint < ThrowPositionAmount)
		{

			//printf("tempint: %i ; ThrowPosition[tempint] : %f\n", tempint, ThrowPosition[tempint]);
			// SDL_Delay(1000);

			glTexCoord2f(0.0, 0.0); glVertex2f(175.0f + (tempint * 0.1f), 100.0f + ThrowPosition[tempint] * 100);
			glTexCoord2f(0.0, 1.0); glVertex2f(175.0f + (tempint * 0.1f), 150.0f + ThrowPosition[tempint] * 100);
			glTexCoord2f(1.0, 1.0); glVertex2f(225.0f + (tempint * 0.1f), 150.0f + ThrowPosition[tempint] * 100);
			glTexCoord2f(1.0, 0.0); glVertex2f(225.0f + (tempint * 0.1f), 100.0 + ThrowPosition[tempint] * 100);
		
		}

		else
		{
			//printf("tempint: %i ; ThrowPosition[tempint] : %f\n", tempint, ThrowPosition[tempint-1]);
				//SDL_Delay(1000);
			glTexCoord2f(0.0, 0.0); glVertex2f(175.0f + (tempint * 0.1f), 100.0f + ThrowPosition[tempint-1] * 100);
			glTexCoord2f(0.0, 1.0); glVertex2f(175.0f + (tempint * 0.1f), 150.0f + ThrowPosition[tempint-1] * 100);
			glTexCoord2f(1.0, 1.0); glVertex2f(225.0f + (tempint * 0.1f), 150.0f + ThrowPosition[tempint-1] * 100);
			glTexCoord2f(1.0, 0.0); glVertex2f(225.0f + (tempint * 0.1f), 100.0 + ThrowPosition[tempint-1] * 100);
		}
		

	}

	else
	{
		glTexCoord2f(0.0, 0.0); glVertex2f(175.0f, 100.0f);
		glTexCoord2f(0.0, 1.0); glVertex2f(175.0f, 150.0f);
		glTexCoord2f(1.0, 1.0); glVertex2f(225.0f, 150.0f);
		glTexCoord2f(1.0, 0.0); glVertex2f(225.0f, 100.0f);
	}

	glEnd();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (i = 0; i < AmountOfRange + 1; i++)
	{
		glBindTexture(GL_TEXTURE_2D, RangeTexture[i].Texture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + i * 100, 90.0f);
		glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + i * 100, 90.0f - RangeTexture[i].h);
		glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + i * 100 + RangeTexture[i].w, 90.0 - RangeTexture[i].h);
		glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + i * 100 + RangeTexture[i].w, 90.0);
		glEnd();

	}

	glBindTexture(GL_TEXTURE_2D, RangeTexture[i].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(170.0 + i * 100, 90.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(170.0 + i * 100, 90.0f - RangeTexture[i].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(170.0 + i * 100 + RangeTexture[i].w, 90.0 - RangeTexture[i].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(170.0 + i * 100 + RangeTexture[i].w, 90.0);
	glEnd();

	//getch();

	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	Events();

	//MouseEvents();












}