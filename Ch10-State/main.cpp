#include "gumball.h" 

using GumballMachine = MightyGumball::GumballMachine;

int main() {
    
    auto gumballMachine = GumballMachine::create(4);
    
    std::cout << *gumballMachine << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    
    std::cout << *gumballMachine << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    
    std::cout << *gumballMachine << std::endl;
}
