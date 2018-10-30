#include "imageviewer.h"


ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    ImageLabel->setBackgroundRole(QPalette::Base);
    ImageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setBackgroundRole(QPalette::Dark);

    setUpCDList(cds);
    fillMenu(menuFavCD, cds);
}

void ImageViewer::setIcon()
{
    QObject* obj= sender();
    QAction* action = qobject_cast<QAction*>(obj);
    QString actionName = action->text();
    actionName.remove(0,1);  // needed to remove '&' character from beginning of string

    imgProxy = new ImageProxy{cds.value(actionName), ImageLabel};
    connect(imgProxy, SIGNAL(imageSet(QImage)), this, SLOT(resetIcon(QImage)));
    connect(imgProxy, SIGNAL(imageSet(QImage)), imgProxy, SLOT(deleteLater()));
    imgProxy->paintIcon();
}

void ImageViewer::resetIcon(QImage image)
{
    ImageLabel->setPixmap(QPixmap::fromImage(image));
}

void ImageViewer::setUpCDList(QMap<QString, QString>& map)
{
    map.insert("Ambient: Music for Airports", "http://images.amazon.com/images/P/B000003S2K.01.LZZZZZZZ.jpg");
    map.insert("Buddha Bar", "http://images.amazon.com/images/P/B00009XBYK.01.LZZZZZZZ.jpg");
    map.insert("Ima", "http://images.amazon.com/images/P/B000005IRM.01.LZZZZZZZ.jpg");
    map.insert("Karma", "http://images.amazon.com/images/P/B000005DCB.01.LZZZZZZZ.gif");
    map.insert("MCMXC A.D.", "http://images.amazon.com/images/P/B000002URV.01.LZZZZZZZ.jpg");
    map.insert("Northern Exposure", "http://images.amazon.com/images/P/B000003SFN.01.LZZZZZZZ.jpg");
    map.insert("Selected Ambient Works, Vol. 2", "http://images.amazon.com/images/P/B000002MNZ.01.LZZZZZZZ.jpg");
}

void ImageViewer::fillMenu(QMenu* menu, const QMap<QString, QString> &map)
{
    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        QAction* action = new QAction(it.key(), this);
        menu->addAction(action);
        connect(action, SIGNAL(triggered()), this, SLOT(setIcon()));
    }
}
