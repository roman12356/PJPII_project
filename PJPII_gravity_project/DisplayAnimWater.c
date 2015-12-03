#include "Header.h"

void DisplayAnimWater()
{
	//printf("Yes, yes...\n");

	if (i< 200)
	for (i = 0; i < 200; i++)
	{
		printf("Throw pos x: %.2f y: %.7f\n", i*0.01, ThrowPos((float)(i * 0.01), WaterVelocity(&InitData[DTWater]), (float)(angle * (M_PI / 180))));
	} 

	//printf("Height: %i\n", height);


	Events();

	MouseEvents();


}