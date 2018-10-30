#ifndef CONDINMENTS_H
#define CONDINMENTS_H

#include "beverage.h"
#include <memory>
#include <string>

namespace Starbuzz {
    

class Mocha : public CondimentDecorator {
public:
    Mocha(std::unique_ptr<Beverage> bever)
    {
        beverage = std::move(bever);
    }
    
    std::string getDescription() const override;
    double cost() const noexcept override;
};


class SteamedMilk : public CondimentDecorator {
public:
    SteamedMilk(std::unique_ptr<Beverage> bever)
    {
        beverage = std::move(bever);
    }
    
    std::string getDescription() const override;
    double cost() const noexcept override;
};


class Soy : public CondimentDecorator {
public:
    Soy(std::unique_ptr<Beverage> bever)
    {
        beverage = std::move(bever);
    }
    
    std::string getDescription() const override;
    double cost() const noexcept override;
};


class Whip : public CondimentDecorator {
public:
    Whip(std::unique_ptr<Beverage> bever)
    {
        beverage = std::move(bever);
    }
    
    std::string getDescription() const override;
    double cost() const noexcept override;    
};

} // end of namespace Starbuzz


#endif
