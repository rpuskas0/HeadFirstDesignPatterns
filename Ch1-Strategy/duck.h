#ifndef DUCK
#define DUCK

#include "duck_fly.h"
#include "duck_quack.h"
#include <iostream>
#include <memory>
#include <utility>

class Duck {
public:
    Duck(std::unique_ptr<QuackBehavior> qb, std::unique_ptr<FlyBehavior> fb)
        : quackbehavior(std::move(qb)), flybehavior(std::move(fb)) {}
    virtual ~Duck() {}
    
    virtual void display() = 0;
    
    void performFly() { flybehavior->fly(); }
    void performQuack() { quackbehavior->quack(); }
    void swim() { std::cout << "All ducks float, even decoys!\n"; }
    
    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb) { flybehavior = std::move(fb); }
    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb) { quackbehavior = std::move(qb); }
    
protected:
    std::unique_ptr<QuackBehavior> quackbehavior;
    std::unique_ptr<FlyBehavior> flybehavior;
};

class MallardDuck : public Duck {
public:
    MallardDuck()
        : Duck(std::make_unique<Quack>(), std::make_unique<FlyWithWings>())
    {
    }
        
    void display() override { std::cout << "I'm a real Mallard duck\n"; }
};

class ModelDuck : public Duck {
public:
    ModelDuck()
        : Duck(std::make_unique<Quack>(), std::make_unique<FlyWithWings>())
    {
    }
    
    void display() override { std::cout << "I'm a model duck\n"; }
};

#endif
