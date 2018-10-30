#ifndef PEPPERONI_H
#define PEPPERONI_H

#include <string>

namespace PizzaFranchise {


class Pepperoni {
public:
    virtual ~Pepperoni() {}
    
    virtual std::string print() const = 0;
};

// ----------

class SlicedPepperoni : public Pepperoni {
public:
    std::string print() const override;
};


} // end of namespace PizzaFranchise

#endif
