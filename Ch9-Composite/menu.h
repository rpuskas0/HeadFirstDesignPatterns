#ifndef MENU_H
#define MENU_H

/*
 * This code contains Java style iterators implemented in C++, which do not represent true C++ style iterators.
 * I left the Java style to demonstrate that it is possible to create them with C++ as well, and also because
 * some C++ libraries (e.g. Qt) offer them in real world. People interested in C++ style iterators should refer to 
 * Josuttis'- The C++ Standard Library - A Tutorial and Reference (Chapter 9).
 */

#include <exception>
#include <memory>
#include <stack>
#include <string>
#include <utility>
#include <vector>

namespace Diner {


class MenuComponent {
public:
    virtual ~MenuComponent() {}
    
    virtual void add(const std::shared_ptr<MenuComponent>& menuComponent) {
        throw std::runtime_error("add() is not supported");
    }
    virtual void remove(const std::shared_ptr<MenuComponent>& menuComponent) {
        throw std::runtime_error("remove() is not supported");
    }
    virtual std::shared_ptr<MenuComponent> getChild(int i) const {
        throw std::runtime_error("getChild() is not supported");
    }
    
    virtual std::string getName() const {
        throw std::runtime_error("getName() is not supported");
    }
    virtual std::string getDescription() const {
        throw std::runtime_error("getDescription() is not supported");
    }
    virtual double getPrice() const {
        throw std::runtime_error("getPrice() is not supported");
    }
    virtual bool isVegetarian() const {
        throw std::runtime_error("isVegetarian() is not supported");
    }
    
    virtual void print() const {
        throw std::runtime_error("print() is not supported");
    }
};

// ----------

class MenuItem : public MenuComponent {
public:
    MenuItem(const std::string& nname, const std::string& ddescription,
            double pprice, bool vvegetarian);
    
    std::string getName() const override {return name;}
    std::string getDescription() const override {return description;}
    double getPrice() const override {return price;}
    bool isVegetarian() const override {return vegetarian;}
    
    void print() const override;
    
    class iterator;
    iterator begin();
    iterator end();
    
private:
    std::string name;
    std::string description;
    double price;
    bool vegetarian;
};

bool operator==(const MenuItem& mi1, const MenuItem& mi2);

// ----------

class Menu : public MenuComponent {
public:
    Menu(const std::string& nname, const std::string& ddescription);
    
    void add(const std::shared_ptr<MenuComponent>& menuComponent) override;
    
    void remove(const std::shared_ptr<MenuComponent>& menuComponent) override;
    
    std::shared_ptr<MenuComponent> getChild(int i) const override;
    std::string getName() const override {return name;}
    std::string getDescription() const override {return description;}
    
    void print() const override;
    
    using iterator = std::vector<std::shared_ptr<MenuComponent>>::iterator;
    
    iterator begin() {return menuComponents.begin();}
    iterator end() {return menuComponents.end();}

private:
    // Using shared_ptr in vector because we want to be able to add
    // both already and newly instantiated objects. See main.cpp.
    std::vector<std::shared_ptr<MenuComponent>> menuComponents;
    std::string name;
    std::string description;
};

bool operator==(const Menu& m1, const Menu& m2);


} // end of namespace Diner


#endif
