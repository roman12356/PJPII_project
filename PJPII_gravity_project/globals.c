#include "globals.h"


GLuint i;

SDL_Window* window = NULL;
SDL_Surface * gScreenSurface = NULL;
SDL_Surface * gCurrentSurface;
SDL_Surface * gDefaultSurface;

//OpenGL context
SDL_GLContext gContext;


GLuint texture;
GLuint  InterfaceSurface[I_TOTAL];
GLuint AdditionalTextures[AddTotal];

TextTexture InitDataTexture[DTTotal];

TextTexture Data_Water;

float move = 0;
bool pong = false;

//Mouse Position
int mousex;
int mousey;

SDL_Surface *loadSurface(char *filename)
{
		SDL_Surface *optimized = NULL;
		SDL_Surface* loadedSurface = SDL_LoadBMP(filename);
		if (loadedSurface == NULL)
		{
			printf("Unable to load %s! SDL Error: %s\n", filename, SDL_GetError());
		}
		else
		{

			optimized = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
			if (optimized == NULL)
			{
				printf("Failed to optimize image %s SDL ERROR:%s\n", filename, SDL_GetError());
			}
		}

		SDL_FreeSurface(loadedSurface);

		return optimized;
}

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

double Runge[K_TOTAL];

int InitData[DTTotal];
int tempint;
float *WaterPosition = NULL;
GLint WaterPositionAmount;
float angle;


char **InitDataText;


char buffer[1];

SDL_Color textColor = { 0, 0, 0 };

Uint32 StartTimer;
int FPS = 30;

float WaterScale;
	

bool quit = false;
SDL_Event ev;
int InterfaceType = I_MAIN;
int ActiveInitField;


Button_S Button_Main1 = { 23, 160, 533, 70 };
Button_S Button_Main2 = { 23, 290, 289, 30 };
Button_S Button_Main3 = { 23, 413, 515, 30 };
Button_S Button_Back = { 100, 400, 100, 100 };
Button_S Button_Next = { 600, 400, 100, 100 };
Button_S Button_Data_Water = { 267, 145, 177, 41 };
Button_S Button_Data_ThrowWeight = { 372, 101, 162, 41 };
Button_S Button_Data_ThrowVelocity = { 372, 192, 162, 41 };
Button_S Button_Data_ThrowAngle = { 372, 283, 162, 41 };
Button_S Button_Empty = { 0, 0, 0, 0 };