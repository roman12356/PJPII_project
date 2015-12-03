#include "Header.h"

void DisplayAnimThrow()
{

	printf("\n\nWeight: %i\nVelocity: %i\nAngle: %i\n", InitData[DTThrowWeight], InitData[DTThrowVelocity], InitData[DTThrowAngle]);

	getch();

	Events();

	MouseEvents();












}