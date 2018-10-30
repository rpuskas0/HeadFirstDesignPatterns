#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>
#include <memory>

namespace Starbuzz {

class Beverage {
public:
    Beverage()
        : description("Unknown Beverage"), size(GRANDE) {}
    virtual ~Beverage() {}
        
    virtual double cost() const noexcept = 0;
    virtual std::string getDescription() const
    {
        return description + getSizeName(size);
    }
    
    enum Size : short {TALL, GRANDE, VENTI};
    
    Size getSize() const noexcept {return size;}
    void setSize(Size s) {size = s;}

protected:  
    std::string description;
    Size size;
    
private:
    std::string getSizeName(Size s) const;
};


class CondimentDecorator : public Beverage {
public:
    virtual std::string getDescription() const = 0;
    
protected:
    std::unique_ptr<Beverage> beverage;
};

} // end of namespace Starbuzz


#endif
