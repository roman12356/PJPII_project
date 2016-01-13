#include "Header.h"

void CountThrow()
{
	//char range[20];
	float ThrowRange, angle;
	char buff[50];
	for (i = 0; i < 50; i++)
	{
		buff[i] = '\0';
	}

	angle = (float)(InitData[DTThrowAngle] * (M_PI / 180));


	for (i = 0;
		ThrowY((float)i / (FPS * 5), (float)InitData[DTThrowVelocity], &angle) >= 0.0;
		i++
		);

	if (ThrowPositionY != NULL)
	{
		free(ThrowPositionY);
		ThrowPositionY = NULL;
		free(ThrowPositionX);
		ThrowPositionX = NULL;
	}


	ThrowPositionAmount = i;

	if ((ThrowPositionY = (float*)calloc(i+1, sizeof(float))) == NULL)
	{
		printf("\nCan't allocate memory for ThrowPositionY\n");
	}

	if ((ThrowPositionX = (float*)calloc(i + 1, sizeof(float))) == NULL)
	{
		printf("\nCan't allocate memory for ThrowPositionX\n");
	}

	


	for (i = ThrowPositionAmount -1;
		i > 0;
		ThrowPositionY[i] = ThrowY((float)i / (FPS * 5), (float)InitData[DTThrowVelocity], &angle),
		i--);

	ThrowPositionY[ThrowPositionAmount] = 0.0;

	for (i = ThrowPositionAmount - 1;
		i > 0;
		ThrowPositionX[i] = ThrowX((float)i / (FPS * 5), (float)InitData[DTThrowVelocity], &angle),
		i--);


	ThrowPositionX[ThrowPositionAmount] = ThrowX((float)ThrowPositionAmount / (FPS * 5), (float)InitData[DTThrowVelocity], &angle);


	AmountOfRange = 1 + (int)ThrowPositionX[ThrowPositionAmount];

	sprintf(buff, "Zasieg: %.03f[m]\0", ThrowPositionX[ThrowPositionAmount]);

	RangeTexture[45] = LoadFromRenderedText("fonts/arial.ttf", "[cm]", 20, &textColor);	

	AdditionalTextTextures[BACK] = LoadFromRenderedText("fonts/arial.ttf", "Powrót", 35, &textColor);
	AdditionalTextTextures[SLOWMO_TRUE] = LoadFromRenderedText("fonts/arial.ttf", "Wylacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[SLOWMO_FALSE] = LoadFromRenderedText("fonts/arial.ttf", "Wlacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[RANGE] = LoadFromRenderedText("fonts/arial.ttf", buff, 25, &textColor);
	AdditionalTextTextures[START] = LoadFromRenderedText("fonts/arial.ttf", "START", 25, &textColor);



	xrel = 0;
	yrel = 0;
	KRscale = 1.0f;
	SlowMotion = SLOWMO_FALSE;
	scaleflag = false;
	start = false;
	tempint = 0;
	translatex = 0;
	translatey = 0;
	showtime = 0;	
	ThrowPositionYUp = false;

	InterfaceType = I_ANIM_THROW;



}