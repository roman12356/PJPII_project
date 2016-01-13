#include "Header.h"

float ThrowY(float t, float speed, float *angle)
{
	return (float)(speed * t * sin(*angle) - ((9.80665 * pow(t, 2.0)) / 2));
}