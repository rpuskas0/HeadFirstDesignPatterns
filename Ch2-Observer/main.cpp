#include "weatherdata.h"
#include "weatherdisplay.h"
#include <memory>
#include <utility>
#include <iostream>

using WeatherData = WeatherStation::WeatherData;
using Observer = WeatherStation::Observer;
using CurrCondDisp = WeatherStation::CurrentConditionsDisplay;
using StatDisp = WeatherStation::StatisticsDisplay;
using ForecastDisp = WeatherStation::ForecastDisplay;
using HeatIndDisp = WeatherStation::HeatIndexDisplay;

int main() {
    auto weatherdata = std::make_shared<WeatherData>();
    
    std::shared_ptr<Observer> currentdisplay = CurrCondDisp::create(weatherdata);
    std::shared_ptr<Observer> statisticsdisplay = StatDisp::create(weatherdata);
    std::shared_ptr<Observer> forecastdisplay = ForecastDisp::create(weatherdata);
    std::shared_ptr<Observer> heatindexdisplay = HeatIndDisp::create(weatherdata);
    
    weatherdata->setMeasurements(80, 65, 30.4);
    weatherdata->setMeasurements(82, 70, 29.2);
    weatherdata->setMeasurements(78, 90, 29.2);
    
    weatherdata->removeObserver(heatindexdisplay);
    weatherdata->setMeasurements(80, 80, 29.4);
    
    weatherdata->registerObserver(heatindexdisplay);
    weatherdata->setMeasurements(75, 62, 27.4);
    
    heatindexdisplay.reset();
    weatherdata->setMeasurements(74, 64, 28.1);

    return 0;
}
