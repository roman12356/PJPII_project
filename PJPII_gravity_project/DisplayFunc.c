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

	case I_COUNT_ANIM_WATER:
		CountWater();
		break;

	case I_ANIM_WATER:
		DisplayAnimWater();
		break;

	case I_ANIM_THROW:
		DisplayAnimThrow();
		break;

	default:
		printf("Nothing yet\n");
		InterfaceType = I_MAIN;
		break;

	}









}