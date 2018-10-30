#ifndef VEGGIES_H
#define VEGGIES_H

#include <string>

namespace PizzaFranchise {


class Veggies {
public:
    virtual ~Veggies() {}

    virtual std::string print() const = 0;
};

// ----------

class BlackOlives : public Veggies {
public:
    std::string print() const override;
};

class EggPlant : public Veggies {
public:
    std::string print() const override;
};

class Garlic : public Veggies {
public:
    std::string print() const override;
};

class Mushroom : public Veggies {
public:
    std::string print() const override;
};

class Onion : public Veggies {
public:
    std::string print() const override;
};

class RedPepper : public Veggies {
public:
    std::string print() const override;
};

class Spinach : public Veggies {
public:
    std::string print() const override;    
};


} // end of namespace PizzaFranchise

#endif
