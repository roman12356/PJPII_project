#include "Header.h"

TextTexture LoadFromRenderedText(char *font, char *text, int size, SDL_Color *textColor)
{
	TextTexture temp;

	TTF_Font* tmpfont = TTF_OpenFont(font,  size);
	if (tmpfont == NULL)
	{
		printf("Error: %s\n", TTF_GetError());
		return temp;
	}



	SDL_Surface* TextSDL = NULL;
	TextSDL = TTF_RenderText_Blended(tmpfont, text, *textColor);
	if (TextSDL != NULL)
	{
		//invert_image(TextSDL);

		glEnable(GL_TEXTURE_2D);

		/* Create The Texture */
		glGenTextures(1, &temp.Texture);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		/* Typical Texture Generation Using Data From The Bitmap */
		glBindTexture(GL_TEXTURE_2D, temp.Texture);

		/* Generate The Texture */

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextSDL->w,
			TextSDL->h, 0, GL_BGRA,
			GL_UNSIGNED_BYTE, TextSDL->pixels);
		glGetError();

		temp.h = TextSDL->h;
		temp.w = TextSDL->w;

		/* Linear Filtering */
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}





	return temp;
}