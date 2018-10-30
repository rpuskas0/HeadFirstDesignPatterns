#ifndef OBSINTERFACES_H
#define OBSINTERFACES_H

#include <memory>

namespace WeatherStation {


class Observer;


class Subject {
public:
    virtual ~Subject() {}
    
    virtual void registerObserver(const std::shared_ptr<Observer>& obs) = 0;
    virtual void removeObserver(const std::shared_ptr<Observer>& obs) = 0;
    virtual void notifyObservers() = 0;
};
    

class Observer {
public:
    virtual ~Observer() {}
    
    virtual void update(float temp, float humid, float press) = 0;
};


class DisplayElement {
public:
    virtual ~DisplayElement() {}
    
    virtual void display() const = 0;
};


} // end of namespace WeatherStation

#endif
