#include "ingredfactories.h"


namespace PizzaFranchise {


std::unique_ptr<Dough> NYPizzaIngredientFactory::createDough()
{
    return std::make_unique<ThinCrustDough>();
}

std::unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce()
{
    return std::make_unique<MarinaraSauce>();
}

std::unique_ptr<Cheese> NYPizzaIngredientFactory::createCheese()
{
    return std::make_unique<ReggianoCheese>();
}

std::vector<std::unique_ptr<Veggies>> NYPizzaIngredientFactory::createVeggies()
{
    std::vector<std::unique_ptr<Veggies>> veggie;
    veggie.emplace_back(std::make_unique<Garlic>());
    veggie.emplace_back(std::make_unique<Onion>());
    veggie.emplace_back(std::make_unique<Mushroom>());
    veggie.emplace_back(std::make_unique<RedPepper>());
    
    return veggie;
}

std::unique_ptr<Pepperoni> NYPizzaIngredientFactory::createPepperoni()
{
    return std::make_unique<SlicedPepperoni>();
}

std::unique_ptr<Clams> NYPizzaIngredientFactory::createClam()
{
    return std::make_unique<FreshClams>();
}

// ----------

std::unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDough()
{
    return std::make_unique<ThickCrustDough>();
}

std::unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce()
{
    return std::make_unique<PlumTomatoSauce>();
}

std::unique_ptr<Cheese> ChicagoPizzaIngredientFactory::createCheese()
{
    return std::make_unique<MozzarellaCheese>();
}

std::vector<std::unique_ptr<Veggies>> ChicagoPizzaIngredientFactory::createVeggies()
{
    std::vector<std::unique_ptr<Veggies>> veggie;
    veggie.emplace_back(std::make_unique<BlackOlives>());
    veggie.emplace_back(std::make_unique<Spinach>());
    veggie.emplace_back(std::make_unique<EggPlant>());
    
    return veggie;
}

std::unique_ptr<Pepperoni> ChicagoPizzaIngredientFactory::createPepperoni()
{
    return std::make_unique<SlicedPepperoni>();
}

std::unique_ptr<Clams> ChicagoPizzaIngredientFactory::createClam()
{
    return std::make_unique<FrozenClams>();
}

} // end of namespace PizzaFranchise
