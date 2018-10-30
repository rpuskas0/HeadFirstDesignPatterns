/*
 * IMPORTANT:
 * The 'setUpAudio' function, parts of the BeatModel constructor and possibly
 * other parts are taken from Qt's examples with only slight modifications.
 * You can find the original code in it's entirety at the following address:
 * https://doc.qt.io/qt-5.11/qtmultimedia-multimedia-audiooutput-example.html
 */

#include "beatmodel.h"
#include <chrono>
#include <QDebug>
#include <QMessageBox>
#include <QtMultimedia/QAudioFormat>

namespace DJApp {


BeatModel::BeatModel()
    : currBpm(60), timer(new QTimer(this))
{
    initialize();
    auto io = audioOutput->start();
    connect(timer, &QTimer::timeout, [this, io]() {
        if (audioOutput->state() == QAudio::StoppedState)
            return;

        QByteArray buffer(32768, 0);
        int chunks = audioOutput->bytesFree() / audioOutput->periodSize();
        while (chunks) {
            const qint64 len = sequencer->read(buffer.data(), audioOutput->periodSize());
            if (len)
                io->write(buffer.data(), len);
            if (len != audioOutput->periodSize())
                break;
            --chunks;
        }
    });
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBeat()));
}

void BeatModel::initialize()
{
    setUpAudio(QAudioDeviceInfo::defaultOutputDevice());
}

void BeatModel::on()
{
    if (currBpm > 1) {
        timer->start(60000/currBpm);
        notifyBPMObservers();
    }
}

void BeatModel::off()
{
    timer->stop();
    int tempBpm = currBpm;
    currBpm = 0;
    notifyBPMObservers();
    currBpm = tempBpm;
}

void BeatModel::setBPM(int bpm)
{
    currBpm = bpm;
    // Negative BPM does not make sense, 0 will cause FPE because of DIVZERO
    if (bpm > 0 && timer->isActive()) {
        // NOTE: why call getBPM() here, just use currBpm!
        // NOTE: if the the second operator is integer the first value will be
        //       truncated to ingeger. So 60/<NUM>60) will be 0.X, which when
        //       cast to integer is 0. Then will it only be mutliplied with
        //       1000 which is also 0, so zero timeout is a continuous beep.
        //auto timeoutMs{(60/currBpm) * 1000}
        // Solution 1: avoid mutliplying at run time and just divide 60k ms by BPM
        //auto timeoutMs{(60000/currBpm)};
        // Soltution 2: make sure all vaulues are double so there is no implicit
        //              casting of values during evaluation.
        // auto timeoutMs{(60.0L / (double)currBpm) * 1000.0L};
        timer->setInterval(60000/currBpm);
        notifyBPMObservers();
    }
}

int BeatModel::getBPM()
{
    return currBpm;
}

void BeatModel::setUpAudio(const QAudioDeviceInfo& deviceInfo)
{
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    if (!deviceInfo.isFormatSupported(format)) {
        qWarning() << "Default format not supported - trying to use nearest";
        format = deviceInfo.nearestFormat(format);
    }

    constexpr int durationMilliSeconds = 50;
    constexpr int toneSampleRateHz = 600;
    sequencer = std::make_unique<QtExample::ToneGenerator>(format, durationMilliSeconds * 1000, toneSampleRateHz);
    audioOutput = std::make_unique<QAudioOutput>(deviceInfo, format);
    sequencer->start();
}

void BeatModel::registerObserver(const std::shared_ptr<BeatObserver>& obs)
{
    beatObservers.emplace_back(obs);
}

void BeatModel::removeObserver(std::weak_ptr<BeatObserver> obs)
{

}

void BeatModel::notifyBeatObservers()
{
    for (auto obs : beatObservers) {
        if (auto inst = obs.lock()) {
                inst->updateBeat();
            }
    }
}

void BeatModel::registerObserver(const std::shared_ptr<BPMObserver>& obs)
{
    bpmObservers.emplace_back(obs);
}

void BeatModel::removeObserver(std::weak_ptr<BPMObserver> obs)
{

}

void BeatModel::notifyBPMObservers()
{
    for (auto obs : bpmObservers) {
        if (auto inst = obs.lock()) {
            inst->updateBPM();
        }
    }
}

void BeatModel::updateBeat()
{
    notifyBeatObservers();
}


} // end of namespace DJApp
