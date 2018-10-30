#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "interfaces.h"
#include "djview.h"
#include <memory>

namespace DJApp {


class BeatController : public ControllerInterface {
public:
    BeatController(BeatModelInterface& bmi);
    
    void start() override;
    void stop() override;
    void increaseBPM() override;
    void decreaseBPM() override;
    void setBPM(int bpm) override;

private:
    BeatModelInterface& model;
    std::shared_ptr<DJView> view;

};


} // end of namespace DJApp


#endif
