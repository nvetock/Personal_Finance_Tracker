#include <iostream>
#include <string>
#include "Logger.h"

namespace SysInterface {
	void printMsg(const std::string& msg) {
		std::cout << msg << std::endl;
	}

	void printCommandMenu() {
		std::cout << "[ Commands interface Here ]\n";
	}
}

int main()
{
	SysInterface::printMsg("Personal Finance Tracker is running...");
	Logger myLogger("Logs/main.log");

	/*
	while (true) {

		SysInterface::printCommandMenu();

	}
	*/

	SysInterface::printMsg("Personal Finance Tracker shutting down");
	return 0;
}