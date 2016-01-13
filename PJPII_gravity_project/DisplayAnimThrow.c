#include "Header.h"

void DisplayAnimThrow()
{
	glPushMatrix();

	glClearColor(153.0f / 255.0f,
		217.0f / 255.0f,
		234.0f / 255.0f,
		1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLineWidth(2 * KRscale);


	//ground
	glColor4f(34.0f / 255.0f,
		177.0f / 255.0f,
		76.0f / 255.0f,
		1.0f);



	glBegin(GL_QUADS);
	if (ThrowPositionY[tempint] > 3.0 && tempint <= ThrowPositionAmount)
	{

		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 300.0 - (ThrowPositionY[tempint] - 3.0) * KRscale * 10);
		glVertex2f(800.0, 300.0 - (ThrowPositionY[tempint] - 3.0) * KRscale * 10);
		glVertex2f(800.0f, 0.0f);
	}
	else
	{
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 300.0);
		glVertex2f(800.0, 300.0);
		glVertex2f(800.0f, 0.0f);
	}
	glEnd();
	//end ground


	glPushMatrix();
	glTranslatef(-170.0, 25.0, 0.0);
	//additional buttons and info for events of animation

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


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


	sprintf(range, "Pozycja X: %.3f", ThrowPositionX[tempint]);
	AdditionalTextTextures[POS_X] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);


	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[POS_X].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(570.0, 500.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(570.0, 500.0f - AdditionalTextTextures[POS_X].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(570.0 + AdditionalTextTextures[POS_X].w, 500.0 - AdditionalTextTextures[POS_X].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(570.0 + AdditionalTextTextures[POS_X].w, 500.0);
	glEnd();

	glDeleteTextures(1, &AdditionalTextTextures[POS_X].Texture);

	sprintf(range, "Pozycja Y: %.3f", ThrowPositionY[tempint]);
	AdditionalTextTextures[POS_Y] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);


	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[POS_Y].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(570.0, 450.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(570.0, 450.0f - AdditionalTextTextures[POS_Y].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(570.0 + AdditionalTextTextures[POS_Y].w, 450.0 - AdditionalTextTextures[POS_Y].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(570.0 + AdditionalTextTextures[POS_Y].w, 450.0);
	glEnd();

	glDeleteTextures(1, &AdditionalTextTextures[POS_Y].Texture);

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, AdditionalTextTextures[BACK].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(30.0, 50.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(30.0, 50.0f - AdditionalTextTextures[BACK].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(30.0 + AdditionalTextTextures[BACK].w, 50.0 - AdditionalTextTextures[BACK].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(30.0 + AdditionalTextTextures[BACK].w, 50.0);
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
				tempint++;
			}
			else
			{
				tempint += 5;
			}
		}

		if (tempint > ThrowPositionAmount)
		{
			tempint = ThrowPositionAmount;
		}
	}


	if (ThrowPositionX[tempint] > 3.5 && tempint <= ThrowPositionAmount)
	{
		translatex = 350 - ThrowPositionX[tempint] * 100;
	}

	if (ThrowPositionY[tempint] > 2.5 && tempint <= ThrowPositionAmount)
	{
		translatey = 250 - ThrowPositionY[tempint] * 100;
		ThrowPositionYUp = true;
	}

	if (ThrowPositionYUp == true && tempint == ThrowPositionAmount)
	{
		translatey = 0.0;
	}

	glTranslatef(translatex * KRscale, translatey * KRscale, 0.0);

	//scalling with +-
	glScalef(KRscale, KRscale, KRscale);

	//end of scalling and moving





	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_MULTISAMPLE);


	//black
	glColor4f(0.0f,
		0.0f,
		0.0f,
		1.0f);

	glBegin(GL_LINES);

	glVertex2f(200.0f, 100.0f);
	glVertex2f(300.0f + ThrowPositionX[ThrowPositionAmount] * 100 + 100, 100.0f);

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
			glTexCoord2f(0.0, 0.0); glVertex2f(175.0f + ThrowPositionX[tempint] * 100, 100.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(0.0, 1.0); glVertex2f(175.0f + ThrowPositionX[tempint] * 100, 150.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(1.0, 1.0); glVertex2f(225.0f + ThrowPositionX[tempint] * 100, 150.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(1.0, 0.0); glVertex2f(225.0f + ThrowPositionX[tempint] * 100, 100.0 + ThrowPositionY[tempint] * 100);

		}

		else
		{
			glTexCoord2f(0.0, 0.0); glVertex2f(175.0f + ThrowPositionX[tempint] * 100, 100.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(0.0, 1.0); glVertex2f(175.0f + ThrowPositionX[tempint] * 100, 150.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(1.0, 1.0); glVertex2f(225.0f + ThrowPositionX[tempint] * 100, 150.0f + ThrowPositionY[tempint] * 100);
			glTexCoord2f(1.0, 0.0); glVertex2f(225.0f + ThrowPositionX[tempint] * 100, 100.0 + ThrowPositionY[tempint] * 100);
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



	int k = -1;
	if (translatex == 0)
	{
		for (i = 0; i < 40; i++)
		{

			if (i * 100 <= (int)ThrowPositionX[ThrowPositionAmount] * 100 + 100)
			{

				itoa(i * 100, &range, 10);
				RangeTexture[++k] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);

				glBindTexture(GL_TEXTURE_2D, RangeTexture[k].Texture);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + i * 100, 90.0f);
				glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + i * 100, 90.0f - RangeTexture[k].h);
				glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + i * 100 + RangeTexture[k].w, 90.0 - RangeTexture[k].h);
				glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + i * 100 + RangeTexture[k].w, 90.0);
				glEnd();

				glDisable(GL_BLEND);
				glDisable(GL_TEXTURE_2D);

				glBegin(GL_LINES);
				glVertex2f(200.0f + (float)i * 100, 100.0f);
				glVertex2f(200.0f + (float)i * 100, 90.0f);
				glEnd();

				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);

				glDeleteTextures(1, &RangeTexture[k].Texture);
			}
			else if (i * 100 <= (int)ThrowPositionX[ThrowPositionAmount] * 100 + 200)
			{
				RangeTexture[++k] = LoadFromRenderedText("fonts/arial.ttf", "[cm]", 20, &textColor);

				glBindTexture(GL_TEXTURE_2D, RangeTexture[k].Texture);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + i * 100, 90.0f);
				glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + i * 100, 90.0f - RangeTexture[k].h);
				glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + i * 100 + RangeTexture[k].w, 90.0 - RangeTexture[k].h);
				glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + i * 100 + RangeTexture[k].w, 90.0);
				glEnd();

				glDisable(GL_BLEND);
				glDisable(GL_TEXTURE_2D);

				glBegin(GL_LINES);
				glVertex2f(200.0f + (float)showtime * 100, 100.0f);
				glVertex2f(200.0f + (float)showtime * 100, 90.0f);
				glEnd();

				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);

				glDeleteTextures(1, &RangeTexture[k].Texture);
			}

		}
	}
	else
	{
		k = -1;
		for (showtime = (int)ceil(ThrowPositionX[tempint]) - 20; showtime < (int)ceil(ThrowPositionX[tempint]); showtime++)
		{
			if (showtime >= 0)
			{
				itoa(showtime * 100, &range, 10);
				RangeTexture[++k] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);

				glBindTexture(GL_TEXTURE_2D, RangeTexture[k].Texture);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + showtime * 100, 90.0f);
				glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + showtime * 100, 90.0f - RangeTexture[k].h);
				glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0 - RangeTexture[k].h);
				glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0);
				glEnd();

				glDisable(GL_BLEND);
				glDisable(GL_TEXTURE_2D);

				glBegin(GL_LINES);
				glVertex2f(200.0f + (float)showtime * 100, 100.0f);
				glVertex2f(200.0f + (float)showtime * 100, 90.0f);
				glEnd();

				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);

				glDeleteTextures(1, &RangeTexture[k].Texture);
			}
		}

		k = -1;
		for (; showtime < (int)ceil(ThrowPositionX[tempint]) + 40; showtime++)
		{
			if (showtime < (int)ceil(ThrowPositionX[ThrowPositionAmount]) + 1)
			{
				itoa(showtime * 100, &range, 10);
				RangeTexture[++k] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);

				glBindTexture(GL_TEXTURE_2D, RangeTexture[k].Texture);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + showtime * 100, 90.0f);
				glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + showtime * 100, 90.0f - RangeTexture[k].h);
				glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0 - RangeTexture[k].h);
				glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0);
				glEnd();

				glDisable(GL_BLEND);
				glDisable(GL_TEXTURE_2D);

				glBegin(GL_LINES);
				glVertex2f(200.0f + (float)showtime * 100, 100.0f);
				glVertex2f(200.0f + (float)showtime * 100, 90.0f);
				glEnd();

				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);

				glDeleteTextures(1, &RangeTexture[k].Texture);
			}
			else if (showtime < (int)ceil(ThrowPositionX[ThrowPositionAmount]) + 2)
			{
				RangeTexture[++k] = LoadFromRenderedText("fonts/arial.ttf", "[cm]", 20, &textColor);

				glBindTexture(GL_TEXTURE_2D, RangeTexture[k].Texture);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(190.0 + showtime * 100, 90.0f);
				glTexCoord2f(0.0, 1.0); glVertex2f(190.0 + showtime * 100, 90.0f - RangeTexture[k].h);
				glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0 - RangeTexture[k].h);
				glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + showtime * 100 + RangeTexture[k].w, 90.0);
				glEnd();

				glDisable(GL_BLEND);
				glDisable(GL_TEXTURE_2D);

				glBegin(GL_LINES);
				glVertex2f(200.0f + (float)showtime * 100, 100.0f);
				glVertex2f(200.0f + (float)showtime * 100, 90.0f);
				glEnd();

				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);

				glDeleteTextures(1, &RangeTexture[k].Texture);

			}
		}
	}


	glBindTexture(GL_TEXTURE_2D, showtimetexture.Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(190.0, 300.0f);
	glTexCoord2f(0.0, 1.0); glVertex2f(190.0, 300.0f - showtimetexture.h);
	glTexCoord2f(1.0, 1.0); glVertex2f(190.0 + showtimetexture.w, 300.0 - showtimetexture.h);
	glTexCoord2f(1.0, 0.0); glVertex2f(190.0 + showtimetexture.w, 300.0);
	glEnd();


	glDeleteTextures(1, &showtimetexture.Texture);


	glDisable(GL_BLEND);

	//vector
	glColor4f(244.0f / 255.0f,
		0.0f / 255.0f,
		0.0f / 255.0f,
		1.0f);

	if (tempint < ThrowPositionAmount)
	{
		RotateAngle = atan((ThrowPositionY[tempint + 1] - ThrowPositionY[tempint]) / (ThrowPositionX[tempint + 1] - ThrowPositionX[tempint]));
	}

	VectorLenght = 100;

	glBegin(GL_LINES);
	glVertex2f(200.0f + ThrowPositionX[tempint] * 100, 125.0f + ThrowPositionY[tempint] * 100);
	glVertex2f(200.0f + ThrowPositionX[tempint] * 100 + VectorLenght * cos(RotateAngle), 125.0f + ThrowPositionY[tempint] * 100 + VectorLenght * sin(RotateAngle));

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex2f(200.0f + ThrowPositionX[tempint] * 100 + VectorLenght * cos(RotateAngle), 125.0f + ThrowPositionY[tempint] * 100 + VectorLenght * sin(RotateAngle));

	glVertex2f(200.0f + ThrowPositionX[tempint] * 100 + (VectorLenght - 10) * cos(RotateAngle + 0.1),
		125.0f + ThrowPositionY[tempint] * 100 + (VectorLenght - 10) * sin(RotateAngle + 0.1));

	glVertex2f(200.0f + ThrowPositionX[tempint] * 100 + (VectorLenght - 10) * cos(RotateAngle - 0.1),
		125.0f + ThrowPositionY[tempint] * 100 + (VectorLenght - 10) * sin(RotateAngle - 0.1));

	glEnd();

	//End vector


	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	Events();




}