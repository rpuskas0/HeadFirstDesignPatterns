#include "command.h"
#include <utility>

namespace RemoteControl {

    
MacroCommand::MacroCommand(const std::vector<std::weak_ptr<Command>>& comm)
        : commands{comm} {}

void MacroCommand::addCommand(const std::shared_ptr<Command>& comm)
{
    commands.emplace_back(comm);
}

void MacroCommand::execute()
{
    for (auto weak : commands) {
        if (auto comm = weak.lock()) {
            comm->execute();
        }
    }
}

// ----------
    
LightOnCommand::LightOnCommand(const std::shared_ptr<Light>& llight)
    : light{llight} {}

void LightOnCommand::execute()
{
    if (auto appl = light.lock()) {
        appl->on();
    }
}

void LightOnCommand::undo() const
{
    if (auto appl = light.lock()) {
        appl->off();
    }
}

// ----------

LightOffCommand::LightOffCommand(const std::shared_ptr<Light>& llight)
    : light{llight} {}

void LightOffCommand::execute()
{
    if (auto appl = light.lock()) {
        appl->off();
    }
}

void LightOffCommand::undo() const
{
    if (auto appl = light.lock()) {
        appl->on();
    }
}

// ----------

StereoOnWithCDCommand::StereoOnWithCDCommand(const std::shared_ptr<Stereo>& sstereo)
    : stereo{sstereo} {}

void StereoOnWithCDCommand::execute()
{
    if (auto appl = stereo.lock()) {
        appl->on();
        appl->setCD();
        appl->setVolume(11);
    }
}

void StereoOnWithCDCommand::undo() const
{
    if (auto appl = stereo.lock()) {
        appl->off();
    }
}

StereoOffWithCDCommand::StereoOffWithCDCommand(const std::shared_ptr<Stereo>& sstereo)
    : stereo{sstereo} {}

void StereoOffWithCDCommand::execute()
{
    if (auto appl = stereo.lock()) {
        appl->off();
    }
}

void StereoOffWithCDCommand::undo() const
{
    if (auto appl = stereo.lock()) {
        appl->on();
        appl->setCD();
        appl->setVolume(11);
    }
}

// ----------

TVOnCommand::TVOnCommand(const std::shared_ptr<TV>& ttv)
    : tv{ttv} {}
    
void TVOnCommand::execute()
{
    if (auto appl = tv.lock()) {
        appl->on();
    }
}

void TVOnCommand::undo() const
{
    if (auto appl = tv.lock()) {
        appl->off();
    }
}

TVOffCommand::TVOffCommand(const std::shared_ptr<TV>& ttv)
    : tv{ttv} {}
    
void TVOffCommand::execute()
{
    if (auto appl = tv.lock()) {
        appl->off();
    }
}

void TVOffCommand::undo() const
{
    if (auto appl = tv.lock()) {
        appl->on();
    }
}

// ----------

GarageDoorOpenCommand::GarageDoorOpenCommand(const std::shared_ptr<GarageDoor>& gDoor)
    : garageDoor{gDoor} {}

void GarageDoorOpenCommand::execute()
{
    if (auto appl = garageDoor.lock()) {
        appl->up();
    }
}

void GarageDoorOpenCommand::undo() const
{
    if (auto appl = garageDoor.lock()) {
        appl->down();
    }
}

GarageDoorCloseCommand::GarageDoorCloseCommand(const std::shared_ptr<GarageDoor>& gDoor)
    : garageDoor{gDoor} {}

void GarageDoorCloseCommand::execute()
{
    if (auto appl = garageDoor.lock()) {
        appl->down();
    }
}

void GarageDoorCloseCommand::undo() const
{
    if (auto appl = garageDoor.lock()) {
        appl->up();
    }
}

// ----------

CeilingFanHighCommand::CeilingFanHighCommand(const std::shared_ptr<CeilingFan>& cFan)
    : ceilingFan{cFan} {}
    
void CeilingFanHighCommand::execute()
{
    if (auto appl = ceilingFan.lock()) {
        prevSpeed = appl->getSpeed();
        appl->high();
    }
}

void CeilingFanHighCommand::undo() const
{
    if (auto appl = ceilingFan.lock()) {
        if (prevSpeed == CeilingFan::FanSpeed::high) {
            appl->high();
        } else if (prevSpeed == CeilingFan::FanSpeed::medium) {
            appl->medium();
        } else if (prevSpeed == CeilingFan::FanSpeed::low) {
            appl->low();
        } else if (prevSpeed == CeilingFan::FanSpeed::off) {
            appl->off();
        }
    }
}

CeilingFanOffCommand::CeilingFanOffCommand(const std::shared_ptr<CeilingFan>& cFan)
    : ceilingFan{cFan} {}
    
void CeilingFanOffCommand::execute()
{
    if (auto appl = ceilingFan.lock()) {
        prevSpeed = appl->getSpeed();
        appl->off();
    }
}

void CeilingFanOffCommand::undo() const
{
    if (auto appl = ceilingFan.lock()) {
        if (prevSpeed == CeilingFan::FanSpeed::high) {
            appl->high();
        } else if (prevSpeed == CeilingFan::FanSpeed::medium) {
            appl->medium();
        } else if (prevSpeed == CeilingFan::FanSpeed::low) {
            appl->low();
        } else if (prevSpeed == CeilingFan::FanSpeed::off) {
            appl->off();
        }
    }
}


} // end of namespace RemoteControl
