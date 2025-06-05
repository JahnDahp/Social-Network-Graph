#pragma once

#include <set>
#include <vector>
#include "Number.h"

class User
{
public:
	User();
	User(int userID, std::string userName, int userYear, int userZip, std::set<int> userFriends);
	~User();
	int getId();
	std::string getName();
	int getYear();
	int getZip();
	std::set<int>& getFriends();
	void addFriend(int id);
	void deleteFriend(int id);
	void init();
	void transform(float x, float y, float scaleX, float scaleY);
	void setColor(float r, float g, float b, float a);
	void render(glm::mat4 proj, glm::mat4 view);
	bool isVisible();
	glm::vec2 getPos();
	glm::vec2 getScale();
	std::vector<Number*> getLabel();
	int getDigits();
	void setVisible(bool b);
private:
	int id_;
	std::string name_;
	int year_;
	int zip_;
	std::set<int> friends_;
	Shader shader_ = Shader("../../Resources/Shaders/shader.vert", "../../Resources/Shaders/shader.frag");
	Renderer renderer_;
	VertexArray vertexArray_;
	VertexBuffer vertexBuffer_;
	IndexBuffer indexBuffer_;
	glm::vec4 color_;
	bool visible_;
	glm::vec2 position_;
	glm::vec2 scale_;
	std::vector<Number*> label_;
	int digits_;
};
