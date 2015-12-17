#include "Header.h"

void DisplayAnimWater()
{
	static float angle2;

	

	


	glClearColor(153.0f / 255.0f,
				217.0f / 255.0f,
				234.0f / 255.0f,
				1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//floor
	glColor4f(185.0f / 255.0f,
		122.0f / 255.0f,
		87.0f / 255.0f,
		1.0f);

	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(800.0, 200.0);
	glVertex2f(800.0f, 0.0f);
	glEnd();
	//end floor


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
		if (tempint < WaterPositionAmount)
		{
			if (SlowMotion == SLOWMO_TRUE)
			{
				tempint += WaterVelocity(&InitData[DTWater]) * 100 / FPS;
			}
			else
			{
				tempint += WaterVelocity(&InitData[DTWater]) * 1000 / FPS;
			}
			printf("\ntempint: %f", 1 - (float)(tempint / 100000.));
		}

		if (tempint > WaterPositionAmount)
		{
			tempint = WaterPositionAmount;
		}


		if (tempint > 3500 && tempint < WaterPositionAmount)
		{
			glTranslatef(350 - (int)tempint / 10, 0.0, 0.0);
		}
	}

	//scalling with +- and moving with mouse
	if (tempint == WaterPositionAmount && tempint > 3500)
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


	//chair
	glLineWidth(10 * KRscale);
	glBegin(GL_LINES);

	//brown dark
	glColor4f(98.0f / 255.0f,
		83.0f / 255.0f,
		60.0f / 255.0f,
		1.0f);

	glVertex2f(120.0f, 100.0f);
	glVertex2f(120.0f, 290.0f);

	glVertex2f(190.0f, 100.0f);
	glVertex2f(190.0f, 290.0f);

	glVertex2f(120.0f, 286.0f);
	glVertex2f(190.0f, 286.0f);

	glEnd();
	//end chair

	
	//vessel
	glLineWidth(2 * KRscale);

	//dark purple - blue
	glColor4f(131.0f / 255.0f,
		153.0f / 255.0f,
		205.0f / 255.0f,
		1.0f);
	
	glBegin(GL_LINES);
	glVertex2f(110.0f, 300.0f);
	glVertex2f(110.0f, 325.0f + (float)InitData[DTWater]);

	glVertex2f(200.0f, 300.0f);
	glVertex2f(200.0f, 325.0f + (float)InitData[DTWater]);

	glVertex2f(120.0f, 290.0f);
	glVertex2f(190.0f, 290.0f);


	glEnd();


	//left and right circulated sides of vessel
	glBegin(GL_LINE_STRIP);
	for (angle2 = 0; angle2 < M_PI / 2;
		glVertex2f(120.0f - cos(angle2) * 10, 300.0f - sin(angle2) * 10),
		angle2 += 0.1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (angle2 = 0; angle2 < M_PI / 2;
		glVertex2f(190.0f + sin(angle2) * 10, 300.0f - cos(angle2) * 10),
		angle2 += 0.1);
	glEnd();
	//end vessel

	
	//Water
	glColor4f(43.0f / 255.0f,
		75.0f / 255.0f,
		230.0f / 255.0f,
		1.0f);

	//fill the vessel
	glBegin(GL_POLYGON);
	for (angle2 = 0; angle2 < M_PI * 2;
		glVertex2f(189.0f + sin(angle2) * 10, 301.0f - cos(angle2) * 10),
		angle2 += 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	for (angle2 = 0; angle2 < M_PI * 2;
		glVertex2f(121.0f + sin(angle2) * 10, 301.0f - cos(angle2) * 10),
		angle2 += 0.1);
	glEnd();


	glLineWidth(10 * KRscale);

	glBegin(GL_LINES);

	glVertex2f(118.0f, 294.0f);
	glVertex2f(189.0f, 294.0f);

	glVertex2f(118.0f, 299.0f);
	glVertex2f(189.0f, 299.0f);

	glVertex2f(111.0f, 304.0f);
	glVertex2f(199.0f, 304.0f);

	for (i = 0; i < InitData[DTWater]; i += 5)
	{
		glVertex2f(111.0f, 309.0f + (float)i);
		glVertex2f(199.0f, 309.0f + (float)i);
	}

	glEnd();
	//end filing the vessel


	glLineWidth(2 * KRscale);



	glBegin(GL_LINES);

	glVertex2f(195.0f, 300.0f);
	glVertex2f(200.0f, 300.0f);


	if (start == true)
	{

		for (i = 0; i <= tempint - 1;
			glVertex2f(200.0f + (i * 0.1f), 300.0f + WaterPosition[i] * 100),
			glVertex2f(200.0f + ((i + 1) * 0.1f), 300.0f + WaterPosition[i + 1] * 100),
			i++);
	}

	glEnd();

	

	//glDisable(GL_BLEND);


	glBegin(GL_LINES);

	//black
	glColor4f(0.0f,
		0.0f,
		0.0f,
		1.0f);

	glVertex2f(200.0f, 100.0f);
	glVertex2f(300.0f + WaterPositionAmount / 10, 100.0f);

	for (i = 0; i < WaterPositionAmount / 10 + 100; i += 100)
	{
		glVertex2f(200.0f + (float)i, 100.0f);
		glVertex2f(200.0f + (float)i, 90.0f);
	
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




		
	
	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);


	Events();




}