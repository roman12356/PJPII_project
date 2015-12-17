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


extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern int InterfaceType;
extern int ActiveInitField;

//Mouse Position
extern int mousex;
extern int mousey;

extern SDL_Event ev;

extern float move;

extern bool quit;
extern bool pong;

extern Uint32 InitData[];
extern int tempint;
extern float *WaterPosition;
extern int WaterPositionAmount;
extern float angle;
extern int AmountOfRange;

extern char text[];
extern char **InitDataText;
extern char buffer[];
extern char range[];

extern SDL_Color textColor;

extern Uint32 StartTimer;
extern int FPS;

extern float WaterScale;

extern int xrel;

extern float KRscale;
extern int SlowMotion;
extern bool scaleflag;
extern bool start;




enum InterfaceTypeEnum
{
	I_MAIN,
	I_WATER,
	I_THROW,
	I_ORBIT,
	I_COUNT_ANIM_WATER,
	I_ANIM_WATER,
	I_ANIM_THROW,
	I_TOTAL
};

enum AdditionalTexturesEnum
{
	giggles,
	water,
	back,
	AddTotal
};


enum DataTextureEnum
{
	DTWater,
	DTThrowWeight,
	DTThrowVelocity,
	DTThrowAngle,
	DTTotal
};


enum AdditionalTextTexturesEnum
{
	BACK,
	SLOWMO_TRUE,
	SLOWMO_FALSE,
	RANGE,
	START,
	AddTexTotal
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



extern TextTexture InitDataTexture[];
extern TextTexture RangeTexture[];
extern TextTexture AdditionalTextTextures[];


extern Button_S Button_Main1;
extern Button_S Button_Main2;
extern Button_S Button_Main3;
extern Button_S Button_Back;
extern Button_S Button_Next;
extern Button_S Button_Enter;
extern Button_S Button_Data_Water;
extern Button_S Button_Data_ThrowWeight;
extern Button_S Button_Data_ThrowVelocity;
extern Button_S Button_Data_ThrowAngle;
extern Button_S Button_Empty;
extern Button_S Button_Powrot;
extern Button_S Button_Slowmo;
extern Button_S Button_Start;



#endif