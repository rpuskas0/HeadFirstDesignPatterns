#include "controllers.h"

namespace DJApp {

BeatController::BeatController(BeatModelInterface &bmi)
    : model(bmi)
{
    view = DJView::create(*this, bmi);
    view->disableStopMenuItem();
    view->enableStartMenuItem();
}

void BeatController::start()
{
    model.on();
    view->disableStartMenuItem();
    view->enableStopMenuItem();
}

void BeatController::stop()
{
    model.off();
    view->disableStopMenuItem();
    view->enableStartMenuItem();
}

void BeatController::increaseBPM()
{
    int bpm = model.getBPM();
    // NOTE: need to use prefix operator to actually pass an incremented value
    //       to the function!
    model.setBPM(++bpm);
}

void BeatController::decreaseBPM()
{
    int bpm = model.getBPM();
    // NOTE: need to use prefix operator to actually pass a decreased value to
    //       the function.
    model.setBPM(--bpm);
}

void BeatController::setBPM(int bpm)
{
    model.setBPM(bpm);
}


} // end of namespace DJApp
