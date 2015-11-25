#include "Header.h"


float WaterVelocity(float *h1, float *h2)
{

	return (float)( sqrt( 2 * 9.80665 * (*h1 - *h2) ) );
}