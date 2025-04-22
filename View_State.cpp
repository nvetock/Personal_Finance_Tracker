#include "View_State.h"
#include <iostream>

void View_State::setContext(FinTracker context) {
	this->_context = context;
}

const void View_State::printCommandMenu() const {
	// prints the state's menu
	// idle prints all possible states
	std::cout << "View Command Menu\n"
		<< "||||| (1)View All | (2)View Specific | (3)System |||||" << std::endl;
}