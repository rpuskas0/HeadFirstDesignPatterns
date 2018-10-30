#include "adapters.h"
#include <random>

namespace Birds {


TurkeyAdapter::TurkeyAdapter(Turkey& tturkey)
    : turkey{tturkey} {}

void TurkeyAdapter::quack() const
{
    turkey.gobble();
}

void TurkeyAdapter::fly() const
{
    for (int i = 0; i < 5; i++) {
        turkey.fly();
    }
}

// ----------

DuckAdapter::DuckAdapter(Duck& dduck)
    : duck{dduck} {}
    
void DuckAdapter::gobble() const
{
    duck.quack();
}

void DuckAdapter::fly() const
{   
    std::random_device rd;
    std::default_random_engine random(rd());
    std::uniform_int_distribution<> dis(0, 5);
    if (dis(random) == 0) {
        duck.fly();
    }
}


} // end of namespace Birds
