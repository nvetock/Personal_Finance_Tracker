#include "Add_State.h"
#include <iostream>

void Add_State::setContext(FinTracker context) {
	this->_context = context;
}

const void Add_State::printCommandMenu() const {
	// prints the state's menu
	// Add specifies income or expense, both use transaction
	std::cout << "Command Menu\n"
		<< "||||| (1)Income | (2)Expense | (3)System  |||||" << std::endl;
}