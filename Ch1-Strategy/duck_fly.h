#ifndef DUCKFLY
#define DUCKFLY

#include <iostream>

class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

class FlyWithWings : public FlyBehavior {
public:
    void fly() override { std::cout << "I'm flying\n"; }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override { std::cout << "I can't fly\n"; }
};

class FlyRocketPowered : public FlyBehavior {
public:
    void fly() override { std::cout << "I'm flying with a rocket!\n"; }
};

#endif
