#include "User.h"

User::User()
{
	id_ = 0;
	name_ = "";
	year_ = 0;
	zip_ = 0;
	friends_ = {};
	color_ = glm::vec4(0.337f, 0.612f, 0.839f, 1.0f);
	visible_ = true;
	position_ = glm::vec2(0.0f, 0.0f);
	scale_ = glm::vec2(1.0f, 1.0f);
	label_.push_back(new Number(0));
	digits_ = 1;
}
User::User(int userID, std::string userName, int userYear, int userZip, std::set<int> userFriends)
{
	id_ = userID;
	name_ = userName;
	year_ = userYear;
	zip_ = userZip;
	friends_ = userFriends;
	color_ = glm::vec4(0.337f, 0.612f, 0.839f, 1.0f);
	visible_ = true;
	position_ = glm::vec2(0.0f, 0.0f);
	scale_ = glm::vec2(1.0f, 1.0f);
	std::string idStr = std::to_string(id_);
	digits_ = 0;
	for (char ch : idStr)
	{
		label_.push_back(new Number(ch - '0'));
		digits_++;
	}
}
User::~User()
{
	for (Number* number : label_) delete number;
	label_.clear();
}
int User::getId()
{
	return id_;
}
std::string User::getName()
{
	return name_;
}
int User::getYear()
{
	return year_;
}
int User::getZip()
{
	return zip_;
}
std::set<int>& User::getFriends()
{
	return friends_;
}
bool User::isVisible()
{
	return visible_;
}
glm::vec2 User::getPos()
{
	return position_;
}
glm::vec2 User::getScale()
{
	return scale_;
}
std::vector<Number*> User::getLabel()
{
	return label_;
}
int User::getDigits()
{
	return digits_;
}
void User::setVisible(bool b)
{
	visible_ = b;
}
void User::addFriend(int friendID)
{
	friends_.insert(friendID);
}
void User::deleteFriend(int friendID)
{
	friends_.erase(friendID);
}
void User::init()
{
	float vertices[] =
	{
		-1.0f, -1.0f,  0.0f, // Bottom Left
		 1.0f, -1.0f,  0.0f, // Bottom Right
		 1.0f,  1.0f,  0.0f, // Top Right
		-1.0f,  1.0f,  0.0f, // Top Left
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
void User::transform(float x, float y, float scale_X, float scale_Y)
{
	position_ = glm::vec2(x, y);
	scale_ = glm::vec2(scale_X, scale_Y);

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	model = glm::scale(model, glm::vec3(scale_X, scale_Y, 1.0f));
	shader_.setModel(model);
}
void User::setColor(float r, float g, float b, float a)
{
	color_ = glm::vec4(r, g, b, a);
}
void User::render(glm::mat4 proj, glm::mat4 view)
{
	shader_.setColor(color_);
	shader_.setView(view);
	shader_.setProj(proj);
	renderer_.draw(vertexArray_, indexBuffer_, shader_, GL_TRIANGLES);
}
