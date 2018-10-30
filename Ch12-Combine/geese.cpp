#include "geese.h"

namespace SimUDuck {


void Goose::honk()
{
    std::cout << "Honk" << std::endl;
}

std::string Goose::print() const
{
    std::string name {"Goose"};
    return name;
}


} // end of namespace SimUDuck
