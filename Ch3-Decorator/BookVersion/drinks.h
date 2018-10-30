#ifndef DRINKS_H
#define DRINKS_H

#include "beverage.h"
#include <string>

namespace Starbuzz {
    
class Espresso : public Beverage {
public:
    Espresso()
    {
        description = "Espresso";
    }
    
    double cost() const noexcept override;
};


class HouseBlend : public Beverage {
public:
    HouseBlend()
    {
        description = "House Blend Coffee";
    }
    
    double cost() const noexcept override;
};


class DarkRoast : public Beverage {
public:
    DarkRoast()
    {
        description = "Dark Roast Coffee";
    }
    
    double cost() const noexcept override;
};


class Decaf : public Beverage {
    Decaf()
    {
        description = "Decaf Coffee";
    }
    
    double cost() const noexcept override;
};

} // end of namespace Starbuzz

#endif
