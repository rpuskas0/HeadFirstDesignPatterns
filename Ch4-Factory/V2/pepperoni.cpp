#include "pepperoni.h"
#include <iostream>

namespace PizzaFranchise {


std::string SlicedPepperoni::print() const
{
    std::string desc = "Sliced Pepperoni";
    return desc;
}  

std::ostream& operator<<(std::ostream& os, const Pepperoni& p)
{
    os << p.print();
    return os;
}


} // end of namespace PizzaFranchise
