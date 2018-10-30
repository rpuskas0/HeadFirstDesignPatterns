#include "observers.h"
#include <iostream>


namespace SimUDuck {


void Quackologist::update(QuackObservable& duck) const
{
    std::cout << "Quackologist: " << duck << " just quacked." << std::endl;
}


} // end of namespace SimUDuck
