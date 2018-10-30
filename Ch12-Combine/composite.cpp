#include "composite.h"
#include <utility>

namespace SimUDuck {


void Flock::add(const std::shared_ptr<Quackable>& quacker)
{
    quackers.emplace_back(quacker);
} 

void Flock::quack()
{
    for(auto weak : quackers) {
        if (auto bird = weak.lock()) {
            bird->quack();
        }
    }
}

void Flock::registerObserver(const std::shared_ptr<Observer>& obs)
{
    for (auto weak : quackers) {
        if (auto bird = weak.lock()) {
            bird->registerObserver(obs);
        }
    }
}

void Flock::notifyObservers() const
{
}

std::string Flock::print() const
{
    std::string name {"Flock of Quackers"};
}


} // end of namespace SimUDuck
