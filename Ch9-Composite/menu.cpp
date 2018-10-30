#include "menu.h"
#include <iostream>
#include <algorithm>
#include <utility>

namespace Diner {


MenuItem::MenuItem(const std::string& nname, const std::string& ddescription,
                    double pprice, bool vvegetarian)
    : name{nname}, description{ddescription}, price{pprice}, vegetarian{vvegetarian} {}

void MenuItem::print() const
{
    std::cout << " " << getName();
    if (isVegetarian()) {
        std::cout << "(v)";
    }
    std::cout << ", " << getPrice() << "\n   -- "
              << getDescription() << std::endl;
}

class MenuItem::iterator {
public:
    iterator(MenuItem* mmenuItem)
        : menuItem(mmenuItem) {}
    iterator(const iterator& it) {menuItem = it.menuItem;}
    
    iterator& operator=(const iterator& it) {menuItem = it.menuItem; return *this;}
    
    iterator& operator++() {menuItem = nullptr; return *this;}
    iterator operator++(int) {auto ret = *this; ++(*this); return ret;}
        
    MenuItem& operator*() {return *menuItem;}
    
    bool operator==(const iterator& b) const {return menuItem == b.menuItem;}
    bool operator!=(const iterator& b) const {return menuItem != b.menuItem;}
    
private:
    MenuItem* menuItem;
};

MenuItem::iterator MenuItem::begin()
{
    MenuItem::iterator it(this);
    return it;
}

MenuItem::iterator MenuItem::end()
{
    MenuItem::iterator it(nullptr);
    return it;
}

bool operator==(const MenuItem& mi1, const MenuItem& mi2)
{
    if (mi1.getName() == mi2.getName() &&
        mi1.getDescription() == mi2.getDescription() &&
        mi1.getPrice() == mi2.getPrice() &&
        mi1.isVegetarian() == mi2.isVegetarian())
    {
        return true;    
    } else {
        return false;
    }
}

// ----------

Menu::Menu(const std::string& nname, const std::string& ddescription)
        : name{nname}, description{ddescription} {}

void Menu::add(const std::shared_ptr<MenuComponent>& menuComponent)
{
    menuComponents.emplace_back(menuComponent);
}
    
void Menu::remove(const std::shared_ptr<MenuComponent>& menuComponent)
{
    auto it = std::find(menuComponents.begin(), menuComponents.end(), menuComponent);
    menuComponents.erase(it);
}

std::shared_ptr<MenuComponent> Menu::getChild(int i) const
{
    return menuComponents.at(i);
}

void Menu::print() const
{
    std::cout << "\n" << getName()
              << ", " << getDescription()
              << "\n--------------------" << std::endl;
    
    for (auto menuComp : menuComponents) {
            menuComp->print();
    }
}

bool operator==(const Menu& m1, const Menu& m2)
{
    if (m1.getName() == m2.getName() &&
        m1.getDescription() == m2.getDescription())
    {
        return true;
    } else {
        return false;
    }
}


} // end of namespace Diner
