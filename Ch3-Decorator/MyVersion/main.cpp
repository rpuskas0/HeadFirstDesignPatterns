#include "drinks.h" 
#include "condiments.h"
#include <memory>
#include <utility>
#include <iostream>


using Beverage = Starbuzz::Beverage;
using Espresso = Starbuzz::Espresso;
using DarkRoast = Starbuzz::DarkRoast;
using HouseBlend = Starbuzz::HouseBlend;
using Soy = Starbuzz::Soy;
using Mocha = Starbuzz::Mocha;
using Whip = Starbuzz::Whip;


int main() {
    std::unique_ptr<Beverage> beverage = std::make_unique<Espresso>();
    std::cout << beverage->getDescription()
                << " $" << beverage->cost() << std::endl;
                
    
    std::unique_ptr<Beverage> beverage2 = std::make_unique<DarkRoast>();
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));
    beverage2 = std::make_unique<Whip>(std::move(beverage2));
    std::cout << beverage2->getDescription()
                << " $" << beverage2->cost() << std::endl;
                
    
    std::unique_ptr<Beverage> beverage3 = std::make_unique<HouseBlend>();
    beverage3 = std::make_unique<Soy>(std::move(beverage3));
    beverage3 = std::make_unique<Mocha>(std::move(beverage3));
    beverage3 = std::make_unique<Whip>(std::move(beverage3));
    std::cout << beverage3->getDescription()
                << " $" << beverage3->cost() << std::endl;
                
    std::unique_ptr<Beverage> beverage4 = std::make_unique<Espresso>();
    beverage4->setSize(Starbuzz::Beverage::VENTI);
    std::cout << beverage4->getDescription()
                << " $" << beverage4->cost() << std::endl;
                
    std::unique_ptr<Beverage> beverage5 = std::make_unique<HouseBlend>();
    beverage5->setSize(Starbuzz::Beverage::VENTI);
    beverage5 = std::make_unique<Soy>(std::move(beverage5));
    std::cout << beverage5->getDescription()
                << " $" << beverage5->cost() << std::endl;
                
    std::unique_ptr<Beverage> beverage6 = std::make_unique<HouseBlend>();
    beverage6->setSize(Starbuzz::Beverage::TALL);
    beverage6 = std::make_unique<Soy>(std::move(beverage6));
    std::cout << beverage6->getDescription()
                << " $" << beverage6->cost() << std::endl;
                
    return 0;
}
