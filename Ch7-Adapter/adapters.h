#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "interfaces.h"
#include <memory>

namespace Birds {


class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(Turkey& tturkey);
    
    void quack() const override;
    void fly() const override;
    
private:
    Turkey& turkey;
};

// ----------

class DuckAdapter : public Turkey {
public:
    DuckAdapter(Duck& dduck);
    
    void gobble() const override;
    void fly() const override;

private:
    Duck& duck;
};


} // end of namespace Birds


#endif
