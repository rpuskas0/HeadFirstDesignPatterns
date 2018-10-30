#ifndef BEATCONTROL_H
#define BEATCONTROL_H

#include "ui_beatcontrol.h"

class BeatControl : public QMainWindow, private Ui::BeatControl
{
    Q_OBJECT

public:
    explicit BeatControl(QWidget *parent = nullptr);

};

#endif // BEATCONTROL_H
