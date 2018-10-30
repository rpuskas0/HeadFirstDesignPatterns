#ifndef SIMPLEREMOTE_H
#define SIMPLEREMOTE_H

#include "command.h"
#include <memory>

namespace RemoteControl {


class SimpleRemoteControl {
public:
    void setCommand(const std::shared_ptr<Command>& command);
    void buttonWasPressed() const;

private:
    std::weak_ptr<Command> slot;
};


} // end of namespace RemoteControl

#endif
