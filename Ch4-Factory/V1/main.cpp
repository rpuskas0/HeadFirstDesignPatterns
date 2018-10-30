#include "pizza.h" 
#include "pizzastore.h"
#include <memory>
#include <utility>
#include <iostream>

using namespace PizzaFranchise;

int main() {
    std::unique_ptr<PizzaStore> nyStore = std::make_unique<NYPizzaStore>();
    std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();
    
    auto pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << "\n" << std::endl;
    
    auto pizza2 = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza2->getName() << "\n" << std::endl;
}
