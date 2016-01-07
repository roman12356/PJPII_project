#include "Header.h"

void CountThrow()
{
	char range[20];
	float ThrowRange;
	char buff[20];
	for (i = 0; i < 20; i++)
	{
		buff[i] = '\0';
	}

	printf("Velo: %f\nangle: %f\n", (float)InitData[DTThrowVelocity], (float)(InitData[DTThrowAngle] * (M_PI / 180)));


	for (i = 0;
		ThrowPos((float)(i * 0.001), (float)InitData[DTThrowVelocity], (float)(InitData[DTThrowAngle] * (M_PI / 180))) >= 0.0;
		i++
		);


	ThrowPositionAmount = i;

	if ((ThrowPosition = (float*)calloc(i, sizeof(float))) == NULL)
	{
		printf("\nCan't allocate memory for ThrowPosition\n");
	}

	i--;


	for (;
		i > 0;
		ThrowPosition[i] = ThrowPos((float)(i * 0.001), (float)InitData[DTThrowVelocity], (float)(InitData[DTThrowAngle] * (M_PI / 180))),
		printf("watPos: %f\n", ThrowPosition[i]),
		//SDL_Delay(10),
		i--);

	printf("\nThrowPositionAmount: %i\ni: %i", ThrowPositionAmount, i);
	printf("\nVelocity: %f ", (float)InitData[DTThrowVelocity]);


	tempint = 0;

	ThrowScale = 300.0f / ThrowPositionAmount;

	for (i = 0; i < ThrowPositionAmount / 10 + 100; i += 100);

	i -= 100;
	i /= 100;

	AmountOfRange = i;

	for (i = 0; i < AmountOfRange + 1; i++)
	{
		itoa(i * 100, &range, 10);
		RangeTexture[i] = LoadFromRenderedText("fonts/arial.ttf", &range, 20, &textColor);
	}

	ThrowRange = ThrowPositionAmount / 1000.;

	sprintf(range, "%.3f", ThrowRange);

	strcat(buff, "Zasieg: ");
	strcat(buff, range);
	strcat(buff, " [m]");

	RangeTexture[i] = LoadFromRenderedText("fonts/arial.ttf", "[cm]", 20, &textColor);

	AdditionalTextTextures[BACK] = LoadFromRenderedText("fonts/arial.ttf", "Powrót", 35, &textColor);
	AdditionalTextTextures[SLOWMO_TRUE] = LoadFromRenderedText("fonts/arial.ttf", "Wylacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[SLOWMO_FALSE] = LoadFromRenderedText("fonts/arial.ttf", "Wlacz zwolnione tempo", 25, &textColor);
	AdditionalTextTextures[RANGE] = LoadFromRenderedText("fonts/arial.ttf", buff, 25, &textColor);
	AdditionalTextTextures[START] = LoadFromRenderedText("fonts/arial.ttf", "START", 25, &textColor);


	xrel = 0;
	KRscale = 1.0f;
	SlowMotion = SLOWMO_FALSE;
	scaleflag = false;
	start = false;

	InterfaceType = I_ANIM_THROW;



}