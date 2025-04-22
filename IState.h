#ifndef ISTATE_H
#define ISTATE_H

#include <string>

class IState
{
public:
	IState(){}
	virtual ~IState(){}

	const virtual void printCommandMenu() const;
	virtual std::string getUserInput(std::string& userInput);
};

#endif