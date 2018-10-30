#include "chocoboiler.h"
#include <utility>
#include <iostream>

namespace Choco {


std::unique_ptr<ChocolateBoiler> ChocolateBoiler::uniqueInstance = nullptr;
std::mutex ChocolateBoiler::instMutex;

std::unique_ptr<ChocolateBoiler>& ChocolateBoiler::getInstance()
{  
    struct MakeUptrEnabl : public ChocolateBoiler {};
    std::scoped_lock lck {instMutex};
    if (uniqueInstance == nullptr) {
        uniqueInstance = std::make_unique<MakeUptrEnabl>();
    }
    
    return uniqueInstance;
}

void ChocolateBoiler::fill()
{
    if (isEmpty()) {
        empty = false;
        boiled = false;
        std::cout << "Filling the boiler with milk/chocolate mixture" << std::endl;
    }
}

void ChocolateBoiler::drain()
{
    if (!isEmpty() && isBoiled()) {
        std::cout << "Draining boiled milk and chocolate" << std::endl;
        empty = true;
    }
}

void ChocolateBoiler::boil()
{
    if (!isEmpty() && !isBoiled()) {
        std::cout << "Bringing contents to a boil" << std::endl;
        boiled = true;
    }
}


} // end of namespace Choco
