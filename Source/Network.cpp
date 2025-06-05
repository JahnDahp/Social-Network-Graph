#include "Network.h"

int Network::stringToInt(std::string input)
{
	int result = 0;
	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i])) continue;
		int digit = input[i] - '0';
		result = result * 10 + digit;
	}
	return result;
}
int Network::getNumberFromFile(std::ifstream& inputFile) 
{
	std::string temp;
	std::getline(inputFile, temp);
	return stringToInt(temp);
}
std::stringstream Network::fillStream(std::ifstream& inputFile)
{
	std::string temp;
	std::stringstream stream;
	while (std::getline(inputFile, temp))
	{
		stream << temp << "\n";
	}
	return stream;
}
std::string Network::formatName(std::stringstream& stream) 
{
	std::string temp;
	stream >> temp;
	std::string name = temp + " ";
	stream >> temp;
	name += temp;
	return name;
}
std::set<int> Network::formatFriends(std::stringstream& stream) 
{
	std::string temp;
	std::getline(stream, temp);
	std::getline(stream, temp);
	std::stringstream friendStream(temp);
	std::set<int> friends;
	while (friendStream >> temp)
	{
		friends.insert(stringToInt(temp));
	}
	return friends;
}
void Network::addUsersFromFile(int userNumber, std::stringstream& stream)
{
	std::string temp;
	for (int i = 0; i < userNumber; i++)
	{
		stream >> temp;
		std::string name = formatName(stream);
		stream >> temp;
		int year = stringToInt(temp);
		stream >> temp;
		int zip = stringToInt(temp);
		std::set<int> friends = formatFriends(stream);
		addUser(name, year, zip, friends);
	}
	for (int userId = 0; userId < userNumber; userId++)
	{
		for (int friendId : getUser(userId)->getFriends())
		{
			addConnection(getUser(userId)->getName(), getUser(friendId)->getName());
		}
	}
}
void Network::writeAllUsers(std::ofstream& outputFile)
{
	for (User* user : users_)
	{
		outputFile << std::to_string(user->getId()) + "\n";
		outputFile << "\t" + user->getName() + "\n";
		outputFile << "\t" + std::to_string(user->getYear()) + "\n";
		outputFile << "\t" + std::to_string(user->getZip()) + "\n\t";
		for (int friendID : user->getFriends())
		{
			outputFile << std::to_string(friendID) + " ";
		}
		outputFile << "\n";
	}
}
void Network::resetGraph()
{
	for (Connection* connection : connections_)
	{
		connection->setColor(0.612f, 0.863f, 0.996f, 1.0f);
		connection->setVisible(true);
	}
	for (User* user : users_)
	{
		user->setColor(0.337f, 0.612f, 0.839f, 1.0f);
		user->setVisible(true);
		for (Number* number : user->getLabel())
		{
			number->setVisible(true);
		}
	}
}
void Network::selectUserGraphics()
{
	User* user = getUser(selectedUser_);
	for (User* otherUsers : users_)
	{
		otherUsers->setVisible(false);
		for (Number* number : otherUsers->getLabel())
		{
			number->setVisible(false);
		}
	}
	user->setVisible(true);
	for (Number* number : user->getLabel())
	{
		number->setVisible(true);
	}
	user->setColor(1.0f, 0.0f, 0.0f, 1.0f);
	for (int friendId : user->getFriends())
	{
		User* friendUser = getUser(friendId);
		friendUser->setVisible(true);
		friendUser->setColor(0.0f, 0.75f, 0.0f, 1.0f);
	}
}
void Network::selectConnectionGraphics()
{
	for (Connection* connection : connections_)
	{
		if (connection->getUser1()->getId() == selectedUser_)
		{
			for (Number* number : connection->getUser2()->getLabel())
			{
				number->setVisible(true);
			}
			connection->setColor(0.0f, 1.0f, 0.0f, 1.0f);
			continue;
		}
		if (connection->getUser2()->getId() == selectedUser_)
		{
			for (Number* number : connection->getUser1()->getLabel())
			{
				number->setVisible(true);
			}
			connection->setColor(0.0f, 1.0f, 0.0f, 1.0f);
			continue;
		}
		connection->setVisible(false);
	}
}
void Network::renderConnections(glm::mat4 proj, glm::mat4 view, float interval, float radius)
{
	for (Connection* connection : connections_)
	{
		User* user1 = connection->getUser1();
		User* user2 = connection->getUser2();

		float angle1 = glm::radians(interval * (user1->getId() - 1));
		float angle2 = glm::radians(interval * (user2->getId() - 1));

		float x1 = radius * std::cos(angle1);
		float y1 = radius * std::sin(angle1);
		float x2 = radius * std::cos(angle2);
		float y2 = radius * std::sin(angle2);

		float xMid = (x1 + x2) / 2.0f;
		float yMid = (y1 + y2) / 2.0f;

		float dx = x2 - x1;
		float dy = y2 - y1;
		float length = std::sqrt(dx * dx + dy * dy);
		float angle = glm::degrees(std::atan2(dy, dx));

		connection->transform(xMid, yMid, length * 0.5f, 1.0f, angle);
		if (connection->isVisible()) connection->render(proj, view);
	}
}
void Network::renderUsers(glm::mat4 proj, glm::mat4 view, float interval, float radius)
{
	for (User* user : users_)
	{
		float angle = glm::radians(interval * (user->getId() - 1));
		float x = radius * std::cos(angle);
		float y = radius * std::sin(angle);

		user->transform(x, y, 0.015f, 0.015f);
		if (user->isVisible()) user->render(proj, view);

		renderLabels(proj, view, radius, angle, x, y, user);
	}
}
void Network::renderLabels(glm::mat4 proj, glm::mat4 view, float radius, float angle, float x, float y, User* user)
{
	float labelRadius = radius + 0.04f;
	float labelBaseX = labelRadius * std::cos(angle);
	float labelBaseY = labelRadius * std::sin(angle);
	int digitCount = user->getDigits();
	for (int i = 0; i < digitCount; ++i)
	{
		Number* number = user->getLabel()[i];

		float offset = 0.0225f;
		float digitX = labelBaseX;
		float digitY = labelBaseY;
		if (x >= 0) digitX += offset * i;
		if (x < 0) digitX -= offset * (digitCount - i - 1);

		number->transform(digitX, digitY, 0.015f, 0.015f);
		if (number->isVisible()) number->render(proj, view);
	}
}

Network::Network()
{
	users_ = {};
	connections_ = {};
	selectedUser_ = -1;
}
User* Network::getUser(int id)
{
	for (User* user : users_)
	{
		if (user->getId() == id) return user;
	}
	return nullptr;
}
std::vector<User*> Network::getUsers()
{
	return users_;
}
std::set<Connection*> Network::getConnections()
{
	return connections_;
}
void Network::setSelectedUser(int id)
{
	selectedUser_ = id;
}
bool Network::tryExit(glm::vec2 normalizedDeciveCoords, float aspect)
{
	float rightBound = (0.5f / aspect) - 1.0f;
	return normalizedDeciveCoords.x <= rightBound && normalizedDeciveCoords.y >= 0.85;
}
void Network::trySelectUser(glm::vec2 worldCoords)
{
	if (numUsers() == 0) return;
	for (User* user : users_)
	{
		if (!user->isVisible()) continue;
		glm::vec2 min = user->getPos() - user->getScale();
		glm::vec2 max = user->getPos() + user->getScale();
		if (worldCoords.x < min.x || worldCoords.x > max.x || worldCoords.y < min.y || worldCoords.y > max.y) continue;
		if (user->getId() != selectedUser_)
		{
			selectedUser_ = user->getId();
			std::cout << "\nUser " << selectedUser_ << " " << user->getName() << "\n";
			for (int friendId : user->getFriends())
			{
				std::cout << "  Friend " << friendId << " " << getUser(friendId)->getName() << "\n";
			}
		}
		else selectedUser_ = -1;
		return;
	}
}
void Network::selectUser()
{
	resetGraph();
	if (selectedUser_ == -1) return;
	selectUserGraphics();
	selectConnectionGraphics();
}
int Network::getId(std::string name)
{
	for (User* user : users_)
	{
		if (user->getName() == name) return user->getId();
	}
	return -1;
}
void Network::addUser(std::string name, int year, int zip, std::set<int> friends)
{
	User* user = new User(numUsers(), name, year, zip, friends);
	users_.push_back(user);
	user->init();
	for (Number* number : user->getLabel())
	{
		number->init();
	}
}
void Network::addConnection(std::string s1, std::string s2)
{
	int userId = getId(s1);
	int friendId = getId(s2); 

	if (userId > numUsers() - 1 || friendId > numUsers() - 1 || s1 == s2) return;
	if (userId < 0 || friendId < 0) return;

	getUser(userId)->addFriend(friendId);
	getUser(friendId)->addFriend(userId);
	Connection* newConnection = new Connection(getUser(userId), getUser(friendId));
	newConnection->init();
	connections_.insert(newConnection);
	return;
}
void Network::deleteConnection(std::string s1, std::string s2)
{
	int user1Id = getId(s1);
	int user2Id = getId(s2);
	if (user1Id < 0 || user2Id < 0) return;

	getUser(user1Id)->deleteFriend(user2Id);
	getUser(user2Id)->deleteFriend(user1Id);
	Connection* oldConnection = nullptr;

	for (Connection* connection : connections_)
	{
		if ((connection->getUser1()->getId() == user1Id && connection->getUser2()->getId() == user2Id) || (connection->getUser2()->getId() == user1Id && connection->getUser1()->getId() == user2Id))
		{
			oldConnection = connection;
			break;
		}
	}
	if (oldConnection)
	{
		connections_.erase(oldConnection);
		delete oldConnection;
	}
}
int Network::numUsers()
{
	return users_.size();
}
int Network::readUsers(char* fname)
{
	std::ifstream inputFile(fname);
	if (!inputFile)	return -1;
	int userNumber = getNumberFromFile(inputFile);
	std::stringstream stream = fillStream(inputFile);
	addUsersFromFile(userNumber, stream);
	inputFile.close();
	return 0;
}
int Network::writeUsers(char* fname)
{
	std::ofstream outputFile(fname);
	if (!outputFile.is_open()) return -1;

	outputFile << std::to_string(numUsers()) + "\n";
	writeAllUsers(outputFile);

	outputFile.close();
	return 0;
}
void Network::render(glm::mat4 proj, glm::mat4 view)
{
	int numberOfUsers = numUsers();
	if (numberOfUsers == 0) return;

	float interval = 360.0f / (float)numberOfUsers;
	float radius = 2.0f;

	selectUser();
	renderConnections(proj, view, interval, radius);
	renderUsers(proj, view, interval, radius);
}
