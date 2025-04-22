#include "Modify_State.h"
#include <iostream>

void Modify_State::setContext(FinTracker context) {
	this->_context = context;
}

const void Modify_State::printCommandMenu() const {
	// prints the state's menu
	// idle prints all possible states
	std::cout << "Command Menu\n"
		<< "||||| (1)Edit | (2)Remove | (3)System |||||" << std::endl;
}