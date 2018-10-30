#include "waitress.h"
#include "menus.h"
#include <utility>

int main() {
    
    auto pancakeHouseMenu = std::make_shared<Diner::PancakeHouseMenu>();
    auto dinerMenu = std::make_shared<Diner::DinerMenu>();
    auto cafeMenu = std::make_shared<Diner::CafeMenu>();
    
    std::vector<std::shared_ptr<Diner::Menu>> menuList {pancakeHouseMenu, dinerMenu, cafeMenu};
    
    Diner::Waitress waitress(menuList);
    
    waitress.printMenu();
    
}
