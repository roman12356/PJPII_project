#include "Header.h"

void DisplayAnimWater()
{

	static float angle2;
	static char range[4];


	glClearColor(153.0f / 255.0f,
				217.0f / 255.0f,
				234.0f / 255.0f,
				1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glColor4f(185.0f / 255.0f,
			122.0f / 255.0f,
			87.0f / 255.0f,
			1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();




	if (tempint > 3500)
	{
		glTranslatef(350 - (int)tempint / 10, 0.0, 0.0);
	}




	if (tempint < WaterPositionAmount)
	{
		tempint += WaterVelocity(&InitData[DTWater]) * 100 / FPS;
	}

	if (tempint > WaterPositionAmount)
	{
		tempint = WaterPositionAmount;
	}


	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(800.0 + (float)WaterPositionAmount/10, 200.0);
	glVertex2f(800.0 + (float)WaterPositionAmount/10, 000.0);
	glEnd();


	


	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_MULTISAMPLE);


	//chair
	glLineWidth(10);
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
	glLineWidth(2);

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


	glLineWidth(10);

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


	glLineWidth(2);



	glBegin(GL_LINES);

	glVertex2f(195.0f, 300.0f);
	glVertex2f(200.0f, 300.0f);


		for (i = 0; i <= tempint - 1;
			glVertex2f(200.0f + (i * 0.1f), 300.0f + WaterPosition[i] * 100),
			glVertex2f(200.0f + ((i + 1) * 0.1f), 300.0f + WaterPosition[i + 1] * 100),
			i++);
		
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

	for (i = 0; i < AmountOfRange; i++)
	{
		itoa(i * 100, &range, 10);
		RangeTexture[i] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);
	}



	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (i = 0; i < AmountOfRange; i++)
	{
		glBindTexture(GL_TEXTURE_2D, RangeTexture[i].Texture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(290.0 + i * 100, 90.0f);
		glTexCoord2f(0.0, 1.0); glVertex2f(290.0 + i * 100, 90.0f - RangeTexture[i].h);
		glTexCoord2f(1.0, 1.0); glVertex2f(290.0 + i * 100 + RangeTexture[i].w, 90.0 - RangeTexture[i].h);
		glTexCoord2f(1.0, 0.0); glVertex2f(290.0 + i * 100 + RangeTexture[i].w, 90.0);
		glEnd();
	}
	
	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);


	Events();




}