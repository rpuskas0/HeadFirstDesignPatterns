#include "condiments.h"

namespace Starbuzz {


Mocha::Mocha(std::unique_ptr<Beverage> bever)
    : CondimentDecorator(std::move(bever), 0.15, 0.20, 0.25)
{
    description = "; Mocha";
}    
    
// ----------

SteamedMilk::SteamedMilk(std::unique_ptr<Beverage> bever)
    : CondimentDecorator(std::move(bever), 0.05, 0.10, 0.15)
{
    description = "; Steamed Milk";
}

// ----------

Soy::Soy(std::unique_ptr<Beverage> bever)
    : CondimentDecorator(std::move(bever), 0.10, 0.15, 0.20)
{
    description = "; Soy";
}

// ----------

Whip::Whip(std::unique_ptr<Beverage> bever)
    : CondimentDecorator(std::move(bever), 0.05, 0.10, 0.15)
{
    description = "; Whip";
}


} // end of namespace Starbuzz
