#include "pizza.h"
#include <iostream>

namespace PizzaFranchise {


void Pizza::bake() const
{
    std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut() const
{
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box() const
{
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

void Pizza::setName(const std::string& nname)
{
    name = nname;
}

std::ostream& operator<<(std::ostream& os, const Pizza& p)
{
    os << "---- " << p.name << " ----\n";
    
    if (p.dough != nullptr) {
        os << p.dough->print() << "\n";
    }
    if (p.sauce != nullptr) {
        os << p.sauce->print() << "\n";
    }
    if (p.cheese != nullptr) {
        os << p.cheese->print() << "\n";
    }
    if (p.dough != nullptr) {
        os << p.dough->print() << "\n";
    }
    if (!p.veggies.empty()) {
        for (auto i = 0; i < p.veggies.size(); i++) {
            os << p.veggies[i]->print();
            if (i < p.veggies.size() - 1) {
                os << ",";
            }
        }
        os << "\n";
    }
    if (p.clam != nullptr) {
        os << p.clam->print() << "\n";
    }
    if (p.pepperoni != nullptr) {
        os << p.pepperoni->print() << "\n";
    }
    
    return os;
}

// ----------

CheesePizza::CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry)
{
    ingredientFactory = std::move(ingrFactry);
}

void CheesePizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
}

// ----------

ClamPizza::ClamPizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry)
{
    ingredientFactory = std::move(ingrFactry);
}

void ClamPizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
    clam = ingredientFactory->createClam();
}

VeggiePizza::VeggiePizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry)
{
    ingredientFactory = std::move(ingrFactry);
}

void VeggiePizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
    veggies = ingredientFactory->createVeggies();
}

PepperoniPizza::PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry)
{
    ingredientFactory = std::move(ingrFactry);
}

void PepperoniPizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
    pepperoni = ingredientFactory->createPepperoni();
}


} // end of namespace PizzaFranchise
