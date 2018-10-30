#ifndef SAUCES_H
#define SAUCES_H

#include <string>

namespace PizzaFranchise {


class Sauce {
public:
    virtual ~Sauce() {}
    
    virtual std::string print() const = 0;
};

// ----------

class MarinaraSauce : public Sauce {
public:
    std::string print() const override;
};

class PlumTomatoSauce : public Sauce {
public:
    std::string print() const override;
};


} // end of namespace PizzaFranchise

#endif
