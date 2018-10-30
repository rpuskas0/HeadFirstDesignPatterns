#include "cheese.h"
#include <iostream>

namespace PizzaFranchise {


std::string MozzarellaCheese::print() const
{
    std::string desc = "Shredded Mozzarella";
    return desc;
}  

std::string ParmesanCheese::print() const
{
    std::string desc = "Shredded Parmesan";
    return desc;
}  

std::string ReggianoCheese::print() const
{
    std::string desc = "Reggiano Cheese";
    return desc;
}  

std::ostream& operator<<(std::ostream& os, const Cheese& c)
{
    os << c.print();
    return os;
}


} // end of namespace PizzaFranchise
