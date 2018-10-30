#ifndef COMPLEXREMOTE_H
#define COMPLEXREMOTE_H

#include "command.h"
#include <vector>
#include <memory>
#include <stdint.h>

namespace RemoteControl {


class ComplexRemoteControl {
public:
    ComplexRemoteControl();
    
    void setCommand(int8_t slot,
                    const std::shared_ptr<Command>& onCommand,
                    const std::shared_ptr<Command>& offCommand);
    void onButtonWasPushed(int8_t slot);
    void offButtonWasPushed(int8_t slot);
    void undoButtonWasPushed() const;
    
    const std::vector<std::weak_ptr<Command>>& getOnCommands() const {return onCommands;}
    const std::vector<std::weak_ptr<Command>>& getOffCommands() const {return offCommands;}
    
private:
    static constexpr int8_t remoteSize = 7;
    static std::shared_ptr<Command> noCommand;
    std::weak_ptr<Command> undoCommand;
    std::vector<std::weak_ptr<Command>> onCommands;
    std::vector<std::weak_ptr<Command>> offCommands;
};


} // end of namespace RemoteControl


#endif
