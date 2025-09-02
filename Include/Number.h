#pragma once

#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"

class Number
{
public:
	Number(int n);
	void init();
	int getNum();
	int isVisible();
	void setVisible(bool b);
	void transform(float x, float y, float scaleX, float scaleY);
	void render(glm::mat4 proj, glm::mat4 view);
private:
	int num_;
	Shader shader_ = Shader("../Resources/Shaders/texture.vert", "../Resources/Shaders/texture.frag");
	Texture texture_ = Texture("../Resources/Textures/numbers.png");
	Renderer renderer_;
	VertexArray vertexArray_;
	VertexBuffer vertexBuffer_;
	IndexBuffer indexBuffer_;
	bool visible_;
};