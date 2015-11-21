#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include <SDL_events.h>
#include <stdio.h>
#include <stdbool.h>

extern SDL_Window* window;
extern SDL_Surface* gScreenSurface;
extern SDL_Surface * gCurrentSurface;
extern SDL_Surface * gDefaultSurface;
extern SDL_Surface * InterfaceSurface[];

extern SDL_Surface *loadSurface(char *filename);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern bool quit;
extern SDL_Event ev;
extern int InterfaceType;


enum InterfaceTypeEnum
{
	I_MAIN,
	I_WATER,
	I_THROW,
	I_TOTAL
};

#endif