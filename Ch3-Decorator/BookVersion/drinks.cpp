#include "drinks.h"

namespace Starbuzz {
    
double Espresso::cost() const noexcept
{
    switch (size) {
        case TALL:
            return 1.29;
        case GRANDE:
            return 1.99;
        case VENTI:
            return 2.69;
    }
}

double HouseBlend::cost() const noexcept
{
    switch (size) {
        case TALL:
            return 0.59;
        case GRANDE:
            return 0.89;
        case VENTI:
            return 1.19;
    }
}

double DarkRoast::cost() const noexcept
{
    switch (size) {
        case TALL:
            return 0.69;
        case GRANDE:
            return 0.99;
        case VENTI:
            return 1.29;
    }
}

double Decaf::cost() const noexcept
{
    switch (size) {
        case TALL:
            return 0.69;
        case GRANDE:
            return 1.05;
        case VENTI:
            return 1.39;
    }
}
    
} // end of namespace Starbuzz
