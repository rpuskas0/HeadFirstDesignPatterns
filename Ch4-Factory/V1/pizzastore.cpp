#include "pizzastore.h"
#include <utility>

namespace PizzaFranchise {


std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string& type)
{
    std::unique_ptr<Pizza> pizza;
    
    pizza = createPizza(type);
    
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    
    return pizza;
}

// ----------

std::unique_ptr<Pizza> NYPizzaStore::createPizza(const std::string& type) const
{
    if (type == "cheese") {
        return std::make_unique<NYStyleCheesePizza>();
    } else if (type == "veggie") {
        return std::make_unique<NYStyleVeggiePizza>();
    } else if (type == "clam") {
        return std::make_unique<NYStyleClamPizza>();
    } else if (type == "pepperoni") {
        return std::make_unique<NYStylePepperoniPizza>();
    } else {
        return nullptr;
    }
}

// ----------

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(const std::string& type) const
{
    if (type == "cheese") {
        return std::make_unique<ChicagoStyleCheesePizza>();
    } else if (type == "veggie") {
        return std::make_unique<ChicagoStyleVeggiePizza>();
    } else if (type == "clam") {
        return std::make_unique<ChicagoStyleClamPizza>();
    } else if (type == "pepperoni") {
        return std::make_unique<ChicagoStylePepperoniPizza>();
    } else {
        return nullptr;
    }
}



} // end of namespace PizzaFranchise
