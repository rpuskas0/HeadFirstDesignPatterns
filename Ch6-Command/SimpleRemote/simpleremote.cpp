#include "simpleremote.h"


namespace RemoteControl {

    
void SimpleRemoteControl::setCommand(const std::shared_ptr<Command>& command)
{
    slot = command;
}

void SimpleRemoteControl::buttonWasPressed() const
{
    if (auto comm = slot.lock()) {
        comm->execute();
    }
}


} // end of namespace RemoteControl
