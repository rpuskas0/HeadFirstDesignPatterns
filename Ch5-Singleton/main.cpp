#include "chocoboiler.h" 
#include <iostream>

using ChocolateBoiler = Choco::ChocolateBoiler;

int main()
{
    std::unique_ptr<ChocolateBoiler>& boiler = ChocolateBoiler::getInstance();
    boiler->fill();
    boiler->boil();
    boiler->drain();
    
    // returns reference to same instance
    std::unique_ptr<ChocolateBoiler>& boiler2 = ChocolateBoiler::getInstance();
    boiler2->fill();
    boiler2->boil();
    boiler2->drain();
}
