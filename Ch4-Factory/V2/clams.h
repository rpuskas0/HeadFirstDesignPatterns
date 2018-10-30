#ifndef CLAMS_H
#define CLAMS_H

#include <string>

namespace PizzaFranchise {


class Clams {
public:
    virtual ~Clams() {}
    
    virtual std::string print() const = 0;
};

// ----------

class FreshClams : public Clams {
public:
    std::string print() const override;
};

class FrozenClams : public Clams {
public:
    std::string print() const override;
};


} // end of namespace PizzaFranchise

#endif
