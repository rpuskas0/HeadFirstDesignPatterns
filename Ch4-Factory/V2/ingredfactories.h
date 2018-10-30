#ifndef INGREDFACTORIES_H
#define INGREDFACTORIES_H

#include "cheese.h"
#include "clams.h"
#include "doughs.h"
#include "pepperoni.h"
#include "sauces.h"
#include "veggies.h"
#include <memory>
#include <vector>

namespace PizzaFranchise {


class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() {}
    
    virtual std::unique_ptr<Dough> createDough() = 0;
    virtual std::unique_ptr<Sauce> createSauce() = 0;
    virtual std::unique_ptr<Cheese> createCheese() = 0;
    virtual std::vector<std::unique_ptr<Veggies>> createVeggies() = 0;
    virtual std::unique_ptr<Pepperoni> createPepperoni() = 0;
    virtual std::unique_ptr<Clams> createClam() = 0;
};

// ----------

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    std::unique_ptr<Dough> createDough() override;
    std::unique_ptr<Sauce> createSauce() override;
    std::unique_ptr<Cheese> createCheese() override;
    std::vector<std::unique_ptr<Veggies>> createVeggies() override;
    std::unique_ptr<Pepperoni> createPepperoni() override;
    std::unique_ptr<Clams> createClam() override;
};

// ----------

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    std::unique_ptr<Dough> createDough() override;
    std::unique_ptr<Sauce> createSauce() override;
    std::unique_ptr<Cheese> createCheese() override;
    std::vector<std::unique_ptr<Veggies>> createVeggies() override;
    std::unique_ptr<Pepperoni> createPepperoni() override;
    std::unique_ptr<Clams> createClam() override;
};


} // end of namespace PizzaFranchise

#endif
