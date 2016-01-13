#include "Header.h"

bool LoadGLTexturesPNG(GLuint *texture, char * filename)
{
	/* Create storage space for the texture */
	SDL_Surface* optimizedSurface = NULL;


	/* Status indicator */
	bool success = true;


	/* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
	if ((optimizedSurface = IMG_Load(filename)))
	{

		invert_image(optimizedSurface);

		success = true;

		glEnable(GL_TEXTURE_2D);

		/* Create The Texture */
		glGenTextures(1, &texture[0]);
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		/* Typical Texture Generation Using Data From The Bitmap */
		glBindTexture(GL_TEXTURE_2D, texture[0]);

		/* Generate The Texture */
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, optimizedSurface->w,
			optimizedSurface->h, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, optimizedSurface->pixels);
		glGetError();

		/* Linear Filtering */

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
	}
	else
	{
		success = false;
	}

	/* Free up any memory we may have used */
	if (optimizedSurface)
	{
		SDL_FreeSurface(optimizedSurface);
	}



	return success;


}