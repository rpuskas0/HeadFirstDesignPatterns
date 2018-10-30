#include "djview.h"
#include <QString>


namespace DJApp {


DJView::DJView(ControllerInterface& contr, BeatModelInterface& beatmod)
    : controller(contr), model(beatmod)
{
    viewUi = new QDialog(this);
    controlUi = new QMainWindow(this);
    barTimer = new QTimer(this);
    barTimer->setSingleShot(true);

    vui.setupUi(viewUi);
    vui.bpmOutputLabel->setText("Offline");
    cui.setupUi(controlUi);

    connect(cui.actionExit, SIGNAL(triggered()), this, SLOT(on_actionExit_triggered()));
    connect(cui.actionStart, SIGNAL(triggered()), this, SLOT(on_actionStart_triggered()));
    connect(cui.actionStop, SIGNAL(triggered()), this, SLOT(on_actionStop_triggered()));
    connect(cui.setBpmButton, SIGNAL(clicked()), this, SLOT(on_setBpmButton_clicked()));
    connect(cui.increaseBpmButton, SIGNAL(clicked()), this, SLOT(on_increaseBpmButton_clicked()));
    connect(cui.decreaseBpmButton, SIGNAL(clicked()), this, SLOT(on_decreaseBpmButton_clicked()));
    connect(barTimer, SIGNAL(timeout()), vui.beatBar, SLOT(reset()));

    viewUi->show();
    controlUi->show();
}

std::shared_ptr<DJView> DJView::create(ControllerInterface &contr, BeatModelInterface &beatmod)
{
    std::shared_ptr<DJView> instance{new DJView(contr, beatmod)};

    instance->model.registerObserver((std::shared_ptr<BeatObserver>)instance);
    instance->model.registerObserver((std::shared_ptr<BPMObserver>)instance);

    return instance;
}

void DJView::enableStopMenuItem()
{
    cui.actionStop->setEnabled(true);
}

void DJView::disableStopMenuItem()
{
    cui.actionStop->setEnabled(false);
}

void DJView::enableStartMenuItem()
{
    cui.actionStart->setEnabled(true);
}

void DJView::disableStartMenuItem()
{
    cui.actionStart->setEnabled(false);
}

void DJView::updateBPM()
{
    int bpm = model.getBPM();

    if (bpm == 0) {
        vui.bpmOutputLabel->setText("Offline");
    } else {
        vui.bpmOutputLabel->setText(QString::number(bpm));
    }
}

void DJView::updateBeat()
{
    vui.beatBar->setValue(100);
    barTimer->start(100);
}

void DJView::on_actionExit_triggered()
{
    DJView::close();
}

void DJView::on_actionStart_triggered()
{
    controller.start();
}

void DJView::on_actionStop_triggered()
{
    controller.stop();
}

void DJView::on_setBpmButton_clicked()
{
    int bpm = cui.bpmLineEdit->text().toInt();
    controller.setBPM(bpm);
}

void DJView::on_increaseBpmButton_clicked()
{
    controller.increaseBPM();
}

void DJView::on_decreaseBpmButton_clicked()
{
    controller.decreaseBPM();
}


} // end of namespace DJApp
