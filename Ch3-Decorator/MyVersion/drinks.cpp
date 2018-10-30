#include "drinks.h"

namespace Starbuzz {


Espresso::Espresso()
    : Beverage("Espresso", 1.29, 1.99, 2.69)
{
}

// ----------

HouseBlend::HouseBlend()
    : Beverage("House Blend Coffee", 0.59, 0.89, 1.19)
{
}


// ----------

DarkRoast::DarkRoast()
    : Beverage("Dark Roast Coffee", 0.69, 0.99, 1.29)
{
}


// ----------

Decaf::Decaf()
    : Beverage("Decaf Coffee", 0.69, 1.05, 1.39)
{
}

    
} // end of namespace Starbuzz
