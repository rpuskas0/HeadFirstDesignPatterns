#include "menus.h"
#include <utility>
#include <iostream>
#include <iterator>

namespace Diner {


MenuItem::MenuItem(const std::string& nname, const std::string& ddescription,
                    bool vvegetarian, double pprice)
    : name{nname}, description{ddescription}, vegetarian{vvegetarian}, price{pprice} {}

MenuItem::MenuItem()
    : name("Empty"), description(""), vegetarian(false), price(0) {}

// ----------

PancakeHouseMenu::PancakeHouseMenu()
{
    addItem("K&B's Pancake Breakfast",
            "Pancake with scrambled eggs, and toast",
            true,
            2.99);
    
    addItem("Regular Pancake Breakfast",
            "Pancakes with fried eggs, sausage",
            false,
            2.99);
    
    addItem("Blueberry Pancakes",
            "Pancakes made with fresh blueberries",
            true,
            3.49);
    
    addItem("Waffles",
            "Waffles, with your choice of blueberries or strawberries",
            true,
            3.59);
}

void PancakeHouseMenu::addItem(const std::string& nname, const std::string& ddescription,
                               bool vvegetarian, double pprice)
{
    menuItems.emplace_back(nname, ddescription, vvegetarian, pprice);
}

std::unique_ptr<Iterator> PancakeHouseMenu::createIterator() const
{
    auto phi = std::make_unique<PancakeHouseIterator>(menuItems);
    return phi;
}

// ----------

PancakeHouseIterator::PancakeHouseIterator(const std::vector<MenuItem>& iitems)
        : items(iitems) {}

bool PancakeHouseIterator::hasNext() const
{
    if (position >= items.size()) {
        return false;
    } else {
        return true;
    }
}

MenuItem PancakeHouseIterator::next()
{
    MenuItem menuItem = items.at(position);
    position++;
    
    return menuItem;
}

// ----------

DinerMenu::DinerMenu()
{    
    addItem("Vegetarian BLT",
            "(Fakin') Bacon with lettuce & tomato on whole wheat",
            true,
            2.99);
    
    addItem("BLT",
            "Bacon with lettuce &tomato on whole wheat",
            false,
            2.99);
    
    addItem("Soup of the day",
            "Soup of the day, with a side of potato salad",
            false,
            3.29);
    
    addItem("Hotdog",
            "A hot dog with sauerkraut, relish, onions, topped with cheese",
            false,
            3.05);
}

void DinerMenu::addItem(const std::string& nname, const std::string& ddescription,
                        bool vvegetarian, double pprice)
{
    MenuItem menuItem(nname, ddescription, vvegetarian, pprice);
    
    if (numberOfItems >= DINER_MAX_ITEMS) {
        std::cerr << "Sorry, menu is full! Can't add item to menu" << std::endl;
    } else {
        menuItems[numberOfItems] = std::move(menuItem);
        numberOfItems++;
    }
}

std::unique_ptr<Iterator> DinerMenu::createIterator() const
{
    auto dmi = std::make_unique<DinerMenuIterator>(menuItems);
    return dmi;
}

// ----------

bool DinerMenuIterator::hasNext() const
{
    if (position >= items.max_size() || items[position].getName() == "Empty") {
        return false;
    } else {
        return true;
    }
}

MenuItem DinerMenuIterator::next()
{
    MenuItem menuItem = items[position];
    position++;
    
    return menuItem;
}

// ----------

CafeMenu::CafeMenu()
{
    addItem("Veggie Burger and Air Fries",
            "Veggie Burger on a whole wheat bun, lettuce, tomato and fries",
            true,
            3.99);
    
    addItem("Soup of the day",
            "A cup of the soup of the day, with a side salad",
            false,
            3.69);
    
    addItem("Burrito",
            "A large burrito, with a whole pinto beans, salsa, guacamole",
            true,
            4.29);
}

void CafeMenu::addItem(const std::string& nname, const std::string& ddescription,
                        bool vvegetarian, double pprice)
{
    MenuItem tempItem(nname, ddescription, vvegetarian, pprice);
    menuItems.emplace(nname, std::move(tempItem));
}

std::unique_ptr<Iterator> CafeMenu::createIterator() const
{
    auto chi = std::make_unique<CafeMenuIterator>(menuItems);
    return chi;
}

// ----------

bool CafeMenuIterator::hasNext() const
{
    if (position >= items.size()) {
        return false;
    } else {
        return true;
    }
}

MenuItem CafeMenuIterator::next()
{   
    auto it = items.cbegin();
    std::advance(it, position);
    
    MenuItem menuItem = (*it).second;
    position++;
    
    return menuItem;
}


} // end of namespace Diner
