#include "turkeys.h"
#include <iostream>

namespace Birds {


void WildTurkey::gobble() const
{
    std::cout << "Gobble gobble" << std::endl;
}

void WildTurkey::fly() const
{
    std::cout << "I'm flying a short distance" << std::endl;
}


} // end of namespace Birds
