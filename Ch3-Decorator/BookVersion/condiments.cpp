#include "condiments.h"

namespace Starbuzz {


std::string Mocha::getDescription() const
{
    return beverage->getDescription() + std::string("; Mocha");
}
    
double Mocha::cost() const noexcept
{
    switch (beverage->getSize()) {
        case TALL:
            return beverage->cost() + 0.15;
        case GRANDE:
            return beverage->cost() + 0.20;
        case VENTI:
            return beverage->cost() + 0.25;
    }     
}

// ----------

std::string SteamedMilk::getDescription() const
{
    return beverage->getDescription() + std::string("; Steamed Milk");
}

double SteamedMilk::cost() const noexcept
{
    switch (beverage->getSize()) {
        case TALL:
            return beverage->cost() + 0.05;
        case GRANDE:
            return beverage->cost() + 0.10;
        case VENTI:
            return beverage->cost() + 0.15;
    }
}

// ----------

std::string Soy::getDescription() const
{
    return beverage->getDescription() + std::string("; Soy");
}

double Soy::cost() const noexcept
{
    switch (beverage->getSize()) {
        case TALL:
            return beverage->cost() + 0.10;
        case GRANDE:
            return beverage->cost() + 0.15;
        case VENTI:
            return beverage->cost() + 0.20;
    }
}

// ----------

std::string Whip::getDescription() const
{
    return beverage->getDescription() + std::string("; Whip");
}

double Whip::cost() const noexcept
{
    switch (beverage->getSize()) {
        case TALL:
            return beverage->cost() + 0.05;
        case GRANDE:
            return beverage->cost() + 0.10;
        case VENTI:
            return beverage->cost() + 0.15;
    }
}


} // end of namespace Starbuzz
