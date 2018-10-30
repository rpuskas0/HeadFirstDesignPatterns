#ifndef DOUGHS_H
#define DOUGHS_H

#include <string>

namespace PizzaFranchise {


class Dough {
public:
    virtual ~Dough() {}
    
    virtual std::string print() const = 0;
};

// ----------

class ThickCrustDough : public Dough {
public:
    std::string print() const override;
};

class ThinCrustDough : public Dough {
public:
    std::string print() const override;
};


} // end of namespace PizzaFranchise

#endif
