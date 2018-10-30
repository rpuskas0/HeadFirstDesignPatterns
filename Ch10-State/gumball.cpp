
#include "gumball.h"
#include <utility>
#include <cstdlib>
#include <chrono>

namespace MightyGumball {


void SoldState::insertQuarter()
{
    std::cout << "Please wait, we are already giving you a gumball" << std::endl;
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, but you already turned the crank" << std::endl;
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}

void SoldState::dispense()
{
    gumballMachine.releaseBall();

    if (gumballMachine.getCount() > 0) {
        gumballMachine.setState(gumballMachine.getNoQuarterState());
    } else {
        std::cout << "Oops, out of gumballs!" << std::endl;
        gumballMachine.setState(gumballMachine.getSoldOutState());
    }
}

void SoldState::refill()
{
    std::cout << "Can't refill during selling" << std::endl;
}

std::string SoldState::print()
{
    return "Selling gumball...";
}

// ----------

void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert a quarter, the machine sold out" << std::endl;
}

void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
}

void SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs" << std::endl;
}

void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void SoldOutState::refill()
{
    auto ballCount = gumballMachine.getCount();
    if (ballCount > 0) {
        gumballMachine.setState(gumballMachine.getNoQuarterState());
        std::cout << "The gumball machine was just refilled; it's new count is: "
        << ballCount
        << std::endl;
    } else {
        std::cout << "No gumballs were added, machine remains empty" << std::endl;
    }
    
}

std::string SoldOutState::print()
{
    return "Out of gumballs, Machine is waiting for refill...";
}

// ----------

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter" << std::endl;
    gumballMachine.setState(gumballMachine.getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter" << std::endl;
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there is no quarter" << std::endl;
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first" << std::endl;
}

void NoQuarterState::refill()
{
    auto ballCount = gumballMachine.getCount();
    std::cout << "The gumball machine was just refilled; it's new count is: "
        << ballCount << std::endl;
}

std::string NoQuarterState::print()
{
    return "Machine is waiting for quarter...";
}

// ----------

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter" << std::endl;
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned" << std::endl;
    gumballMachine.setState(gumballMachine.getNoQuarterState());
}

void HasQuarterState::turnCrank()
{        
    auto timeNow = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
        
    std::cout << "You turned..." << std::endl;
    srand(timeNow.time_since_epoch().count());
    int winner = rand() % 10;
    
    if (winner == 0 && gumballMachine.getCount() > 1) {
        gumballMachine.setState(gumballMachine.getWinnerState());
    } else {
        gumballMachine.setState(gumballMachine.getSoldState());
    }
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void HasQuarterState::refill()
{
    std::cout << "Can't refill when coin is inserted" << std::endl;
}

std::string HasQuarterState::print()
{
    return "Quarter inserted, waiting for customer action...";
}

// ----------

void WinnerState::insertQuarter()
{
    std::cout << "Please wait, we are already giving you a gumball" << std::endl;
}

void WinnerState::ejectQuarter()
{
    std::cout << "Sorry, but you already turned the crank" << std::endl;
}

void WinnerState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}

void WinnerState::dispense()
{
    gumballMachine.releaseBall();
    
    if (gumballMachine.getCount() == 0) {
        gumballMachine.setState(gumballMachine.getSoldOutState());
    } else {
        gumballMachine.releaseBall();
        std::cout << "YOU'RE A WINNER! You got two gumballs for your quarter" << std::endl;
    
        if (gumballMachine.getCount() > 0) {
            gumballMachine.setState(gumballMachine.getNoQuarterState());
        } else {
            std::cout << "Oops, out of gumballs!" << std::endl;
            gumballMachine.setState(gumballMachine.getSoldOutState());
        }
    }
}

void WinnerState::refill()
{
    std::cout << "Can't refill during selling" << std::endl;
}

std::string WinnerState::print()
{
    return "There was a winner, processing...";
}

// ----------

std::unique_ptr<GumballMachine> GumballMachine::create(int numberGumballs)
{
    std::unique_ptr<GumballMachine> instance(new GumballMachine(numberGumballs));
    
    instance->soldState = std::make_unique<SoldState>(*instance);
    instance->soldOutState = std::make_unique<SoldOutState>(*instance);
    instance->noQuarterState = std::make_unique<NoQuarterState>(*instance);
    instance->hasQuarterState = std::make_unique<HasQuarterState>(*instance);
    instance->winnerState = std::make_unique<WinnerState>(*instance);
    
    if (numberGumballs > 0) {
        instance->currState = instance->getNoQuarterState();
    } else {
        instance->currState = instance->getSoldOutState();
    }
    
    return instance;
}

void GumballMachine::refill(int numberGumballs)
{
    if (currState == soldOutState.get() || currState == noQuarterState.get()) {
        ballCount += numberGumballs;
    }
    currState->refill();
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
    if (ballCount > 0) {
        ballCount--;
    }
}

std::ostream& operator<<(std::ostream& os, const GumballMachine& gm)
{
    auto gumballCount = gm.getCount();
    
    os << "\nMighty Gumball, Inc.\nC++_enabled Standing Gumball Model #2018\n";
    
    if (gumballCount > 1) {
        os << "Inventory: " << gumballCount << " gumballs\n";
    } else if (gumballCount == 1) {
        os << "Inventory: " << gumballCount << " gumball\n";
    } else {
        os << "Inventory: EMPTY\n";
    }
    
    os << gm.printState() << std::endl;
    
    return os;
}


} // end of namespace MightyGumball
