#ifndef OBSERVABLES_H
#define OBSERVABLES_H

#include "interfaces.h"
#include <vector>
#include <memory>
#include <string>

namespace SimUDuck {


class Observable : public QuackObservable {
public:
    Observable(QuackObservable& dduck)
        : duck(dduck) {}
        
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;

private:
    std::vector<std::weak_ptr<Observer>> observers;
    QuackObservable& duck;
};


} // end of namespace SimUDuck

#endif
