#include "factories.h"
#include "adapters.h"
#include "ducks.h"

namespace SimUDuck {


std::unique_ptr<Quackable> DuckFactory::createMallardDuck()
{
    auto instance = std::make_unique<MallardDuck>(MallardDuck());
    return instance;
}

std::unique_ptr<Quackable> DuckFactory::createRedheadDuck()
{
    auto instance = std::make_unique<RedheadDuck>(RedheadDuck());
    return instance;
}

std::unique_ptr<Quackable> DuckFactory::createDuckCall()
{
    auto instance = std::make_unique<DuckCall>(DuckCall());
    return instance;
}

std::unique_ptr<Quackable> DuckFactory::createRubberDuck()
{
    auto instance = std::make_unique<RubberDuck>(RubberDuck());
    return instance;
}

std::unique_ptr<Quackable> DuckFactory::createQuackable(std::unique_ptr<Honkable> bird)
{
    auto instance = std::make_unique<GooseAdapter>(std::move(bird));
    return instance;
}

// ----------

std::unique_ptr<Quackable> CountingDuckFactory::createMallardDuck()
{
    auto mallardDuck = std::make_unique<MallardDuck>();
    auto instance = std::unique_ptr<Quackable>{std::make_unique<QuackCounter>(std::move(mallardDuck))};
    return instance;
}

std::unique_ptr<Quackable> CountingDuckFactory::createRedheadDuck()
{
    auto redheadDuck = std::make_unique<RedheadDuck>();
    auto instance = std::unique_ptr<Quackable>{std::make_unique<QuackCounter>(std::move(redheadDuck))};
    return instance;
}

std::unique_ptr<Quackable> CountingDuckFactory::createDuckCall()
{
    auto duckCall = std::make_unique<DuckCall>();
    auto instance = std::unique_ptr<Quackable>{std::make_unique<QuackCounter>(std::move(duckCall))};
    return instance;
}

std::unique_ptr<Quackable> CountingDuckFactory::createRubberDuck()
{
    auto rubberDuck = std::make_unique<RubberDuck>();
    auto instance = std::unique_ptr<Quackable>{std::make_unique<QuackCounter>(std::move(rubberDuck))};
    return instance;
}

std::unique_ptr<Quackable> CountingDuckFactory::createQuackable(std::unique_ptr<Honkable> bird)
{   // not using QuackCounter, because non-ducks still don't quack
    auto instance = std::make_unique<GooseAdapter>(std::move(bird));
    return instance;
}


} // end of namespace SimUDuck
