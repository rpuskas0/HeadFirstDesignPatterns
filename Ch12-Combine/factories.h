#ifndef FACTORIES_H
#define FACTORIES_H

#include "decorators.h"
#include <memory>

namespace SimUDuck {


class AbstractDuckFactory {
public:
    virtual ~AbstractDuckFactory() {}
    
    virtual std::unique_ptr<Quackable> createMallardDuck() = 0;
    virtual std::unique_ptr<Quackable> createRedheadDuck() = 0;
    virtual std::unique_ptr<Quackable> createDuckCall() = 0;
    virtual std::unique_ptr<Quackable> createRubberDuck() = 0;
    virtual std::unique_ptr<Quackable> createQuackable(std::unique_ptr<Honkable> bird) = 0;
};

// ----------

class DuckFactory : public AbstractDuckFactory {
public:
    std::unique_ptr<Quackable> createMallardDuck() override;
    std::unique_ptr<Quackable> createRedheadDuck() override;
    std::unique_ptr<Quackable> createDuckCall() override;
    std::unique_ptr<Quackable> createRubberDuck() override;
    std::unique_ptr<Quackable> createQuackable(std::unique_ptr<Honkable> bird) override;
};

// ----------

class CountingDuckFactory : public AbstractDuckFactory {
public:
    std::unique_ptr<Quackable> createMallardDuck() override;
    std::unique_ptr<Quackable> createRedheadDuck() override;
    std::unique_ptr<Quackable> createDuckCall() override;
    std::unique_ptr<Quackable> createRubberDuck() override;
    std::unique_ptr<Quackable> createQuackable(std::unique_ptr<Honkable> bird) override;
};

// ----------


} // end of namespace SimUDuck


#endif
