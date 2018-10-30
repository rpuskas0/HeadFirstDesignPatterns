#ifndef DRINKS_H
#define DRINKS_H

#include "beverage.h"
#include <string>

namespace Starbuzz {
    
class Espresso : public Beverage {
public:
    Espresso();
};


class HouseBlend : public Beverage {
public:
    HouseBlend();
};


class DarkRoast : public Beverage {
public:
    DarkRoast();
};


class Decaf : public Beverage {
    Decaf();
};

} // end of namespace Starbuzz

#endif
