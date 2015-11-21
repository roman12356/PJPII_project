#include "globals.h"
#include "functions.h"

void DisplayFunc()
{

	switch (InterfaceType)
	{
	case I_MAIN:
		DisplayMain();
		break;

	case I_WATER:
		DisplayWater();
		break;

	default:
		break;

	}









}