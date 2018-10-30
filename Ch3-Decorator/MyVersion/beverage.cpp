#include "beverage.h"

namespace Starbuzz {


Beverage::Beverage(const std::string& name, float pTall, float pGrande, float pVenti)
    : description{name}, priceTall{pTall}, priceGrande{pGrande}, priceVenti{pVenti} {}

Beverage::Beverage(float pTall, float pGrande, float pVenti)
    : priceTall{pTall}, priceGrande{pGrande}, priceVenti{pVenti} {}

float Beverage::cost() const noexcept
{
    switch (size) {
        case TALL:
            return priceTall;
        case GRANDE:
            return priceGrande;
        case VENTI:
            return priceVenti;
    }
}

std::string Beverage::getSizeName(Size s) const
{
    std::string sizeName;
    switch(s) {
        case TALL:
            sizeName = ", tall";
            break;
        case GRANDE:
            sizeName = ", grande";
            break;
        case VENTI:
            sizeName = ", venti";
            break;
    }
    
    return sizeName;
}

// ----------

std::string CondimentDecorator::getDescription() const
{
    return beverage->getDescription() + description;
}


float CondimentDecorator::cost() const noexcept
{
    switch (beverage->getSize()) {
        case TALL:
            return beverage->cost() + priceTall;
        case GRANDE:
            return beverage->cost() + priceGrande;
        case VENTI:
            return beverage->cost() + priceVenti;
    }
}

} // end of namespace Starbuzz
