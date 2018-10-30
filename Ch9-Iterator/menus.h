#ifndef MENUS_H
#define MENUS_H

/*
 * This code contains Java style iterators implemented in C++, which do not represent true C++ style iterators.
 * I left the Java style to demonstrate that it is possible to create them with C++ as well, and also because
 * some C++ libraries (e.g. Qt) offer them in real world. People interested in C++ style iterators should refer to 
 * Josuttis'- The C++ Standard Library - A Tutorial and Reference (Chapter 9).
 */

#include <string>
#include <vector>
#include <array>
#include <memory>
#include <unordered_map>

namespace Diner {

    
class MenuItem {
public:
    MenuItem(const std::string& nname, const std::string& ddescription,
             bool vvegetarian, double pprice);
    MenuItem();
    
    virtual std::string getName() const {return name;}
    virtual std::string getDescription() const {return description;}
    virtual double getPrice() const {return price;}
    virtual bool isVegetarian() const {return vegetarian;}
    
private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};

// ----------

class Iterator {
public:
    virtual ~Iterator () {}
    
    virtual bool hasNext() const = 0;
    virtual MenuItem next() = 0;
};

// ----------

class Menu {
public:
    virtual ~Menu() {}
    
    virtual std::unique_ptr<Iterator> createIterator() const = 0;
};

// ----------

class PancakeHouseMenu : public Menu {
public:
    PancakeHouseMenu();
    
    void addItem(const std::string& nname, const std::string& ddescription,
                 bool vvegetarian, double pprice);
    std::unique_ptr<Iterator> createIterator() const override;
    
private:
    std::vector<MenuItem> menuItems;
};

// ----------

class PancakeHouseIterator : public Iterator {
public:
    PancakeHouseIterator(const std::vector<MenuItem>& iitems);
    
    bool hasNext() const override;
    MenuItem next() override;
    
private:
    const std::vector<MenuItem>& items;
    int position = 0;
};

// ----------

constexpr int DINER_MAX_ITEMS = 6;

class DinerMenu : public Menu {
public:
    DinerMenu();
    
    void addItem(const std::string& nname, const std::string& ddescription,
                 bool vvegetarian, double pprice);
    std::unique_ptr<Iterator> createIterator() const override;
    
private:
    int numberOfItems = 0;
    std::array<MenuItem, DINER_MAX_ITEMS> menuItems;
};

// ----------

class DinerMenuIterator : public Iterator {
public:
    DinerMenuIterator(const std::array<MenuItem, DINER_MAX_ITEMS>& iitems)
        : items(iitems) {}
        
    bool hasNext() const override;
    MenuItem next() override;

private:
    const std::array<MenuItem, DINER_MAX_ITEMS>& items;
    int position = 0;
};

// ----------

class CafeMenu : public Menu {
public:
    CafeMenu();
    
    void addItem(const std::string& nname, const std::string& ddescription,
                 bool vvegetarian, double pprice);
    std::unique_ptr<Iterator> createIterator() const override;

private:
    std::unordered_map<std::string, MenuItem> menuItems;
};

// ----------

class CafeMenuIterator : public Iterator {
public:
    CafeMenuIterator(const std::unordered_map<std::string, MenuItem>& iitems)
        : items(iitems) {}
    
    bool hasNext() const override;
    MenuItem next() override;
    
private:
    const std::unordered_map<std::string, MenuItem>& items;
    int position = 0;
};

} // end of namespace Diner

#endif
