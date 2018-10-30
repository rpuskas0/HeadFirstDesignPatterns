#include "pizza.h" 
#include <iostream>

namespace PizzaFranchise {


Pizza::Pizza(const std::string& nname, const std::string& ddough, const std::string& ssauce)
    : name{nname}, dough{ddough}, sauce{ssauce}
{
}
    
void Pizza::prepare() const
{
    std::cout << "Preparing " << name << "\n"
                << "Tossing dough...\n"
                << "Adding sauce...\n"
                << "Adding toppings:\n\t";
    for (auto topping : toppings) {
        std::cout << topping << ", ";
    }
    std::cout << std::endl;
}

void Pizza::bake() const
{
    std::cout << "Bake for 25 minutes at 350C" << std::endl;
}

void Pizza::cut() const
{
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box() const
{
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

// ----------

NYStyleCheesePizza::NYStyleCheesePizza()
    : Pizza("NY Style Sauce and Cheese Pizza",
            "Thin Crust Dough",
            "Marinara Sauce")
{
    toppings.emplace_back("Grated Reggiano Cheese");
}

// ----------

NYStyleClamPizza::NYStyleClamPizza()
    : Pizza("NY Style Clam Pizza",
            "Thin Crust Dough",
            "Marinara Sauce")
{
    toppings.emplace_back("Grated Reggiano Cheese");
    toppings.emplace_back("Fresh Clams from Long Island Sound");
}

// ----------

NYStylePepperoniPizza::NYStylePepperoniPizza()
    : Pizza("NY Style Pepperoni Pizza",
            "Thin Crust Dough",
            "Marinara Sauce")
{
    toppings.emplace_back("Grated Reggiano Cheese");
    toppings.emplace_back("Sliced Pepperoni");
    toppings.emplace_back("Garlic");
    toppings.emplace_back("Onion");
    toppings.emplace_back("Mushrooms");
    toppings.emplace_back("Red Pepper");
}

// ----------

NYStyleVeggiePizza::NYStyleVeggiePizza()
    : Pizza("NY Style Veggie Pizza",
            "Thin Crust Dough",
            "Marinara Sauce")
{
    toppings.emplace_back("Grated Reggiano Cheese");
    toppings.emplace_back("Garlic");
    toppings.emplace_back("Onion");
    toppings.emplace_back("Mushrooms");
    toppings.emplace_back("Red Pepper");
}

// ----------

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
    : Pizza("Chicago Style Deep Dish Cheese Pizza",
            "Extra Thick Crust Dough",
            "Plum Tomato Sauce")
{
    toppings.emplace_back("Shredded Mozarella Cheese");
}

void ChicagoStyleCheesePizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

// ----------

ChicagoStyleClamPizza::ChicagoStyleClamPizza()
    : Pizza("Chicago Style Clam Pizza",
            "Extra Thick Crust Dough",
            "Plum Tomato Sauce")
{
    toppings.emplace_back("Shredded Mozzarella Cheese");
    toppings.emplace_back("Frozen Clams from Chesapeake Bay");
}
 
void ChicagoStyleClamPizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

// ----------

ChicagoStylePepperoniPizza::ChicagoStylePepperoniPizza()
    : Pizza("Chicago Style Pepperoni Pizza",
            "Extra Thick Crust Dough",
            "Plum Tomato Sauce")
{
    toppings.emplace_back("Shredded Mozzarella Cheese");
    toppings.emplace_back("Black Olives");
    toppings.emplace_back("Spinach");
    toppings.emplace_back("Eggplant");
    toppings.emplace_back("Sliced Pepperoni");
}

void ChicagoStylePepperoniPizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}

// ----------

ChicagoStyleVeggiePizza::ChicagoStyleVeggiePizza()
    : Pizza("Chicago Deep Dish Veggie Pizza",
            "Extra Thick Crust Dough",
            "Plum Tomato Sauce")
{
    toppings.emplace_back("Shredded Mozzarella Cheese");
    toppings.emplace_back("Black Olives");
    toppings.emplace_back("Spinach");
    toppings.emplace_back("Eggplant");
}

void ChicagoStyleVeggiePizza::cut() const
{
    std::cout << "Cutting the pizza into square slices" << std::endl;
}


} // end of namespace PizzaFranchise
