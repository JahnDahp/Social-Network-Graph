#pragma once

#include <GL/gl3w.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

class Shader 
{
public:
	Shader();
	Shader(std::string vertexFile, std::string fragmentFile);
	~Shader();
	void bind();
	void unbind();
	unsigned int getID();
	void setColor(glm::vec4 color);
	void setTexture();
	void setModel(glm::mat4 model);
	void setView(glm::mat4 view);
	void setProj(glm::mat4 proj);
private:
	unsigned int ID_;
};
