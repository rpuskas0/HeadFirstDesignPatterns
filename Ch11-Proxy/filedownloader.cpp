/*
 * IMPORTANT: This class is taken from Qt's wiki page as is, no modifications were made.
 * You can find it here: https://wiki.qt.io/Download_Data_from_URL
 */

#include "filedownloader.h"

FileDownloader::FileDownloader(const QUrl& Url, QObject *parent) :
 QObject(parent), imageUrl{Url}
{
    connect(
     &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
     this, SLOT (fileDownloaded(QNetworkReply*))
     );

    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader() { }

void FileDownloader::fileDownloaded(QNetworkReply* pReply) {
 m_DownloadedData = pReply->readAll();
 //emit a signal
 pReply->deleteLater();
 emit downloaded();
}

QByteArray FileDownloader::downloadedData() const {
    return m_DownloadedData;
}
