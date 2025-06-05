#pragma once

#include "User.h"
#include "Connection.h"

class Network
{
public:
	Network();
	User* getUser(int id);
	std::vector<User*> getUsers();
	int getId(std::string name);
	void addUser(std::string name, int year, int zip, std::set<int> friends);
	void addConnection(std::string s1, std::string s2);
	void deleteConnection(std::string s1, std::string s2);
	int numUsers();
	int readUsers(char* fname);
	int writeUsers(char* fname);
	void render(glm::mat4 proj, glm::mat4 view);
	std::set<Connection*> getConnections();
	void setSelectedUser(int id);
	bool tryExit(glm::vec2 screenCoords, float aspect);
	void trySelectUser(glm::vec2 worldCoords);
	void selectUser();
private:
	int stringToInt(std::string input);
	int getNumberFromFile(std::ifstream& inputFile);
	std::stringstream fillStream(std::ifstream& inputFile);
	std::string formatName(std::stringstream& stream);
	std::set<int> formatFriends(std::stringstream& stream);
	void addUsersFromFile(int userNumber, std::stringstream& stream);
	void writeAllUsers(std::ofstream& outputFile);
	void resetGraph();
	void selectUserGraphics();
	void selectConnectionGraphics();
	void renderConnections(glm::mat4 proj, glm::mat4 view, float interval, float radius);
	void renderUsers(glm::mat4 proj, glm::mat4 view, float interval, float radius);
	void renderLabels(glm::mat4 proj, glm::mat4 view, float radius, float angle, float x, float y, User* user);

	std::vector<User*> users_;
	std::set<Connection*> connections_;
	int selectedUser_;
};
