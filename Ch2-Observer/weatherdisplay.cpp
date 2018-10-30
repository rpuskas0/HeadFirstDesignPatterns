#include "weatherdisplay.h"
#include <utility>
#include <iostream>

namespace WeatherStation {
   
   
// ----------

CurrentConditionsDisplay::CurrentConditionsDisplay(const std::shared_ptr<Subject>& wdata)
    : temperature{0.0}, humidity{0.0}, weatherdata{wdata}
{
}

std::shared_ptr<CurrentConditionsDisplay> CurrentConditionsDisplay::create(const std::shared_ptr<Subject>& wdata)
{
    std::shared_ptr<CurrentConditionsDisplay> instance(new CurrentConditionsDisplay(wdata));
    if (auto wdataptr = instance->weatherdata.lock()) {
        wdataptr->registerObserver(instance);
    }
    
    return instance;
}

void CurrentConditionsDisplay::update(float temp, float humid, float press)
{
    temperature = temp;
    humidity = humid;
    
    display();
}

void CurrentConditionsDisplay::display() const
{
    std::cout << "Current conditions: "
                << temperature << "C degrees and "
                << humidity << "% humidity\n";
}

// ----------

StatisticsDisplay::StatisticsDisplay(const std::shared_ptr<Subject>& wdata)
    : maxTemp{0.0}, minTemp{0.0}, tempSum{0.0}, numReadings{0}, weatherdata{wdata}
{   
}

std::shared_ptr<StatisticsDisplay> StatisticsDisplay::create(const std::shared_ptr<Subject>& wdata)
{
    std::shared_ptr<StatisticsDisplay> instance(new StatisticsDisplay(wdata));
    if (auto wdataptr = instance->weatherdata.lock()) {
        wdataptr->registerObserver(instance);
    }
    
    return instance;
}

void StatisticsDisplay::update(float temp, float humid, float press)
{
    numReadings++;
    tempSum += temp;
    
    if (temp >= maxTemp) maxTemp = temp;
    if (temp <= minTemp) minTemp = temp;
    
    display();
}

void StatisticsDisplay::display() const
{
    std::cout << "Avg/Max/Min temperature = "
                << (tempSum / numReadings) << "/"
                << maxTemp << "/"
                << minTemp << "\n";
}

// ----------

ForecastDisplay::ForecastDisplay(const std::shared_ptr<Subject>& wdata)
    : currentPressure{29.92}, lastPressure{0.0}, weatherdata{wdata}
{
}

std::shared_ptr<ForecastDisplay> ForecastDisplay::create(const std::shared_ptr<Subject>& wdata)
{
    std::shared_ptr<ForecastDisplay> instance(new ForecastDisplay(wdata));
    if (auto wdataptr = instance->weatherdata.lock()) {
        wdataptr->registerObserver(instance);
    }
    
    return instance;
}

void ForecastDisplay::update(float temp, float humid, float press)
{
    lastPressure = currentPressure;
    currentPressure = press;
    
    display();
}

void ForecastDisplay::display() const
{
    std::cout << "Forecast: ";
        if (currentPressure > lastPressure) {
            std::cout << "Improving weather on the way!\n";
        }
        if (currentPressure == lastPressure) {
            std::cout << "More of the same\n";
        }
        if (currentPressure < lastPressure) {
            std::cout << "Watch out for cooler, rainy weather\n";
        }
}

// ----------

HeatIndexDisplay::HeatIndexDisplay(const std::shared_ptr<Subject>& wdata)
    : heatIndex{0.0}, weatherdata(wdata)
{
}

std::shared_ptr<HeatIndexDisplay> HeatIndexDisplay::create(const std::shared_ptr<Subject>& wdata)
{
    std::shared_ptr<HeatIndexDisplay> instance(new HeatIndexDisplay(wdata));
    if (auto wdataptr = instance->weatherdata.lock()) {
        wdataptr->registerObserver(instance);
    }
    
    return instance;
}

void HeatIndexDisplay::update(float temp, float humid, float press)
{
    heatIndex = computeHeatIndex(temp, humid);
    
    display();
}

float HeatIndexDisplay::computeHeatIndex(float t, float rh) const
{
    float index = ((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) 
            + (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) 
            + (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
            (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 * 
            (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) + 
            (0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
            0.000000000843296 * (t * t * rh * rh * rh)) -
            (0.0000000000481975 * (t * t * t * rh * rh * rh)));
    
    return index;
}

void HeatIndexDisplay::display() const
{
    std::cout << "Heat index is " << heatIndex << "\n";
}
// ----------

} // end of namespace WeatherStation
