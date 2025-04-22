#ifndef FINTRACKER_H
#define FINTRACKER_H

#include "IState.h"

/// <summary>
/// FinTracker is the brain that a user interacts with. This class controls the state machine and holds relevant DB info.
/// </summary>
class FinTracker
{
public:
	FinTracker(){}
	FinTracker(IState initialState){}
	~FinTracker();

	void changeState(IState state);
	const void printCommandMenu() const;


private:
	IState _state;
};

#endif