#ifndef CONDINMENTS_H
#define CONDINMENTS_H

#include "beverage.h"
#include <memory>
#include <string>

namespace Starbuzz {

    
class Mocha : public CondimentDecorator {
public:
    Mocha(std::unique_ptr<Beverage> bever);
    
};


class SteamedMilk : public CondimentDecorator {
public:
    SteamedMilk(std::unique_ptr<Beverage> bever);
    
};


class Soy : public CondimentDecorator {
public:
    Soy(std::unique_ptr<Beverage> bever);
    
};


class Whip : public CondimentDecorator {
public:
    Whip(std::unique_ptr<Beverage> bever);
    
};

} // end of namespace Starbuzz


#endif
