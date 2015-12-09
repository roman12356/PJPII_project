#include "Header.h"


float WaterVelocity(int *h)
{

	return (float)( sqrt( 2 * 9.80665 * (*h) * 0.01 ) );
}