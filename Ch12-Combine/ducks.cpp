#include "ducks.h"
#include <iostream>

namespace SimUDuck {


MallardDuck::MallardDuck()
{
    observable = std::make_unique<Observable>(*this);
}

void MallardDuck::quack()
{
    std::cout << "Quack" << std::endl;
    notifyObservers();
}

void MallardDuck::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observable->registerObserver(obs);
}

void MallardDuck::notifyObservers() const
{
    observable->notifyObservers();
}

std::string MallardDuck::print() const
{
    std::string name {"Mallard Duck"};
    return name;
}

// ----------

RedheadDuck::RedheadDuck()
{
    observable = std::make_unique<Observable>(*this);
}

void RedheadDuck::quack()
{
    std::cout << "Quack" << std::endl;
    notifyObservers();
}

void RedheadDuck::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observable->registerObserver(obs);
}

void RedheadDuck::notifyObservers() const
{
    observable->notifyObservers();
}

std::string RedheadDuck::print() const
{
    std::string name {"Redhead Duck"};
    return name;
}

// ----------

DuckCall::DuckCall() {
    observable = std::make_unique<Observable>(*this);
}

void DuckCall::quack()
{
    std::cout << "Kwak" << std::endl;
    notifyObservers();
}

void DuckCall::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observable->registerObserver(obs);
}

void DuckCall::notifyObservers() const
{
    observable->notifyObservers();
}

std::string DuckCall::print() const
{
    std::string name {"Duck Call"};
    return name;
}

// ----------

RubberDuck::RubberDuck()
{
    observable = std::make_unique<Observable>(*this);
}

void RubberDuck::quack()
{
    std::cout << "Squeak" << std::endl;
    notifyObservers();
}

void RubberDuck::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observable->registerObserver(obs);
}

void RubberDuck::notifyObservers() const
{
    observable->notifyObservers();
}

std::string RubberDuck::print() const
{
    std::string name {"Rubber Duck"};
    return name;
}


} // end of namespace SimUDuck
