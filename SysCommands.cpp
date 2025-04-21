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