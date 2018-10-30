#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>
#include <memory>

namespace Starbuzz {

    
class Beverage {
public:
    Beverage() = delete;
    
    virtual ~Beverage() {}
        
    virtual float cost() const noexcept;
    virtual std::string getDescription() const
    {
        return description + getSizeName(size);
    }
    
    enum Size : short {TALL, GRANDE, VENTI};
    
    Size getSize() const noexcept {return size;}
    void setSize(Size s) {size = s;}

protected:
    Beverage(float pTall, float pGrande, float pVenti);
    Beverage(const std::string& name, float pTall, float pGrande, float pVenti);
    Size size {GRANDE};
    float priceTall {0.0};
    float priceGrande {0.0};
    float priceVenti {0.0};
    std::string description;
    
private:
    std::string getSizeName(Size s) const;
};


class CondimentDecorator : public Beverage {
public:
    CondimentDecorator() = delete;
    
    virtual std::string getDescription() const override;
    float cost() const noexcept override;
    
protected:
    CondimentDecorator(std::unique_ptr<Beverage> bev, float pTall, float pGrande, float pVenti)
        : Beverage(pTall, pGrande, pVenti), beverage{std::move(bev)} {}
    std::unique_ptr<Beverage> beverage;
};

} // end of namespace Starbuzz


#endif
