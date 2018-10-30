#include "beatcontrol.h"

BeatControl::BeatControl(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    bpmLineEdit->setInputMask("Ddd");
}
