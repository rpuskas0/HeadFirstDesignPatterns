#include "adapters.h"
#include <utility>

namespace SimUDuck {


GooseAdapter::GooseAdapter(std::unique_ptr<Honkable> honky)
    : goose(std::move(honky))
{
    observable = std::make_unique<Observable>(*this);
}

void GooseAdapter::quack()
{
    goose->honk();
    notifyObservers();
}

void GooseAdapter::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observable->registerObserver(obs);
}

void GooseAdapter::notifyObservers() const
{
    observable->notifyObservers();
}

std::string GooseAdapter::print() const
{
    std::string name {"Goose pretending to be a Duck"};
    return name;
}


} // end of namespace SimUDuck
