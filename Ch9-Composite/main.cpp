#include "waitress.h" 
#include "menu.h"
#include <utility>


using MenuComponent = Diner::MenuComponent;
using Menu = Diner::Menu;
using MenuItem = Diner::MenuItem;
using Waitress = Diner::Waitress;

int main() {
    
    std::shared_ptr<MenuComponent> pancakeHouseMenu = std::make_shared<Menu>("PANCAKE HOUSE MENU","Breakfast");
    std::shared_ptr<MenuComponent> dinerMenu = std::make_shared<Menu>("DINER MENU","Lunch");
    std::shared_ptr<MenuComponent> cafeMenu = std::make_shared<Menu>("CAFE MENU","Dinner");
    std::shared_ptr<MenuComponent> dessertMenu = std::make_shared<Menu>("DESSERT MENU","Dessert of course!");
    
    std::shared_ptr<MenuComponent> allMenus = std::make_shared<Menu>("ALL MENUS", "All menus combined");
    
    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);
    
    pancakeHouseMenu->add(std::make_shared<MenuItem>(
            "K&B's pancake breakfast",
            "Pancake with scrambled eggs, and toast",
            2.99,
            true));
    
    pancakeHouseMenu->add(std::make_shared<MenuItem>(
            "Waffles",
            "Waffles, with your choice of of blueberries or strawberries",
            3.59,
            true));
    
    
    dinerMenu->add(std::make_shared<MenuItem>(
            "BLT",
            "Bacon with lettuce & tomato on whole wheat",
            2.99,
            false));
        
    dinerMenu->add(std::make_shared<MenuItem>(
            "Pasta",
            "Spaghetti with Marinara Sauce, and a slice of sourdough bread",
            3.89,
            true));
    
    dinerMenu->add(dessertMenu);
    
    dessertMenu->add(std::make_shared<MenuItem>(
            "Apple pie",
            "Apple pie with a flakey crust, topped with vanilla icecream",
            1.59,
            true));
    
    dessertMenu->add(std::make_shared<MenuItem>(
            "Cheesecake",
            "Creamy New York cheesecake, with a chocolate graham crust",
            1.89,
            true));
    
    
    cafeMenu->add(std::make_shared<MenuItem>(
            "Soup of the day",
            "A cup of the soup of the day, with a side salad",
            3.69,
            false));
    
    cafeMenu->add(std::make_shared<MenuItem>(
            "Burrito",
            "A large burrito, with whole pinto beans, salsa, guacamole",
            2.99,
            false));
    
    
    
    Waitress waitress(allMenus);
    
    waitress.printMenu();
}
