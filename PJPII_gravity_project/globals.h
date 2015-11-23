#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include <SDL_events.h>
#include <gl/glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <gl/GLU.h>
#include <stdio.h>
#include <stdbool.h>

extern GLuint count;

extern SDL_Window  * window;
extern SDL_Surface * gScreenSurface;
extern SDL_Surface * gCurrentSurface;
extern SDL_Surface * gDefaultSurface;
extern GLuint  InterfaceSurface[];
extern GLuint AdditionalTextures[];

extern SDL_GLContext gContext;

extern GLuint texture;

extern SDL_Surface *loadSurface(char *filename);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern bool quit;
extern SDL_Event ev;
extern int InterfaceType;

extern float move;

extern bool pong;

//Mouse Position
extern int mousex;
extern int mousey;


enum InterfaceTypeEnum
{
	I_MAIN,
	I_WATER,
	I_THROW,
	I_ORBIT,
	I_TOTAL
};

enum AdditionalTexturesEnum
{
	giggles,
	water,
	back,
	AddTotal
};

typedef struct
{
	int x;
	int y;
	int width;
	int height;
} Button_S;


extern Button_S Button_Main1;
extern Button_S Button_Main2;
extern Button_S Button_Main3;
extern Button_S Button_Back;
extern Button_S Button_Enter;


#endif