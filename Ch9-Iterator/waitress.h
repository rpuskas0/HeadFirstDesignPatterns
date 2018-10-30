#ifndef WAITRESS_H
#define WAITRESS_H

#include "menus.h"
#include <memory>
#include <vector>

namespace Diner {


class Waitress {
public:
    Waitress(const std::vector<std::shared_ptr<Menu>>& mmenus)
        : menus(mmenus) {}
    
    void printMenu();
    void printMenu(const std::unique_ptr<Iterator>& it);

private:
    const std::vector<std::shared_ptr<Menu>>& menus;
};


} // end of namespace Diner

#endif
