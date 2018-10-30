#ifndef OBSERVERS_H
#define OBSERVERS_H

#include "interfaces.h"

namespace SimUDuck {


class Quackologist : public Observer {
public:
    void update(QuackObservable& duck) const override;
};


} // end of namespace SimUDuck


#endif
