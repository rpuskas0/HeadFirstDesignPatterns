#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "interfaces.h"
#include "observables.h"
#include <memory>
#include <string>
#include <vector>

namespace SimUDuck {


class Flock : public Quackable {
public:
    void add(const std::shared_ptr<Quackable>& quacker);
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;

private:
    std::string print() const override;
    std::vector<std::weak_ptr<Quackable>> quackers;
};


} // end of namespace SimUDuck

#endif
