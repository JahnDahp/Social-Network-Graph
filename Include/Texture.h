#pragma once

#include <GL/gl3w.h>
#include "../Resources/STB/stb_image.h"

class Texture 
{
public:
	Texture(const char* image);
	~Texture();
	void bind();
	void unbind();
	unsigned int getID();
private:
	unsigned int ID_;
	const char* imagePath_;
};
