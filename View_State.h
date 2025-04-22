#ifndef VIEW_STATE_H
#define VIEW_STATE_H

#include "IState.h"
#include "FinTracker.h"

class View_State : public IState
{
public:
	View_State(FinTracker context)
		: _context{ context } {}
	~View_State(){}

	void setContext(FinTracker context);

	const void printCommandMenu() const;

	std::string getUserInput(std::string& userInput);
private:
	FinTracker _context;
};

#endif