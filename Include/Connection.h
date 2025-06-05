#pragma once

#include "User.h"

class Connection
{
public:
	Connection(User* firstUser, User* secondUser);
	User* getUser1();
	User* getUser2();
	bool isVisible();
	void setVisible(bool b);
	void init();
	void transform(float x, float y, float scaleX, float scaleY, float angle);
	void setColor(float r, float g, float b, float a);
	void render(glm::mat4 proj, glm::mat4 view);
private:
	User* user1_;
	User* user2_;
	Shader shader_ = Shader("../../Resources/Shaders/shader.vert", "../../Resources/Shaders/shader.frag");
	Renderer renderer_;
	VertexArray vertexArray_;
	VertexBuffer vertexBuffer_;
	IndexBuffer indexBuffer_;
	glm::vec4 color_;
	bool visible_;
};
