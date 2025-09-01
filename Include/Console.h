#pragma once

#include <algorithm>
#include "Network.h"

class Console
{
public:
	Console(Network* network, std::string inputUserFile);
	void run();
private:
	std::string getFullName(std::stringstream& input);
	void getTwoUserNames(std::string& userName, std::string& friendName);
	char* stringToCstring(const std::string& str);
	bool isValidChoice(const std::string& choice);
	int getNextNum(std::stringstream& input);
	std::string getChoice();
	void addUser();
	void addConnection();
	void deleteConnection();
	void writeUsers();

	Network* network_;
};
