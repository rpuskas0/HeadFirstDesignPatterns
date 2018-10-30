#ifndef INTERFACES_H
#define INTERFACES_H


namespace Birds {


class Duck {
public:
    virtual ~Duck() {}
    
    virtual void quack() const = 0;
    virtual void fly() const = 0;
};

// ----------

class Turkey {
public:
    virtual ~Turkey() {}
    
    virtual void gobble() const = 0;
    virtual void fly() const = 0;
};


} // end of namespace Birds

#endif
