#include "waitress.h"
#include <iostream>

namespace Diner {

void Waitress::printMenu()
{
    std::cout << "MENU\n----" << std::endl;
    int typeNum = 1;
    for (auto menu : menus) {
        std::cout << "\nTYPE " << typeNum << std::endl;
        printMenu(menu->createIterator());
        typeNum++;
    }
}

void Waitress::printMenu(const std::unique_ptr<Iterator>& it)
{
    while (it->hasNext()) {
        MenuItem menuItem = it->next();
        std::cout << menuItem.getName() << ", "
                  << menuItem.getPrice() << " -- "
                  << menuItem.getDescription()
                  << std::endl;
    }
}


} // end of namespace Diner
