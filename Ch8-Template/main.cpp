#include "CaffeineBeverages.h"
#include <iostream>


using Tea = Beverages::Tea;
using Coffee = Beverages::Coffee;

int main() {
    
    Tea teaHook;
    Coffee coffeeHook;
    
    std::cout << "\nMaking Tea..." << std::endl;
    teaHook.prepareRecipe();
    
    std::cout << "\nMaking Coffee..." << std::endl;
    coffeeHook.prepareRecipe();
    
    return 0;
}
