#include "interfaces.h"
#include <iostream>

namespace SimUDuck {


std::ostream& operator<<(std::ostream& os, const QuackObservable& quacky)
{
    os << quacky.print();
    return os;
}

// ----------

std::ostream& operator<<(std::ostream& os, const Honkable& honky)
{
    os << honky.print();
    return os;
}

} // end of namespace SimUDuck
