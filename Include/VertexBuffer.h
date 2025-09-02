#pragma once

#include <GL/gl3w.h>

class VertexBuffer 
{
public:
	VertexBuffer();
	~VertexBuffer();
	void init(float* vertices, unsigned int count);
	void bind();
	void unbind();
	unsigned int getCount();
	unsigned int getID();
private:
	unsigned int ID_;
	unsigned int vertexCount_;
};
