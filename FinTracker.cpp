#include "FinTracker.h"
#include "Idle_State.h"
#include <iostream>


FinTracker::FinTracker(IState* initialState)
	: _state{ nullptr }
{
	this->changeState(initialState);
}

FinTracker::~FinTracker() {
	delete _state;
}

void FinTracker::changeState(IState* state) {
	std::cout << "Transitioning to " << typeid(*state).name() << '\n';

	if (this->_state != nullptr) {
		delete this->_state;
	}

	this->_state = state;
	this->_state->setTrackerContext(this);
}

const void FinTracker::printCommandMenu() const {
	this->_state->printCommandMenu();
}