#include "SysCommands.h"

#include <iostream>

void SysCommands::printMsg(const std::string& msg) {
	std::cout << msg << std::endl;
}

void SysCommands::printCommandMenu() {
	std::cout << "Command Menu\n"
		<< "||||| (1)View | (2)Add Entry | (3)Quit |||||" << std::endl;
}

void SysCommands::ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string SysCommands::toLower(const std::string& str) {
	// FIXME: Should this check for errors?
	
	std::string s{};
	for (int i = 0; i < str.size(); ++i) {
		s[i] = std::tolower(str[i]);
	}

	return s;
}

bool SysCommands::clearFailedExtraction() {
	if (!std::cin) {
		if (std::cin.eof()) {
			std::exit(0);
		}

		//handle failure
		std::cin.clear();
		SysCommands::ignoreLine();

		return true;
	}

	return false;
}