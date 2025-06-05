#include "Connection.h"

Connection::Connection(User* firstUser, User* secondUser)
{
	user1_ = firstUser;
	user2_ = secondUser;
	color_ = glm::vec4(0.612f, 0.863f, 0.996f, 1.0f);
	visible_ = true;
}
User* Connection::getUser1()
{
	return user1_;
}
User* Connection::getUser2()
{
	return user2_;
}
bool Connection::isVisible()
{
	return visible_;
}
void Connection::setVisible(bool b)
{
	visible_ = b;
}
void Connection::init()
{
	float vertices[] =
	{
		-1.0f,  0.001f,  0.0f, // Left Top
		-1.0f, -0.001f,  0.0f, // Left Bottom
		 1.0f, -0.001f,  0.0f, // Right Bottom
		 1.0f,  0.001f,  0.0f, // Right Top
	};
	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0,
	};
	vertexArray_.init();
	vertexBuffer_.init(vertices, sizeof(vertices));
	indexBuffer_.init(indices, sizeof(indices));
	vertexArray_.linkAttrib(vertexBuffer_, 0, 3, GL_FLOAT, 3, (void*)0);
	shader_.setModel(glm::mat4(1.0f));
}
void Connection::transform(float x, float y, float scaleX, float scaleY, float angle)
{
	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scaleX, scaleY, 1.0f));
	shader_.setModel(model);
}
void Connection::setColor(float r, float g, float b, float a)
{
	color_ = glm::vec4(r, g, b, a);
}
void Connection::render(glm::mat4 proj, glm::mat4 view)
{
	shader_.setColor(color_);
	shader_.setView(view);
	shader_.setProj(proj);
	renderer_.draw(vertexArray_, indexBuffer_, shader_, GL_TRIANGLES);
}
