#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include "IState.h"
#include "FinTracker.h"

class System_State :
    public IState
{
public:
    System_State(FinTracker context)
        : _context{ context } {}
    ~System_State() {}

    void setContext(FinTracker context);

    const void printCommandMenu() const;

    std::string getUserInput(std::string& userInput);
private:
    FinTracker _context;
};

#endif