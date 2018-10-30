#ifndef CHEESE_H
#define CHEESE_H

#include <string>

namespace PizzaFranchise {


class Cheese {
public:
    virtual ~Cheese() {}
    
    virtual std::string print() const = 0;
};

// ----------

class MozzarellaCheese : public Cheese {
public:
    std::string print() const override;
};

class ParmesanCheese : public Cheese {
public:
    std::string print() const override;
};

class ReggianoCheese : public Cheese {
public:
    std::string print() const override;
};


} // end of namespace PizzaFranchise

#endif
