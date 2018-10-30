/*
 * IMPORTANT:
 * This entire class is part of Qt's example package, and was taken from there
 * as is. You can find this example in it's entirety at the following address:
 * https://doc.qt.io/qt-5.11/qtmultimedia-multimedia-audiooutput-example.html
 */

#ifndef TONEGENERATOR_H
#define TONEGENERATOR_H

#include <QByteArray>
#include <QIODevice>
#include <QTimer>
#include <QtMultimedia/qaudioformat.h>

namespace QtExample {

constexpr auto pi = 3.14159265358979323846;

class ToneGenerator : public QIODevice
{
    Q_OBJECT

public:
    ToneGenerator(const QAudioFormat &format, qint64 durationUs, int sampleRate);

    void start();
    void stop();

    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;
    qint64 bytesAvailable() const override;

private:
    void generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate);

    qint64 m_pos = 0;
    QByteArray m_buffer;
};

} // end of namespace QtExample

#endif // TONEGENERATOR_H
