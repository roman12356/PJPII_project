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

	case I_THROW:
		DisplayThrow();
			break;

	case I_ANIM_WATER:
		DisplayAnimWater();
		break;

	default:
		printf("Nothing yet\n");
		InterfaceType = I_MAIN;
		break;

	}









}