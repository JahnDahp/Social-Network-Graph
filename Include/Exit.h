#pragma once

#include "Renderer.h"

class Exit
{
public:
	void init();
	void render(float aspect);
private:
	Shader shader_ = Shader("../Resources/Shaders/texture.vert", "../Resources/Shaders/texture.frag");
	Texture texture_ = Texture("../Resources/Textures/exit.png");
	Renderer renderer_;
	VertexArray vertexArray_;
	VertexBuffer vertexBuffer_;
	IndexBuffer indexBuffer_;
};