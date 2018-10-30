#include "decorators.h"
#include <sstream>

namespace SimUDuck {


QuackCounter::QuackCounter(std::unique_ptr<Quackable> quacker)
    : duck(std::move(quacker))
{
}

void QuackCounter::quack()
{
    duck->quack();
    numberOfQuacks++;
}

void QuackCounter::registerObserver(const std::shared_ptr<Observer>& obs)
{
    duck->registerObserver(obs);
}

void QuackCounter::notifyObservers() const
{
    duck->notifyObservers();
}

std::string QuackCounter::print() const
{
    // an ugly way to bypass the privateness of print() in Quackables
    std::ostringstream oss;
    oss << *duck;
    return oss.str();
}

int QuackCounter::numberOfQuacks = 0;
    

} // end of namespace SimUDuck
