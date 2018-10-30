#include "beverage.h"

namespace Starbuzz {


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

} // end of namespace Starbuzz
