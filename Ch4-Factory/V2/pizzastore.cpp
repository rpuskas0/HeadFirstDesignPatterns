#include "pizzastore.h"
#include <iostream>

namespace PizzaFranchise {


std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string& type)
{
    auto pizza = createPizza(type);
    std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    
    return pizza;
}

// ----------

std::unique_ptr<Pizza> NYPizzaStore::createPizza(const std::string& item)
{
    std::unique_ptr<Pizza> pizza;
        
    if (item == "cheese") {        
        pizza = std::make_unique<CheesePizza>(std::make_unique<NYPizzaIngredientFactory>());
        pizza->setName("New York Style Cheese Pizza");
    
    } else if (item == "veggie") {
        pizza = std::make_unique<VeggiePizza>(std::make_unique<NYPizzaIngredientFactory>());
        pizza->setName("New York Style Veggie Pizza");
    
    } else if (item == "clam") {
        pizza = std::make_unique<ClamPizza>(std::make_unique<NYPizzaIngredientFactory>());
        pizza->setName("New York Style Clam Pizza");
        
    } else if (item == "pepperoni") {
        pizza = std::make_unique<PepperoniPizza>(std::make_unique<NYPizzaIngredientFactory>());
        pizza->setName("New York Style Pepperoni Pizza");
    }
    
    return pizza;
}

// ----------

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(const std::string& item)
{
    std::unique_ptr<Pizza> pizza;
        
    if (item == "cheese") {        
        pizza = std::make_unique<CheesePizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
        pizza->setName("New York Style Cheese Pizza");
    
    } else if (item == "veggie") {
        pizza = std::make_unique<VeggiePizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
        pizza->setName("New York Style Veggie Pizza");
    
    } else if (item == "clam") {
        pizza = std::make_unique<ClamPizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
        pizza->setName("New York Style Clam Pizza");
        
    } else if (item == "pepperoni") {
        pizza = std::make_unique<PepperoniPizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
        pizza->setName("New York Style Pepperoni Pizza");
    }
    
    return pizza;
}


} // End of namespace PizzaFranchise
