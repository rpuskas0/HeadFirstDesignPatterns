#ifndef DUCKQUACK
#define DUCKQUACK

#include <iostream>

class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior {
    void quack() { std::cout << "Quack\n"; }
};

class MuteQuack : public QuackBehavior {
    void quack() { std::cout << "<< Silence >>\n"; }
};

class Squeak : public QuackBehavior {
    void quack() { std::cout << "Squeak\n"; }
};

#endif
