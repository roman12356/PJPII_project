#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void DisplayFunc();

void DisplayMain();

void DisplayWater();

void DisplayThrow();

void DisplayAnimWater();

void DisplayAnimThrow();

void CountThrow();

void CountWater();


void Events();

void MouseEvents();

void close();


bool loadMedia();

bool init();

bool LoadGLTextures(GLuint *texture, char * filename);

bool LoadGLTexturesPNG(GLuint *texture, char * filename);

bool invert_image(SDL_Surface* image);

bool CheckButton(Button_S *);

TextTexture LoadFromRenderedText(char *font, char *text, int size, SDL_Color *textColor);


float ThrowPos(float x, float speed, float angle);

float WaterVelocity(int *h);

#endif