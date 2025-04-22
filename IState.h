#ifndef ISTATE_H
#define ISTATE_H

#include "FinTracker.h"
#include <string>

class IState
{
protected:
	FinTracker *_trackerContext;

public:
	virtual ~IState(){}

	void setTrackerContext(FinTracker *trackerContext) {
		this->_trackerContext = trackerContext;
	}

	/// <summary>
	/// Prints the programs command menu to the console, expects user input to follow.
	/// </summary>
	const virtual void printCommandMenu() const;

};

#endif