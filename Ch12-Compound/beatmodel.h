#ifndef BEATMODEL_H
#define BEATMODEL_H

#include "interfaces.h"
#include "tonegenerator.h"
#include <memory>
#include <vector>
#include <QTimer>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioOutput>

namespace DJApp {


class BeatModel : public QObject, public BeatModelInterface
{
    Q_OBJECT
public:
    BeatModel();

    void initialize() override;
    void on() override;
    void off() override;

    void setBPM(int bpm) override;
    int getBPM() override;

    void beatEvent();
    void setUpAudio(const QAudioDeviceInfo& deviceInfo);

    void registerObserver(const std::shared_ptr<BeatObserver>& obs) override;
    void removeObserver(std::weak_ptr<BeatObserver> obs) override;
    void notifyBeatObservers();

    void registerObserver(const std::shared_ptr<BPMObserver>& obs) override;
    void removeObserver(std::weak_ptr<BPMObserver> obs) override;
    void notifyBPMObservers();

    const QTimer* getTimer(){return timer;}

public slots:
    void updateBeat();

private:
    int currBpm;
    int timeoutMs;
    QTimer* timer;
    std::unique_ptr<QtExample::ToneGenerator> sequencer;
    std::unique_ptr<QAudioOutput> audioOutput;
    std::vector<std::weak_ptr<BeatObserver>> beatObservers;
    std::vector<std::weak_ptr<BPMObserver>> bpmObservers;
};

} // end of namespace DJApp

#endif // BEATMODEL_H
