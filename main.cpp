#include <iostream>
#include <string>
#include "Logger.h"
#include "SysCommands.h"

int main()
{
	SysCommands::printMsg("Personal Finance Tracker is running...");
	Logger myLogger("Logs/main.log");

	// Database class instantiates here
	
	while (true) {
		SysCommands::printCommandMenu();

		// Get menu option from user
		std::string userInput{};
		try {
			std::getline(std::cin, userInput);
			
			if (!SysCommands::clearFailedExtraction()) {
				// input is ok
				SysCommands::ignoreLine();
			}
			else {
				continue;
			}
		}
		catch () {

		}

		// Convert user input into Enum

		switch () {

		}
		// View asks to filter by date or type

		// Add Entry asks if income or expense

		// Quit
	}
	

	SysCommands::printMsg("Personal Finance Tracker shutting down");
	return 0;
}