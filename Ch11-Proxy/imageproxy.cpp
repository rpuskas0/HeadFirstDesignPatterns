#include "imageproxy.h"

namespace WebCoverViewer {


ImageProxy::ImageProxy(const QUrl& url, QLabel *widget, QObject* parent)
    : QObject(parent), imageFrame{widget}, imageURL{url} {}
    
int ImageProxy::getIconWidth() const
{
    if (!imageIcon.isNull()) {
        return imageIcon.width();
    } else {
        return 800;
    }
}

int ImageProxy::getIconHeight() const
{
    if (!imageIcon.isNull()) {
        return imageIcon.height();
    } else {
        return 600;
    }
}

void ImageProxy::paintIcon()
{
    if (!imageIcon.isNull()) {
        imageFrame->setPixmap(QPixmap::fromImage(imageIcon));
        imageFrame->repaint();
    } else {
        imageFrame->setText("Loading CD cover, please wait...");
        imageFrame->repaint();
        if (!retrieving) {
            retrieveImage();
        }
    }
}

void ImageProxy::loadImage()
{
    QImage tempImage;
    tempImage.loadFromData(downloader->downloadedData());
    imageIcon = tempImage;
    emit imageSet(imageIcon);
}

void ImageProxy::setImage()
{
    imageFrame->setPixmap(QPixmap::fromImage(imageIcon));
}

void ImageProxy::retrieveImage()
{
    retrieving = true;
    // QNetworkAccessManager actions are async by default, no need for separate thread
    downloader = new FileDownloader(imageURL);
    connect(downloader, SIGNAL(downloaded()), this, SLOT(loadImage()));
    connect(downloader, SIGNAL(downloaded()), downloader, SLOT(deleteLater()));
}


} // end of namespace WebCoverViewer
