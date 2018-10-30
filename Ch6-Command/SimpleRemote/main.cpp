#include "command.h"
#include "appliances.h"
#include "simpleremote.h"

using namespace RemoteControl;

int main() {
    
    SimpleRemoteControl remote;
    auto light = std::make_shared<Light>("Living Room");
    auto garageDoor = std::make_shared<GarageDoor>();
    
    auto lightOn = std::make_shared<LightOnCommand>(light);
    auto garageOpen = std::make_shared<GarageDoorOpenCommand>(garageDoor);
    
    remote.setCommand(lightOn);
    remote.buttonWasPressed();
    remote.setCommand(garageOpen);
    remote.buttonWasPressed();
}
