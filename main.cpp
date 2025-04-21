#include <iostream>
#include <string>
#include "Logger.h"

namespace SysInterface {
	void printMsg(const std::string& msg) {
		std::cout << msg << std::endl;
	}

	void printCommandMenu() {
		std::cout << "Command Menu\n"
			<< "||||| (1)View | (2)Add Entry | (3)Quit |||||" << std::endl;
	}


}

int main()
{
	SysInterface::printMsg("Personal Finance Tracker is running...");
	Logger myLogger("Logs/main.log");

	// Database class instantiates here
	
	while (true) {
		SysInterface::printCommandMenu();

		// Get menu option from user

		// View asks to filter by date or type

		// Add Entry asks if income or expense

		// Quit
	}
	

	SysInterface::printMsg("Personal Finance Tracker shutting down");
	return 0;
}