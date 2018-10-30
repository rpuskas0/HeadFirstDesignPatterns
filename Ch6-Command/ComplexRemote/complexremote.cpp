#include "complexremote.h" 
#include <utility>
#include <typeinfo>
#include <iostream>

namespace RemoteControl {


std::shared_ptr<Command> ComplexRemoteControl::noCommand = std::make_shared<NoCommand>();

ComplexRemoteControl::ComplexRemoteControl()
{
    onCommands = std::vector<std::weak_ptr<Command>>(remoteSize, noCommand);
    offCommands = std::vector<std::weak_ptr<Command>>(remoteSize, noCommand);
    undoCommand = noCommand; 
}

void ComplexRemoteControl::setCommand(int8_t slot,
                                      const std::shared_ptr<Command>& onCommand,
                                      const std::shared_ptr<Command>& offCommand)
{
    onCommands.at(slot) = onCommand;
    offCommands.at(slot) = offCommand;
}

void ComplexRemoteControl::onButtonWasPushed(int8_t slot)
{
    if (auto onComm = onCommands.at(slot).lock()) {
        onComm->execute();
        undoCommand = onComm;
    }
}

void ComplexRemoteControl::offButtonWasPushed(int8_t slot)
{
    if (auto offComm = offCommands.at(slot).lock()) {
        offComm->execute();
        undoCommand = offComm;
    }
}

void ComplexRemoteControl::undoButtonWasPushed() const
{
    if (auto undoComm = undoCommand.lock()) {
        undoComm->undo();
    }
}


} // end of namespace RemoteControl
