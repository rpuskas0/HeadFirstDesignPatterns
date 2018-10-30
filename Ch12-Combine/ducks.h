#ifndef DUCKS_H
#define DUCKS_H

#include "interfaces.h"
#include "observables.h"
#include <memory>
#include <string>

namespace SimUDuck {


class MallardDuck : public Quackable {
public:
    MallardDuck();
    
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;
    
private:
    std::string print() const override;
    std::unique_ptr<Observable> observable;
};

// ----------

class RedheadDuck : public Quackable {
public:
    RedheadDuck();
    
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;
    
private:
    std::string print() const override;
    std::unique_ptr<Observable> observable;
};

// ----------

class DuckCall : public Quackable {
public:
    DuckCall();
    
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;
    
private:
    std::string print() const override;
    std::unique_ptr<Observable> observable;
};

// -----------

class RubberDuck : public Quackable {
public:
    RubberDuck();
    
    void quack() override;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() const override;
    
private:
    std::string print() const override;
    std::unique_ptr<Observable> observable;
};

} // end of namespace SimUDuck


#endif
