#include "Header.h"

bool LoadGLTexturesPNG(GLuint *texture, char * filename)
{

	SDL_Surface* optimizedSurface = NULL;


	/* Status indicator */
	bool success = true;

	/* Create storage space for the texture */
	SDL_Surface *TextureImage[1];// = NULL;

	/* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
	if ((TextureImage[0] = IMG_Load(filename)))
	{

		//Convert surface to screen format
		/*optimizedSurface = SDL_ConvertSurface(TextureImage[0], gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", filename, SDL_GetError());
		}*/

		optimizedSurface = TextureImage[0];

		//SDL_DisplayFormatAlpha(optimizedSurface);

		invert_image(optimizedSurface);

		success = true;

		glEnable(GL_TEXTURE_2D);

		/* Create The Texture */
		glGenTextures(1, &texture[0]);
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		/* Typical Texture Generation Using Data From The Bitmap */
		glBindTexture(GL_TEXTURE_2D, texture[0]);

		/* Generate The Texture */

		

		/*glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/

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

		//Get rid of old loaded surface
		//SDL_FreeSurface(TextureImage[0]);
	}

	return success;


}