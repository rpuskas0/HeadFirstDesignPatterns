#include "veggies.h"
#include <iostream>

namespace PizzaFranchise {


std::string BlackOlives::print() const
{
    std::string desc = "Black Olives";
    return desc;
}

std::string EggPlant::print() const
{
    std::string desc = "Egg Plant";
    return desc;
}

std::string Garlic::print() const
{
    std::string desc = "Garlic";
    return desc;
}

std::string Mushroom::print() const
{
    std::string desc = "Mushroom";
    return desc;
}

std::string Onion::print() const
{
    std::string desc = "Onion";
    return desc;
}

std::string RedPepper::print() const
{
    std::string desc = "Red Pepper";
    return desc;
}

std::string Spinach::print() const
{
    std::string desc = "Spinach";
    return desc;
}

std::ostream& operator<<(std::ostream& os, const Veggies& v)
{
    os << v.print();
    return os;
}


} // end of namespace PizzaFranchise
