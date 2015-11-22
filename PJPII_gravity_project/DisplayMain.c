#include "Header.h"

void DisplayMain()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();




	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, InterfaceSurface[I_MAIN]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-400.0, -300.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(-400.0, 300.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(400.0, 300.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(400.0, -300.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	printf("Count: %i\n", count++);


	Events();






}