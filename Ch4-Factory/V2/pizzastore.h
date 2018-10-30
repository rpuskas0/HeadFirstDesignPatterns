#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "pizza.h"
#include <string>
#include <memory>

namespace PizzaFranchise {


class PizzaStore {
public:
    std::unique_ptr<Pizza> orderPizza(const std::string& type);

protected:
    virtual std::unique_ptr<Pizza> createPizza(const std::string& item) = 0;
};

// ----------

class NYPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(const std::string& item) override;
};

// ----------

class ChicagoPizzaStore : public PizzaStore {
private:
    std::unique_ptr<Pizza> createPizza(const std::string& item) override;
};


} // end of namespace PizzaFranchise

#endif
