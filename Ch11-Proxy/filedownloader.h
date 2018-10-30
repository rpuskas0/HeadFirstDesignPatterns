/*
 * IMPORTANT: This class is taken from Qt's wiki page as is, no modifications were made.
 * You can find it here: https://wiki.qt.io/Download_Data_from_URL
 */

#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class FileDownloader : public QObject
{
 Q_OBJECT
 public:
  FileDownloader() {}
  explicit FileDownloader(const QUrl& Url, QObject *parent = 0);
  virtual ~FileDownloader();
  QByteArray downloadedData() const;

 signals:
  void downloaded();

 private slots:
  void fileDownloaded(QNetworkReply* pReply);

 private:
  QUrl imageUrl;
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
};

#endif // FILEDOWNLOADER_H
