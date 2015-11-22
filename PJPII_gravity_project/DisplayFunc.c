#include "Header.h"

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