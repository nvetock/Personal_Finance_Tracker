#include "Idle_State.h"
#include <iostream>

void Idle_State::setContext(FinTracker context) {
	this->_context = context;
}

const void Idle_State::printCommandMenu() const {
	// prints the state's menu
	// idle prints all possible states
	std::cout << "Command Menu\n"
		<< "||||| (1)Add | (2)View | (3)Modify | (4)System |||||" << std::endl;
}

