#ifndef GEESE_H
#define GEESE_H

#include "interfaces.h" 
#include <iostream>
#include <string>

namespace SimUDuck {


class Goose : public Honkable {
public:
    void honk() override;
    
private:
    std::string print() const override;
};


} // end of namespace SimUDuck

#endif
