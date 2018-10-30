#include "clams.h"
#include <iostream>

namespace PizzaFranchise {


std::string FreshClams::print() const
{
    std::string desc = "Fresh Clams from Long Island Sound";
    return desc;
}  

std::string FrozenClams::print() const
{
    std::string desc = "Frozen Clams from Chesapeake Bay";
    return desc;
}  

std::ostream& operator<<(std::ostream& os, const Clams& c)
{
    os << c.print();
    return os;
}


} // end of namespace PizzaFranchise
