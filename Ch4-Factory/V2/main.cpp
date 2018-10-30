#include "pizzastore.h"
#include <iostream>

using NYPizzaStore = PizzaFranchise::NYPizzaStore;
using ChicagoPizzaStore = PizzaFranchise::ChicagoPizzaStore;
using Pizza = PizzaFranchise::Pizza;

int main() {
    
    auto nyStore = std::make_unique<NYPizzaStore>();
    auto chicagoStore = std::make_unique<ChicagoPizzaStore>();
    
    std::unique_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << *pizza << std::endl;
        
    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << *pizza << std::endl;
    
    return 0;
}
