#ifndef INTERFACES_H
#define INTERFACES_H

#include <memory>

namespace DJApp {


class BeatObserver {
public:
    virtual void updateBeat() = 0;
    virtual ~BeatObserver() {}
};

// ----------

class BPMObserver {
public:
    virtual void updateBPM() = 0;
    virtual ~BPMObserver() {}
};

// ----------

class BeatModelInterface {
public:
    virtual void initialize() = 0;
    virtual void on() = 0;
    virtual void off() = 0;
    
    virtual void setBPM(int bpm) = 0;
    virtual int getBPM() = 0;
    
    virtual void registerObserver(const std::shared_ptr<BeatObserver>& obs) = 0;
    virtual void removeObserver(std::weak_ptr<BeatObserver> obs) = 0;
    
    virtual void registerObserver(const std::shared_ptr<BPMObserver>& obs) = 0;
    virtual void removeObserver(std::weak_ptr<BPMObserver> obs) = 0;

    virtual ~BeatModelInterface() {}
};

// ----------

class ControllerInterface {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void increaseBPM() = 0;
    virtual void decreaseBPM() = 0;
    virtual void setBPM(int bpm) = 0;
    virtual ~ControllerInterface() {}
};



} // end of namespace DJApp


#endif
