#include "command.h" 
#include "complexremote.h"
#include <memory>
#include <utility>
#include <vector>
#include <iostream>

using namespace RemoteControl;

int main() {
    
    ComplexRemoteControl remoteControl;
    
    // creating appliances
    auto livingRoomLight = std::make_shared<Light>("Living Room");
    auto kitchenLight = std::make_shared<Light>("Kitchen");
    auto ceilingFan = std::make_shared<CeilingFan>("Living Room");
    auto garageDoor = std::make_shared<GarageDoor>();
    auto stereo = std::make_shared<Stereo>("Living Room");
    auto tv = std::make_shared<TV>("Living Room");
    
    // creating commands for the corresponding appliances
    auto livingRoomLightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff = std::make_shared<LightOffCommand>(livingRoomLight);
    auto kitchenLightOn = std::make_shared<LightOnCommand>(kitchenLight);
    auto kitchenLightOff = std::make_shared<LightOffCommand>(kitchenLight);
    
    auto ceilingFanOn = std::make_shared<CeilingFanHighCommand>(ceilingFan);
    auto ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);
    
    auto garageDoorUp = std::make_shared<GarageDoorOpenCommand>(garageDoor);
    auto garageDoorDown = std::make_shared<GarageDoorCloseCommand>(garageDoor);
    
    auto stereoOnWithCD = std::make_shared<StereoOnWithCDCommand>(stereo);
    auto stereoOff = std::make_shared<StereoOffWithCDCommand>(stereo);
    
    auto tvOn = std::make_shared<TVOnCommand>(tv);
    auto tvOff = std::make_shared<TVOffCommand>(tv);
    
    // generating macros
    std::vector<std::weak_ptr<Command>> partyOn {livingRoomLightOn, stereoOnWithCD, tvOn};
    std::vector<std::weak_ptr<Command>> partyOff {livingRoomLightOff, stereoOff, tvOff};
    auto partyOnMacro = std::make_shared<MacroCommand>(partyOn);
    auto partyOffMacro = std::make_shared<MacroCommand>(partyOff);
    
    // setting up remote control
    remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl.setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl.setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl.setCommand(3, stereoOnWithCD, stereoOff);
    remoteControl.setCommand(4, partyOnMacro, partyOffMacro);
    
    // simulating remote control usage
    remoteControl.onButtonWasPushed(0);
    remoteControl.offButtonWasPushed(0);
    remoteControl.onButtonWasPushed(1);
    remoteControl.offButtonWasPushed(1);
    remoteControl.onButtonWasPushed(2);
    remoteControl.offButtonWasPushed(2);
    remoteControl.onButtonWasPushed(3);
    remoteControl.offButtonWasPushed(3);

    std::cout << "\nParty begins!! :)\n" << std::endl;
    
    remoteControl.onButtonWasPushed(4);
    std::cout << "\nParty ends :(\n" << std::endl;
    remoteControl.offButtonWasPushed(4);
    
    // test NoCommand
    remoteControl.onButtonWasPushed(5);
    
    return 0;
}
