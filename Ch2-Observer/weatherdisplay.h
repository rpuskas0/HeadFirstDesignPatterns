/*
 * The implementation (and usage) of the constructors differs from the Java version due
 * to language mechanics concerning shared_ptr. The short story is: you cannot have a
 * shared_ptr to an object unless it is fully constructed first, hence the need for a
 * static create function.
 */


#ifndef WEATHERDISPLAY_H
#define WEATHERDISPLAY_H

#include "obsinterfaces.h"
#include <memory>

namespace WeatherStation {

    
// ----------
    
class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
    static std::shared_ptr<CurrentConditionsDisplay> create(const std::shared_ptr<Subject>& wdata);
    
    void update(float temp, float humid, float press) override;
    void display() const override;
    
private:
    CurrentConditionsDisplay(const std::shared_ptr<Subject>& wdata);
    
    float temperature;
    float humidity;
    std::weak_ptr<Subject> weatherdata;
};

// ----------

class StatisticsDisplay : public Observer, public DisplayElement {
public:
    static std::shared_ptr<StatisticsDisplay> create(const std::shared_ptr<Subject>& wdata);
    
    void update(float temp, float humid, float press) override;
    void display() const override;
    
private:
    StatisticsDisplay(const std::shared_ptr<Subject>& wdata);
    
    float maxTemp;
    float minTemp;
    float tempSum;
    int numReadings;
    std::weak_ptr<Subject> weatherdata;
};

// ----------

class ForecastDisplay : public Observer, public DisplayElement {
public:
    static std::shared_ptr<ForecastDisplay> create(const std::shared_ptr<Subject>& wdata);
    
    void update(float temp, float humid, float press) override;
    void display() const override;

private:
    ForecastDisplay(const std::shared_ptr<Subject>& wdata);
    
    float currentPressure;
    float lastPressure;
    std::weak_ptr<Subject> weatherdata;
};

// ----------

class HeatIndexDisplay : public Observer, public DisplayElement {
public:
    static std::shared_ptr<HeatIndexDisplay> create(const std::shared_ptr<Subject>& wdata);
    
    void update(float temp, float humid, float press) override;
    void display() const override;
    
    float computeHeatIndex(float t, float rh) const;
    
private:
    HeatIndexDisplay(const std::shared_ptr<Subject>& wdata);
    
    float heatIndex;
    std::weak_ptr<Subject> weatherdata;
};

} // end of namespace WeatherStation



#endif
