#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	ID_ = 0;
	vertexCount_ = 0;
}
void VertexBuffer::init(float* vertices, unsigned int count)
{
	vertexCount_ = count;
	glGenBuffers(1, &ID_);
	bind();
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), vertices, GL_STATIC_DRAW);
	unbind();
}
VertexBuffer::~VertexBuffer() 
{
	glDeleteBuffers(1, &ID_);
}
void VertexBuffer::bind() 
{
	glBindBuffer(GL_ARRAY_BUFFER, ID_);
}
void VertexBuffer::unbind() 
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
unsigned int VertexBuffer::getCount()
{
	return vertexCount_;
}
unsigned int VertexBuffer::getID() 
{
	return ID_;
}
