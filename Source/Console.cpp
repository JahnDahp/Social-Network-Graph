#include "Console.h"

int manual_stoi(std::string& str) {
	str.erase(remove_if(str.begin(), str.end(), [](unsigned char c) { return !std::isdigit(c); }), str.end());
	int i = 0;
	int n = str.size();
	while (i < n && isspace(str[i]))
	{
		i++;
	}
	if (i == n) throw std::invalid_argument("No digits found");
	int sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-') sign = -1;
		++i;
	}
	if (i == n || !isdigit(str[i])) throw std::invalid_argument("Invalid format: no digits after sign");
	long long result = 0;
	while (i < n && isdigit(str[i]))
	{
		int digit = str[i] - '0';
		result = result * 10 + digit;
		if (sign == 1 && result > INT_MAX) throw std::out_of_range("Integer overflow");
		else if (sign == -1 && -result < INT_MIN) throw std::out_of_range("Integer underflow");
		i++;
	}
	return (int)(sign * result);
}

Console::Console(Network* network, std::string inputUserFile)
{
	network_ = network;
	network_->readUsers(stringToCstring(inputUserFile));
	std::cout << "Welcome to the Social Network.\n";
}
void Console::run()
{
	while (true)
	{
		std::string choice = getChoice();
		if (!isValidChoice(choice)) return;
		if (choice == "1") addUser();
		if (choice == "2") addConnection();
		if (choice == "3") deleteConnection();
		if (choice == "4") writeUsers();
	}
}

std::string Console::getFullName(std::stringstream& input)
{
	std::string firstName, lastName;
	input >> firstName;
	input >> lastName;
	return firstName + " " + lastName;
}
void Console::getTwoUserNames(std::string& userName, std::string& friendName)
{
	std::string temp;
	std::cout << "Please enter the user's first and last name, followed by the friend's first and last name.\n";
	std::getline(std::cin, temp);
	std::stringstream input(temp);
	userName = getFullName(input);
	friendName = getFullName(input);
}
char* Console::stringToCstring(const std::string& str)
{
	char* Cstring = new char[str.length() + 1];
	for (long unsigned int i = 0; i < str.length() + 1; i++) Cstring[i] = str[i];
	return Cstring;
}
bool Console::isValidChoice(const std::string& choice)
{
	return (choice == "1" || choice == "2" || choice == "3" || choice == "4");
}
int Console::getNextNum(std::stringstream& input)
{
	std::string temp;
	input >> temp;
	return manual_stoi(temp);
}
std::string Console::getChoice()
{
	std::string choice;
	std::cout << "\nHow would you like to proceed?\n";
	std::cout << "1. Add User 2. Add Friend 3. Remove Friend 4. Save Data 5. Exit Program\n";
	std::getline(std::cin, choice);
	return choice;
}
void Console::addUser()
{
	std::string temp;
	std::cout << "Please enter the user's first name, last name, birth year, and zip code.\n";
	std::getline(std::cin, temp);
	std::stringstream input(temp);

	std::string name = getFullName(input);
	int year = getNextNum(input);
	int zip = getNextNum(input);

	network_->addUser(name, year, zip, {});
}
void Console::addConnection()
{
	std::string userName, friendName;
	getTwoUserNames(userName, friendName);
	network_->addConnection(userName, friendName);
}
void Console::deleteConnection()
{
	std::string userName, friendName;
	getTwoUserNames(userName, friendName);
	network_->deleteConnection(userName, friendName);
}
void Console::writeUsers()
{
	std::string filename = "users.txt";
	std::cout << "Saving data.\n";
	char* outputFile = stringToCstring(input);
	network_->writeUsers(outputFile);
	delete[] outputFile;
}
