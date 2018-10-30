#ifndef DECORATORS_H
#define DECORATORS_H

#include "interfaces.h"
#include "observables.h"
#include <memory>
#include <string>
#include <utility>

namespace SimUDuck {


class QuackCounter : public Quackable {
public:
    QuackCounter(std::unique_ptr<Quackable> quacker);
    
    static int getQuacks() {return numberOfQuacks;}
    
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;

private:
    std::string print() const override;
    std::unique_ptr<Quackable> duck;
    static int numberOfQuacks;
};


} // end of namespace SimUDuck


#endif
