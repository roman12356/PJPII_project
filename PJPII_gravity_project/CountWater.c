#include "Header.h"

void CountWater()
{
	char range[20];
	float WaterRange;
	char buff[20];
	for (i = 0; i < 20; i++)
	{
		buff[i] = '\0';
	}

	for (i = 0;
		ThrowPos((float)(i * 0.001), WaterVelocity(&InitData[DTWater]), (float)(angle * (M_PI / 180))) >= -2.0;
		i++
		);

	WaterPositionAmount = i;

	if ((WaterPosition = (float*)calloc(i, sizeof(float))) == NULL)
	{
		printf("\nCan't allocate memory for WaterPosition\n");
	}

	i--;


	for (;
		i > 0;
		WaterPosition[i] = ThrowPos((float)(i * 0.001), WaterVelocity(&InitData[DTWater]), (float)(angle * (M_PI / 180))),
		i--);

	//SDL_Delay(10000);

	printf("\nWaterPositionAmount: %i\ni: %i", WaterPositionAmount, i );
	printf("\nVelocity: %f ", WaterVelocity(&InitData[DTWater]));


	tempint = 0;

	WaterScale = 300.0f / WaterPositionAmount;

	for (i = 0; i < WaterPositionAmount / 10 + 100; i += 100);

	i -= 100;
	i /= 100;

	AmountOfRange = i;

	for (i = 0; i < AmountOfRange +1 ; i++)
	{
		itoa(i * 100, &range, 10);
		RangeTexture[i] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);
	}

	WaterRange = WaterPositionAmount / 1000.;

	//ftoa(WaterRange, &range, 10);
	sprintf(range, "%.3f", WaterRange);

	strcat(buff, "Zasieg: ");
	strcat(buff, range);
	strcat(buff, " [m]");

	RangeTexture[i] = LoadFromRenderedText("fonts/arial.ttf", "[cm]", 20, &textColor);

	AdditionalTextTextures[BACK] = LoadFromRenderedText("fonts/arial.ttf", "Powr�t", 35, &textColor);
	AdditionalTextTextures[SLOWMO_TRUE] = LoadFromRenderedText("fonts/arial.ttf", "Wylacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[SLOWMO_FALSE] = LoadFromRenderedText("fonts/arial.ttf", "Wlacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[RANGE] = LoadFromRenderedText("fonts/arial.ttf", buff, 25, &textColor);
	AdditionalTextTextures[START] = LoadFromRenderedText("fonts/arial.ttf", "START", 25, &textColor);


	xrel = 0;
	KRscale = 1.0f;
	SlowMotion = SLOWMO_FALSE;
	scaleflag = false;
	start = false;

	InterfaceType = I_ANIM_WATER;



}