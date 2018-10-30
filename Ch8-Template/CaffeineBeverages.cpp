#include "CaffeineBeverages.h" 
#include <iostream>
#include <cctype>

namespace Beverages {


void CaffeineBeverage::prepareRecipe() const
{
    boilWater();
    brew();
    pourInCup();
    if (customerWantsCondiments()) {
        addCondiments();
    }
}

void CaffeineBeverage::boilWater() const
{
    std::cout << "Boiling water..." << std::endl;
}

void CaffeineBeverage::pourInCup() const
{
    std::cout << "Pouring into cup." << std::endl;
}

bool CaffeineBeverage::customerWantsCondiments() const
{
    return true;
}

// ----------

void Tea::brew() const
{
    std::cout << "Steeping the tea." << std::endl;
}

void Tea::addCondiments() const
{
    std::cout << "Adding lemon." << std::endl;
}

// ----------

void Coffee::brew() const
{
    std::cout << "Dripping coffee through filter." << std::endl;
}

void Coffee::addCondiments() const
{
    std::cout << "Adding sugar and milk." << std::endl;
}

bool Coffee::customerWantsCondiments() const
{
    std::string answer = getUserInput();
    
    if ( std::tolower(answer[0]) == 'y' ) {
        return true;
    } else {
        return false;
    }
}

std::string Coffee::getUserInput() const
{
    std::string answer = "";
    
    std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
    
    std::cin >> answer;
    if (!std::cin) {
        if (std::cin.bad()) {
            std::cerr << "IO error trying to read your answer" << std::endl;
        }
    }
    
    if (answer == "") {
        return "no";
    }
    
    return answer;
}


} // end of namespace Beverages
