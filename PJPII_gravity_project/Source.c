#include "Header.h"




int main(int argc, char * argv[])
{


	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	

	if (!loadMedia("bmp/interface1.bmp"))
	{
			printf("Failed to load media!\n");

	}

	Display();

	close();

	return 0;
}