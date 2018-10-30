#include "doughs.h"
#include <iostream>

namespace PizzaFranchise {


std::string ThickCrustDough::print() const
{
    std::string desc = "ThickCrust style extra thick crust dough";
    return desc;
} 

std::string ThinCrustDough::print() const
{
    std::string desc = "Thin Crust Dough";
    return desc;
}

std::ostream& operator<<(std::ostream& os, const Dough& d)
{   
    os << d.print();
    return os;
}


} // end of namespace PizzaFranchise
