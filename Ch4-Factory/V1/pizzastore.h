#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "pizza.h"
#include <string>
#include <memory>

namespace PizzaFranchise {


class PizzaStore {
public:
    virtual ~PizzaStore() {}
    
    std::unique_ptr<Pizza> orderPizza(const std::string& type);

protected:
    virtual std::unique_ptr<Pizza> createPizza(const std::string& type) const = 0;
};

// ----------

class NYPizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string& type) const override;
};

// ----------

class ChicagoPizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string& type) const override;
};


} // end of namespace PizzaFranchise

#endif
