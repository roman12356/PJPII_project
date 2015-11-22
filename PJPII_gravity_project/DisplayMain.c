#include "Header.h"

void DisplayMain()
{
	glClearColor(1.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINES);
	glVertex2f(0.5, 0.5);
	glVertex2f(1.5, 1.5);

	glEnd();

	/*glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(0, 0);
	glTexCoord2i(0, 1); glVertex2i(0, 64);
	glTexCoord2i(1, 1); glVertex2i(64, 64);
	glTexCoord2i(1, 0); glVertex2i(64, 0);
	glEnd();


	glDisable(GL_TEXTURE_2D);*/
	/*
	if (!(LoadGLTextures(&texture, "bmp/Happy_face.bmp")))
	{
		printf("SDL ERROR: %s\n", SDL_GetError());
	}*/

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-2.0, -2.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(-2.0, 2.0);
	glTexCoord2f(1.0, 1.0); glVertex2f(2.0, 2.0);
	glTexCoord2f(1.0, 0.0); glVertex2f(2.0, -2.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);


	Events();






}