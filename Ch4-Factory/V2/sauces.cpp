#include "sauces.h"
#include <iostream>

namespace PizzaFranchise {


std::string MarinaraSauce::print() const
{
    std::string desc = "Marinara Sauce";
    return desc;
}  

std::string PlumTomatoSauce::print() const
{
    std::string desc = "Tomato sauce with plum tomatoes";
    return desc;
}  

std::ostream& operator<<(std::ostream& os, const Sauce& s)
{
    os << s.print();
    return os;
}


} // end of namespace PizzaFranchise
