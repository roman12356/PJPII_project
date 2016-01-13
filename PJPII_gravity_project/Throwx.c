#include "Header.h"

float ThrowX(float t, float speed, float *angle)
{
	return speed * t * cos(*angle);
}