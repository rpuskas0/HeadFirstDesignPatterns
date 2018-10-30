#ifndef BEATVIEW_H
#define BEATVIEW_H

#include "ui_beatview.h"

class BeatView : public QDialog, private Ui::BeatView
{
    Q_OBJECT

public:
    explicit BeatView(QWidget *parent = nullptr);
};

#endif // BEATVIEW_H
