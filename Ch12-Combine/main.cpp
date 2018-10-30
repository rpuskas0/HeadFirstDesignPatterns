#include "adapters.h"
#include "composite.h"
#include "decorators.h"
#include "ducks.h"
#include "factories.h"
#include "geese.h"
#include "interfaces.h"
#include "observables.h"
#include "observers.h"
#include <iostream>
#include <memory>


using AbstractDuckFactory = SimUDuck::AbstractDuckFactory;
using CountingDuckFactory = SimUDuck::CountingDuckFactory;
using Flock = SimUDuck::Flock;
using Goose = SimUDuck::Goose;
using Quackable = SimUDuck::Quackable;
using QuackCounter = SimUDuck::QuackCounter;
using Quackologist = SimUDuck::Quackologist;


void simulate(Quackable& duck)
{
    duck.quack();
}

void simulate(AbstractDuckFactory& duckFactory)
{ // Whoa! A gigantic function it is!
    
    auto mallardDuck = std::shared_ptr<Quackable>{ duckFactory.createMallardDuck() };
    auto redheadDuck = std::shared_ptr<Quackable>{ duckFactory.createRedheadDuck() };
    auto duckCall = std::shared_ptr<Quackable>{ duckFactory.createDuckCall() };
    auto rubberDuck = std::shared_ptr<Quackable>{ duckFactory.createRubberDuck() };
    auto gooseDuck = duckFactory.createQuackable(std::make_unique<Goose>());
    
    std::cout << "Duck Simulator" << std::endl;
    
    auto flockOfDucks = std::make_shared<Flock>();
    
    flockOfDucks->add(mallardDuck);
    flockOfDucks->add(redheadDuck);
    flockOfDucks->add(duckCall);
    flockOfDucks->add(rubberDuck);
    
    
    
    auto flockOfMallards = std::make_shared<Flock>();
    
    auto mallardOne = std::shared_ptr<Quackable>{ duckFactory.createMallardDuck() };
    auto mallardTwo = std::shared_ptr<Quackable>{ duckFactory.createMallardDuck() };
    auto mallardThree = std::shared_ptr<Quackable>{ duckFactory.createMallardDuck() };
    auto mallardFour = std::shared_ptr<Quackable>{ duckFactory.createMallardDuck() };
    
    flockOfMallards->add(mallardOne);
    flockOfMallards->add(mallardTwo);
    flockOfMallards->add(mallardThree);
    flockOfMallards->add(mallardFour);
    
    flockOfDucks->add(flockOfMallards);
    
    
    
    auto quackologist = std::make_shared<Quackologist>();
    flockOfDucks->registerObserver(quackologist);


    
    std::cout << "\nDuck Simulator: Whole Flock Simulation" << std::endl;
    simulate(*flockOfDucks);
    
    std::cout << "\nDuck Simulator: Mallard Flock Simulation" << std::endl;
    simulate(*flockOfMallards);

    
    
    std::cout << "\nThe ducks quacked " << QuackCounter::getQuacks() << " times" << std::endl;
    
}

int main() {
    
    auto duckFactory = CountingDuckFactory();
    simulate(duckFactory);
    
}
