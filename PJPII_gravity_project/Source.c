#include "Header.h"



int main(int argc, char * argv[])
{


	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	

	if (!loadMedia())
	{
			printf("Failed to load media!\n");

	}

	//While app is running
	while (!quit)
	{
			
		Events();

		DisplayFunc();

	}

	close();

	return 0;
}