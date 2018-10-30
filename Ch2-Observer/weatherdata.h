#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "obsinterfaces.h"
#include <memory>
#include <vector>

namespace WeatherStation {


class WeatherData : public Subject {
public:
    WeatherData();
    
    WeatherData(const WeatherData&) = delete;
    WeatherData& operator=(const WeatherData&) = delete;
    WeatherData(WeatherData&&) = default;
    WeatherData& operator=(WeatherData&&) = default;
    
    void registerObserver(const std::shared_ptr<Observer>& obs) override;
    void removeObserver(const std::shared_ptr<Observer>& obs) override;
    void notifyObservers() override;
    
    void measurementsChanged();
    
    void setMeasurements(float temp, float humid, float press);

private:
    float temperature;
    float humidity;
    float pressure;
    std::vector<std::weak_ptr<Observer>> observers;
};

} // end of namespace WeatherStation

#endif
