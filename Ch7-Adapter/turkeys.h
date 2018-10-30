#ifndef TURKEYS_H
#define TURKEYS_H

#include "interfaces.h"

namespace Birds {


class WildTurkey : public Turkey {
public:
    void gobble() const override;
    void fly() const override;
};


} // end of namespace Birds


#endif
