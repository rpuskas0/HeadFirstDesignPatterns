#include "duck.h"

void duck_actions(auto& duck) {
    duck->display();
    duck->swim();
    duck->performQuack();
    duck->performFly();        
}

int main() {
    auto mallard_duck = std::make_unique<MallardDuck>();
    duck_actions(mallard_duck);
    
    auto model_duck = std::make_unique<ModelDuck>();
    duck_actions(model_duck);
    model_duck->setFlyBehavior(std::make_unique<FlyRocketPowered>());
    model_duck->performFly();
    
    return 0;
}
