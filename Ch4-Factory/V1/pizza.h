#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>

namespace PizzaFranchise {


class Pizza {
public:
    virtual ~Pizza() {}
    Pizza() = delete;
    
    virtual void prepare() const final;
    virtual void bake() const;
    virtual void cut() const;
    virtual void box() const final;
    
    std::string getName() const noexcept {return name;}
    
protected:
    Pizza(const std::string& nname, const std::string& ddough, const std::string& ssauce);
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;
};

// ----------

class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza();
};

// ----------

class NYStyleClamPizza : public Pizza {
public:
    NYStyleClamPizza();
};

// ----------

class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza();
};

// ----------

class NYStyleVeggiePizza : public Pizza {
public:
    NYStyleVeggiePizza();
};

// ----------

class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza();
    
    void cut() const override;
};

// ----------

class ChicagoStyleClamPizza : public Pizza {
public:
    ChicagoStyleClamPizza();
    
    void cut() const override;
};

// ----------

class ChicagoStylePepperoniPizza : public Pizza {
public:
    ChicagoStylePepperoniPizza();
    
    void cut() const override;
};

// ----------

class ChicagoStyleVeggiePizza : public Pizza {
public:
    ChicagoStyleVeggiePizza();
    
    void cut() const override;
};

} // end of namespace PizzaFranchise

#endif
