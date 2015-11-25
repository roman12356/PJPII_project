#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void DisplayFunc();

void DisplayMain();

void DisplayWater();

void DisplayThrow();

void DisplayAnimWater();


void Events();

void MouseEvents();

void close();


bool loadMedia();

bool init();

bool LoadGLTextures(GLuint *texture, char * filename);

bool LoadGLTexturesPNG(GLuint *texture, char * filename);

bool invert_image(SDL_Surface* image);

bool CheckButton(Button_S *);


float ThrowPos(float x, float speed, float angle);

float WaterVelocity(float *h1, float *h2);

#endif