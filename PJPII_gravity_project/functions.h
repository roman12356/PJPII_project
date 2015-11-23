#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void DisplayFunc();

void DisplayMain();

void DisplayWater();

void DisplayThrow();


void Events();

void MouseEvents();

void close();

bool loadMedia();

bool init();

bool loadMedia();

bool LoadGLTextures(GLuint *texture, char * filename);

bool LoadGLTexturesPNG(GLuint *texture, char * filename);

bool invert_image(SDL_Surface* image);

#endif