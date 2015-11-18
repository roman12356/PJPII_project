Download the zip from http://www.lonesock.net/soil.html and unzip it.

In your visual studio project include path (project -> properties -> vc++ directories -> include directories) add the path to "src" folder of Soil. Same place of -> library directories add the "lib" folder. project -> properties -> Linker -> Input -> Additional Dependencies -> Edit to add "SOIL.lib"

This step is important as people tend to rename that .a file to .lib. Don't do that. Instead go inside "projects" folder, select a VC* (eg VC8 for VS2012) -> open the visual studio file -> it will open using your visual studio -> click ok -> click ok. Your solution will be Ready.

Now press F5/Run to build and Run. Be careful while doing it, in case your project is using a x64 Debug version then in here select the same before you build the solution.

There will be folders/files created in the VC* folder. Go inside Debug/x64 (dependent on your project), copy the SOIL.lib file to original "lib" folder (you pointed to in Visual Studio Properties in step 2).
At this point, you are done. It should work.


GLuint image;


	int width, height;
	image =
		SOIL_load_image("interfejs1.bmp", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image);


	glBindTexture(GL_TEXTURE_2D, image);