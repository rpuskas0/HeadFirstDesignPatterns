#ifndef DUCKS_H
#define DUCKS_H

#include "interfaces.h"

namespace Birds {
    

class MallardDuck : public Duck {
public:
    void quack() const override;
    void fly() const override;
};


} // end of namespace Birds

#endif
