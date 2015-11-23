#include "Header.h"

void DisplayWater()
{

	//glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(1.0, 0.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();




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

	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);


	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	//printf("Count: %i\n", count++);


	Events();

	MouseEvents();





}