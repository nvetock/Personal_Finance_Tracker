#ifndef MODIFY_STATE_H
#define MODIFY_STATE_H

#include "IState.h"
#include "FinTracker.h"

class Modify_State :
    public IState
{
public:
    Modify_State() {}
    ~Modify_State() {}

    void setContext(FinTracker context);

    const void printCommandMenu() const;

    std::string getUserInput(std::string& userInput);
private:
    FinTracker _context;
};

#endif