#include "weatherdata.h"
#include <utility>
#include <algorithm>
#include <iterator>


namespace WeatherStation {

WeatherData::WeatherData()
    : temperature{0.0}, humidity{0.0}, pressure{0.0}
{}
    
void WeatherData::registerObserver(const std::shared_ptr<Observer>& obs)
{
    observers.emplace_back(obs);
}

void WeatherData::removeObserver(const std::shared_ptr<Observer>& obs)
{
    auto it = std::find_if(std::cbegin(observers), std::cend(observers), 
        [&obs](const auto& wptr){return wptr.lock() == obs;});

    if (it != std::cend(observers)) {
        observers.erase(it);
    }
}

void WeatherData::notifyObservers()
{   
    for (auto weak : observers) {
        if (auto obs = weak.lock()) {
            obs->update(temperature, humidity, pressure);
        }
    }
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(float temp, float humid, float press)
{
    temperature = temp;
    humidity = humid;
    pressure = press;
    
    measurementsChanged();
}

} // end of namespace WeatherStation
