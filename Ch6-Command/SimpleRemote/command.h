#ifndef COMMAND_H
#define COMMAND_H

#include "appliances.h"
#include <memory>
#include <vector>

namespace RemoteControl {


class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() const = 0;
};

// ----------

class NoCommand : public Command {
public:
    void execute() override {}
    void undo() const override {}
};

// ----------

class MacroCommand : public Command {
public:
    MacroCommand(const std::vector<std::weak_ptr<Command>>& comm);
    
    void addCommand(const std::shared_ptr<Command>& comm);
    void execute() override;
    void undo() const override {}
    
private:
    std::vector<std::weak_ptr<Command>> commands;
};

// ----------

class LightOnCommand : public Command {
public:
    LightOnCommand(const std::shared_ptr<Light>& llight);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<Light> light;
};

// ----------

class LightOffCommand : public Command {
public:
    LightOffCommand(const std::shared_ptr<Light>& llight);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<Light> light;
};

// ----------

class StereoOnWithCDCommand : public Command {
public:
    StereoOnWithCDCommand(const std::shared_ptr<Stereo>& sstereo);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<Stereo> stereo;
};

class StereoOffWithCDCommand : public Command {
public:
    StereoOffWithCDCommand(const std::shared_ptr<Stereo>& sstereo);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<Stereo> stereo;
};

// ----------

class TVOnCommand : public Command {
public:
    TVOnCommand(const std::shared_ptr<TV>& ttv);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<TV> tv;
};

class TVOffCommand : public Command {
public:
    TVOffCommand(const std::shared_ptr<TV>& ttv);
    
    void execute() override;
    void undo() const override;
    
private:
    std::weak_ptr<TV> tv;
};

// ----------

class GarageDoorOpenCommand : public Command {
public:
    GarageDoorOpenCommand(const std::shared_ptr<GarageDoor>& gDoor);
    
    void execute() override;
    void undo() const override;

private:
    std::weak_ptr<GarageDoor> garageDoor;
};

class GarageDoorCloseCommand : public Command {
public:
    GarageDoorCloseCommand(const std::shared_ptr<GarageDoor>& gDoor);
    
    void execute() override;
    void undo() const override;

private:
    std::weak_ptr<GarageDoor> garageDoor;
};

// ----------

class CeilingFanHighCommand : public Command {
public:
    CeilingFanHighCommand(const std::shared_ptr<CeilingFan>& cFan);
    
    void execute() override;
    void undo() const override;

private:
    std::weak_ptr<CeilingFan> ceilingFan;
    CeilingFan::FanSpeed prevSpeed;
};

class CeilingFanOffCommand : public Command {
public:
    CeilingFanOffCommand(const std::shared_ptr<CeilingFan>& cFan);
    
    void execute() override;
    void undo() const override;

private:
    std::weak_ptr<CeilingFan> ceilingFan;
    CeilingFan::FanSpeed prevSpeed;
};


} // end of namespace RemoteControl

#endif
