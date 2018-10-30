#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "ui_imageviewer.h"
#include <QMap>
#include <QString>
#include <QImage>
#include "imageproxy.h"

using ImageProxy = WebCoverViewer::ImageProxy;

class ImageViewer : public QMainWindow, private Ui::ImageViewer
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = 0);

private slots:
    void setIcon();
    void resetIcon(QImage image);

private:
    void setUpCDList(QMap<QString, QString>& map);
    void fillMenu(QMenu* menu, const QMap<QString, QString>& map);

    ImageProxy* imgProxy;
    QMap<QString, QString> cds;
};

#endif // IMAGEVIEWER_H
