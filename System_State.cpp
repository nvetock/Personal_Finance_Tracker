#include "System_State.h"
#include <iostream>

void System_State::setContext(FinTracker context) {
	this->_context = context;
}

const void System_State::printCommandMenu() const {
	// prints the state's menu
	// idle prints all possible states
	std::cout << "Command Menu\n"
		<< "||||| (1)Undo | (2)Save | (3)Save + Quit | (4)Quit | (5)Return |||||" << std::endl;
}