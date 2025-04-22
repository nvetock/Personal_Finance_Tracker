#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "IState.h"

class Idle_State :
    public IState
{
public:
    Idle_State(FinTracker &context)
        : _context{ context } {}
    ~Idle_State() {}

    void setContext(FinTracker context);

    const void printCommandMenu() const;

    std::string getUserInput();
private:
    FinTracker _context{};
};

#endif