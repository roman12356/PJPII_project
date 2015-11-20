#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#pragma comment(lib, "opengl32.lib")

static SDL_Surface* gHelloWorld = NULL;
static SDL_Window* window = NULL;
static SDL_Surface* gScreenSurface = NULL;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;



bool init();
bool loadMedia();
void close();
void Display();


#endif