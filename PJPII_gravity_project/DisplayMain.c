#include "Header.h"

void DisplayMain()
{
	glClearColor(136.0f / 255.0f, 0.0f, 21.0f / 255.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT /*| GL_DEPTH_BUFFER_BIT*/);

	//glColor3f(136.0f / 255.0f, 0.0f, 21.0f / 255.0f);

	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0, 0.0, 0.0);


	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, InterfaceSurface[I_MAIN]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(0.0 , 0.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(0.0, 600.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(800.0, 600.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(800.0, 0.0);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, AdditionalTextures[giggles]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(550.0, 135.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(550.0, 535.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(800.0, 535.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(800.0, 135.0);
	glEnd();


	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);

	//glTranslatef(0, 0, -1.0);


	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	//printf("Count: %i\n", count++);


	Events();

	MouseEvents();






}