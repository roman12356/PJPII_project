#include "Header.h"

void DisplayAnimWater()
{
	printf("Yes, yes...\n");

	for (i = 0; i < 200; i++)
	{
		printf("Throw pos x: %.2f y: %.7f\n", i*0.01, ThrowPos((float)(i * 0.01), WaterVelocity(&height1, &height2), (float)( angle * (M_PI/180 ) )) );
	} 

	getch();

	Events();

	MouseEvents();


}