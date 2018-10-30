#include "djview.h"
#include "beatmodel.h"
#include "controllers.h"
#include <QApplication>

using BeatController = DJApp::BeatController;
using BeatModel = DJApp::BeatModel;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BeatModel model;
    BeatController control(model);

    return a.exec();
}
