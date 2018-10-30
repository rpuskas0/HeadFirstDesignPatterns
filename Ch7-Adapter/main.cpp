#include "ducks.h"
#include "turkeys.h"
#include "adapters.h"
#include <iostream>


using MallardDuck = Birds::MallardDuck;
using WildTurkey = Birds::WildTurkey;
using Duck = Birds::Duck;
using TurkeyAdapter = Birds::TurkeyAdapter;
using DuckAdapter = Birds::DuckAdapter;

void testDuck(const Duck& duck)
{
    duck.quack();
    duck.fly();
}

int main()
{
    MallardDuck duck;
    WildTurkey turkey;
    
    // Duck test drive
    TurkeyAdapter turkeyAdapter(turkey);
    
    std::cout << "The turkey says..." << std::endl;
    turkey.gobble();
    turkey.fly();
    
    std::cout << "The duck says..." << std::endl;
    testDuck(duck);
    
    std::cout << "The TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);
    
    std::cout << std::endl;
    
    // Turkey test drive
    DuckAdapter duckAdapter(duck);
    
    for (int i = 0; i < 5; i++) {
        std::cout << "The DuckAdapter says...";
        duckAdapter.gobble();
        duckAdapter.fly();
    }
    
    return 0;
}
