#ifndef PIZZA_H
#define PIZZA_H

#include "cheese.h"
#include "clams.h"
#include "doughs.h"
#include "ingredfactories.h"
#include "pepperoni.h"
#include "sauces.h"
#include "veggies.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace PizzaFranchise {


class Pizza {
public:
    virtual ~Pizza() {}
    
    virtual void prepare() = 0;
    
    void bake() const;
    virtual void cut() const;
    virtual void box() const final;
    
    virtual void setName(const std::string& nname);
    virtual std::string getName() const noexcept
        {return name;}
        
    friend std::ostream& operator<<(std::ostream& os, const Pizza& p);

protected:
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory{nullptr};
    std::unique_ptr<Dough> dough{nullptr};
    std::unique_ptr<Sauce> sauce{nullptr};
    std::unique_ptr<Cheese> cheese{nullptr};
    std::unique_ptr<Pepperoni> pepperoni{nullptr};
    std::unique_ptr<Clams> clam{nullptr};
    std::string name;
    std::vector<std::unique_ptr<Veggies>> veggies;
};

// ----------

class CheesePizza : public Pizza {
public:
    CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry);
        
    void prepare() override;
};

// ----------

class ClamPizza : public Pizza {
public:
    ClamPizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry);
        
    void prepare() override;
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry);
        
    void prepare() override;
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> ingrFactry);
        
    void prepare() override;
};


} // end of namespace PizzaFranchise


#endif
