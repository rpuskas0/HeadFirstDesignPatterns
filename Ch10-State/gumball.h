#ifndef GUMBALL_H
#define GUMBALL_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

namespace MightyGumball {

class GumballMachine;

// ----------

class State {
public:
    virtual ~State() {}
    
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
    virtual void refill() = 0;
    virtual std::string print() = 0;
};

// ----------

class SoldState : public State {
public:
    SoldState(GumballMachine& ggumballMachine)
        : gumballMachine(ggumballMachine) {}
    
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;
    std::string print() override;
    
private:
    GumballMachine& gumballMachine;
};

// ----------

class SoldOutState : public State {
public:
    SoldOutState(GumballMachine& ggumballMachine)
        : gumballMachine(ggumballMachine) {}
    
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;
    std::string print() override;
    
private:
    GumballMachine& gumballMachine;
};

// ----------

class NoQuarterState : public State {
public:
    NoQuarterState(GumballMachine& ggumballMachine)
        : gumballMachine(ggumballMachine) {}
    
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;
    std::string print() override;
    
private:
    GumballMachine& gumballMachine;
};

// ----------

class HasQuarterState : public State {
public:
    HasQuarterState(GumballMachine& ggumballMachine)
        : gumballMachine(ggumballMachine) {}
    
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;
    std::string print() override;
    
private:
    GumballMachine& gumballMachine;
};

// ----------

class WinnerState : public State {
public:
    WinnerState(GumballMachine& ggumballMachine)
        : gumballMachine(ggumballMachine) {}
    
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
    void refill() override;
    std::string print() override;

private:
    GumballMachine& gumballMachine;
};

// ----------

class GumballMachine {
public:
    GumballMachine() = delete;
    GumballMachine(const GumballMachine&) = delete;
    GumballMachine& operator=(const GumballMachine&) = delete;
    GumballMachine(GumballMachine&&) = default;
    GumballMachine& operator=(GumballMachine&&) = default;
    
    static std::unique_ptr<GumballMachine> create(int numberGumballs);
    
    State* getSoldState() const {return soldState.get();}
    State* getSoldOutState() const {return soldOutState.get();}
    State* getNoQuarterState() const {return noQuarterState.get();}
    State* getHasQuarterState() const {return hasQuarterState.get();}
    State* getWinnerState() const {return winnerState.get();}
    
    int getCount() const {return ballCount;}
    std::string printState() const {return currState->print();}
    
    void setState(State* state) {currState = state;}
    void refill(int numberGumballs);
    
    void insertQuarter() {currState->insertQuarter();}
    void ejectQuarter() {currState->ejectQuarter();}
    void turnCrank() {currState->turnCrank(); currState->dispense();}
    void releaseBall();
    
private:
    GumballMachine(int numberGumballs)
        : ballCount(numberGumballs) {}
    
    std::unique_ptr<State> soldState;
    std::unique_ptr<State> soldOutState;
    std::unique_ptr<State> noQuarterState;
    std::unique_ptr<State> hasQuarterState;
    std::unique_ptr<State> winnerState;
    
    State* currState;
    int ballCount;
};

std::ostream& operator<<(std::ostream& os, const GumballMachine& gm);


} // end of namespace MightyGumball


#endif
