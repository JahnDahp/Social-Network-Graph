#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	ID_ = 0;
	indexCount_ = 0;
}
void IndexBuffer::init(const unsigned int* indices, unsigned int count)
{
	indexCount_ = count;
	glGenBuffers(1, &ID_);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(float), indices, GL_STATIC_DRAW);
	unbind();
}
IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &ID_);
}
void IndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID_);
}
void IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
unsigned int IndexBuffer::getCount()
{
	return indexCount_;
}
unsigned int IndexBuffer::getID()
{
	return ID_;
}
