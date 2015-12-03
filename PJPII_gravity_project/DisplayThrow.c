#include "Header.h"

void DisplayThrow()
{

	glClearColor(136.0f / 255.0f, 0.0f, 21.0f / 255.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(1.0, 0.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if (InitDataText[DTThrowWeight][0] == '\0')
	{
		InitDataText[DTThrowWeight][0] = ' ';
		InitDataText[DTThrowWeight][1] = '\0';
	}

	if (InitDataText[DTThrowVelocity][0] == '\0')
	{
		InitDataText[DTThrowVelocity][0] = ' ';
		InitDataText[DTThrowVelocity][1] = '\0';
	}

	if (InitDataText[DTThrowAngle][0] == '\0')
	{
		InitDataText[DTThrowAngle][0] = ' ';
		InitDataText[DTThrowAngle][1] = '\0';
	}

	InitDataTexture[DTThrowWeight] = LoadFromRenderedText("fonts/arial.ttf", InitDataText[DTThrowWeight], 20, &textColor);
	InitDataTexture[DTThrowVelocity] = LoadFromRenderedText("fonts/arial.ttf", InitDataText[DTThrowVelocity], 20, &textColor);
	InitDataTexture[DTThrowAngle] = LoadFromRenderedText("fonts/arial.ttf", InitDataText[DTThrowAngle], 20, &textColor);


	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, InterfaceSurface[I_THROW]);
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

	glBindTexture(GL_TEXTURE_2D, InitDataTexture[DTThrowWeight].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(370.0, 490.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(370.0, 490.0 - InitDataTexture[DTThrowWeight].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(370.0 + InitDataTexture[DTThrowWeight].w, 490.0 - InitDataTexture[DTThrowWeight].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(370.0 + InitDataTexture[DTThrowWeight].w, 490.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, InitDataTexture[DTThrowVelocity].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(370.0, 400.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(370.0, 400.0 - InitDataTexture[DTThrowVelocity].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(370.0 + InitDataTexture[DTThrowVelocity].w, 400.0 - InitDataTexture[DTThrowVelocity].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(370.0 + InitDataTexture[DTThrowVelocity].w, 400.0);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, InitDataTexture[DTThrowAngle].Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(370.0, 310.0);
	glTexCoord2f(0.0, 1.0); glVertex2f(370.0, 310.0 - InitDataTexture[DTThrowAngle].h);
	glTexCoord2f(1.0, 1.0); glVertex2f(370.0 + InitDataTexture[DTThrowAngle].w, 310.0 - InitDataTexture[DTThrowAngle].h);
	glTexCoord2f(1.0, 0.0); glVertex2f(370.0 + InitDataTexture[DTThrowAngle].w, 310.0);
	glEnd();


	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);


	SDL_GL_MakeCurrent(window, gContext);

	SDL_GL_SwapWindow(window);

	//printf("Count: %i\n", count++);


	Events();

	MouseEvents();





}