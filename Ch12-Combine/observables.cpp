#include "observables.h" 
#include <utility>
#include <iostream>

namespace SimUDuck {


void Observable::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observers.emplace_back(obs);
}

void Observable::notifyObservers() const
{
    for (auto obs : observers) {
        if (auto inst = obs.lock()) {
            inst->update(duck);
        }
    }
}


} // end of namespace SimUDuck
