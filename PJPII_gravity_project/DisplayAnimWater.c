#include "Header.h"

void DisplayAnimWater()
{

	static float angle2;


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


	//glEnable(GL_BLEND);

	//glEnable(GL_TEXTURE_2D);


	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(800.0, 200.0);
	glVertex2f(800.0, 000.0);
	glEnd();

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(43.0f / 255.0f,
			75.0f / 255.0f,
			230.0f / 255.0f,
			1.0f);


	if (tempint < WaterPositionAmount)
	{
		tempint += WaterVelocity(&InitData[DTWater]) * 100 / FPS;
	}

	if (tempint > WaterPositionAmount)
	{
		tempint = WaterPositionAmount;
	}


	if ( tempint > 3500)
	glTranslatef(350-tempint/10, 0.0, 0.0);

	//glEnable(GL_BLEND);


	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_MULTISAMPLE);

	glLineWidth(2);

	

	glBegin(GL_LINES);
	for (i = 0; i <= tempint - 1;
		glVertex2f(200.0f + (i * 0.1f), 300.0f + WaterPosition[i] * 100),
		glVertex2f(200.0f + ((i + 1) * 0.1f), 300.0f + WaterPosition[i + 1] * 100),
		i++);
	glEnd();

	glDisable(GL_BLEND);

	glLineWidth(2);

	glBegin(GL_LINES);

	//black
	glColor4f(0.0f,
		0.0f,
		0.0f,
		1.0f);

	glVertex2f(200.0f, 100.0f);
	glVertex2f(700.0f, 100.0f);
	glEnd();



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


	glLineWidth(2);
	glBegin(GL_LINES);

	//dark purple - blue
	glColor4f(131.0f / 255.0f,
		153.0f / 255.0f,
		205.0f / 255.0f,
		1.0f);


	//vessel
	glVertex2f(110.0f, 300.0f);
	glVertex2f(110.0f, 310.0f + (float)InitData[DTWater]);

	glVertex2f(200.0f, 300.0f);
	glVertex2f(200.0f, 310.0f + (float)InitData[DTWater]);

	glVertex2f(120.0f, 290.0f);
	glVertex2f(190.0f, 290.0f);


	glEnd();


	//left and right circuled sides of vessel
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

	//getch();

	//printf("\nInterfaceType: %i", InterfaceType);

	//glDisable(GL_BLEND);

	//glDisable(GL_TEXTURE_2D);

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);


	Events();




}