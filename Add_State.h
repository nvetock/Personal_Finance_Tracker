#ifndef ADD_STATE_H
#define ADD_STATE_H

#include "IState.h"
#include "FinTracker.h"

class Add_State :
    public IState
{
public:
    Add_State(FinTracker context)
		: _context{ context } {}
    ~Add_State(){}

	void setContext(FinTracker context);

	const void printCommandMenu() const;

	std::string getUserInput(std::string& userInput);
private:
	FinTracker _context;
};

#endif