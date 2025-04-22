#include "UserInput.h"

#include <iostream>

void UserInput::printMsg(const std::string& msg) {
	std::cout << msg << std::endl;
}

void UserInput::printCommandMenu() {
	std::cout << "Command Menu\n"
		<< "||||| (1)View | (2)Add Entry | (3)Quit |||||" << std::endl;
}

void UserInput::ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string UserInput::toLower(const std::string& str) {
	// FIXME: Should this check for errors?
	
	std::string s{};
	for (int i = 0; i < str.size(); ++i) {
		s[i] = std::tolower(str[i]);
	}

	return s;
}

bool UserInput::clearFailedExtraction() {
	if (!std::cin) {
		if (std::cin.eof()) {
			std::exit(0);
		}

		//handle failure
		std::cin.clear();
		UserInput::ignoreLine();

		return true;
	}

	return false;
}

std::string UserInput::getUserInput() {
	std::string userInput{};
	while (true) {
		// Listens for userInput and outputs in a lowercase format.
		std::getline(std::cin, userInput);

		if (!UserInput::clearFailedExtraction()) {
			// input is ok
			UserInput::ignoreLine();
		}
	}
}