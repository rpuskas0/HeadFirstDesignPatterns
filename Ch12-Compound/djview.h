#ifndef DJVIEW_H
#define DJVIEW_H

#include "interfaces.h"
#include "ui_beatview.h"
#include "ui_beatcontrol.h"
#include <memory>
#include <QTimer>

namespace DJApp {


class DJView : public QWidget, public BeatObserver, public BPMObserver
{
    Q_OBJECT

public:
    DJView() = delete;
    static std::shared_ptr<DJView> create(ControllerInterface& contr, BeatModelInterface& beatmod);

    void enableStopMenuItem();
    void disableStopMenuItem();
    void enableStartMenuItem();
    void disableStartMenuItem();

    void updateBPM() override;
    void updateBeat() override;

private slots:
    void on_actionExit_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void on_setBpmButton_clicked();
    void on_increaseBpmButton_clicked();
    void on_decreaseBpmButton_clicked();

private:
    DJView(ControllerInterface& contr, BeatModelInterface& beatmod);
    ControllerInterface& controller;
    BeatModelInterface& model;

    QDialog* viewUi;
    QMainWindow* controlUi;
    QTimer* barTimer;
    Ui::BeatView vui;
    Ui::BeatControl cui;
};


} // end of namespace DJApp

#endif // DJVIEW_H
