#include "Header.h"

float ThrowPos(float x, float speed, float angle)
{
	return (float)(x * tan(angle) - (9.80665 / (2 * pow(speed, 2.0) * pow(cos(angle), 2.0) ))*pow(x, 2.0));
}