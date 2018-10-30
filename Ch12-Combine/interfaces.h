#ifndef INTERFACES_H
#define INTERFACES_H

#include <memory>
#include <string>

namespace SimUDuck {


class Observer;

class QuackObservable {
public:
    virtual ~QuackObservable() {}
    
    virtual void registerObserver(const std::shared_ptr<Observer>& obs) = 0;
    virtual void notifyObservers() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const QuackObservable& quacky);
    
private:
    virtual std::string print() const {}
};

// ----------

class Observer {
public:
    virtual ~Observer() {}
    
    virtual void update(QuackObservable& duck) const = 0;
};

// ----------

class Quackable : public QuackObservable {
public:
    virtual void quack() = 0;
};

// ----------

class Honkable {
public:
    virtual ~Honkable() {}
    
    virtual void honk() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Honkable& honky);
    
private:
    virtual std::string print() const = 0;
};


} // end of namespace SimUDuck


#endif
 
