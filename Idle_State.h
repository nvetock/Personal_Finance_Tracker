#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "IState.h"
#include "FinTracker.h"

class Idle_State :
    public IState
{
public:
    Idle_State() {}
    ~Idle_State() {}

    void setContext(FinTracker context);

    const void printCommandMenu() const;

    std::string getUserInput(std::string& userInput);
private:
    FinTracker _context;
};

#endif