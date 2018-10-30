#include "ducks.h"
#include <iostream>

namespace Birds {


void MallardDuck::quack() const
{
    std::cout << "Quack" << std::endl;
}

void MallardDuck::fly() const
{
    std::cout << "I'm flying" << std::endl;
}


} // end of namespace Birds
