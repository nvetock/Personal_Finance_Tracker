#ifndef ISTATE_H
#define ISTATE_H

#include "FinTracker.h"
#include <string>

class IState
{
public:
	IState(FinTracker context){}
	virtual ~IState(){}

	/// <summary>
	/// Prints the programs command menu to the console, expects user input to follow.
	/// </summary>
	const virtual void printCommandMenu() const;
};

#endif