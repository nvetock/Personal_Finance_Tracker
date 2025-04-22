#include "FinTracker.h"
#include "Idle_State.h"

FinTracker::FinTracker() {
}

FinTracker::FinTracker(IState initialState) {
	this->_state = initialState;
}
