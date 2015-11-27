#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include <SDL_events.h>
#include <gl/glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <gl/GLU.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#define H 0.1

extern GLuint i;

extern SDL_Window  * window;
extern SDL_Surface * gScreenSurface;
extern SDL_Surface * gCurrentSurface;
extern SDL_Surface * gDefaultSurface;

extern SDL_Surface *loadSurface(char *filename);

extern GLuint  InterfaceSurface[];
extern GLuint AdditionalTextures[];
extern GLuint texture;


extern SDL_GLContext gContext;

extern double Runge[];

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern int InterfaceType;

//Mouse Position
extern int mousex;
extern int mousey;

extern SDL_Event ev;

extern float move;

extern bool quit;
extern bool pong;

extern int height;
extern float angle;

extern char text[];
extern char buffer[];




enum InterfaceTypeEnum
{
	I_MAIN,
	I_WATER,
	I_THROW,
	I_ORBIT,
	I_ANIM_WATER,
	I_TOTAL
};

enum AdditionalTexturesEnum
{
	giggles,
	water,
	back,
	AddTotal
};

enum Runge_KuttaEnum
{
	K1,
	K2,
	K3,
	K4,
	K_TOTAL
};

typedef struct
{
	int x;
	int y;
	int width;
	int height;
} Button_S;

typedef struct
{
	GLuint Texture;
	int w;
	int h;
}TextTexture;

extern TextTexture Data_Water;


extern Button_S Button_Main1;
extern Button_S Button_Main2;
extern Button_S Button_Main3;
extern Button_S Button_Back;
extern Button_S Button_Next;
extern Button_S Button_Enter;
extern Button_S Button_Data_Water;


#endif