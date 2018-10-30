#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "interfaces.h"
#include "observables.h"
#include <memory>
#include <string>

namespace SimUDuck {


class GooseAdapter : public Quackable {
public:
    GooseAdapter(std::unique_ptr<Honkable> honky);
        
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;


private:
    std::string print() const override;
    std::unique_ptr<Honkable> goose;
    std::unique_ptr<Observable> observable;
};


} // end of namespace SimUDuck


#endif
