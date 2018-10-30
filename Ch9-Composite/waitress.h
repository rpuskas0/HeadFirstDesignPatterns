#ifndef WAITRESS_H
#define WAITRESS_H

#include "menu.h"
#include <memory>

namespace Diner {


class Waitress {
public:
    Waitress(const std::shared_ptr<MenuComponent>& aallMenus)
        : allMenus(aallMenus) {}
        
    void printMenu()
    {
        allMenus->print();
    }

private:
    std::shared_ptr<MenuComponent> allMenus;
};


} // end of namespace Diner


#endif
