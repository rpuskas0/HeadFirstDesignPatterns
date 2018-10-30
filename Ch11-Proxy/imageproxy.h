#ifndef IMAGEPROXY_H
#define IMAGEPROXY_H

#include "filedownloader.h"
#include <QImage>
#include <QUrl>
#include <QLabel>


namespace WebCoverViewer {


class ImageProxy : public QObject {
    Q_OBJECT
    
public:
    explicit ImageProxy(const QUrl& url, QLabel* widget, QObject* parent = 0);
    
    int getIconWidth() const;
    int getIconHeight() const;
    
    void paintIcon();

signals:
    void imageSet(QImage image);
    
private slots:
    void loadImage();
    void setImage();

private:
    void retrieveImage();

    FileDownloader* downloader;
    QLabel* imageFrame;
    QUrl imageURL;
    QImage imageIcon;
    bool retrieving = false;
};


} // end of namespace WebCoverViewer

#endif // IMAGEPROXY_H
