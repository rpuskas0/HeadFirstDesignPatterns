#include "appliances.h" 
#include <iostream>

namespace RemoteControl {


Light::Light(const std::string& loc)
    : location{loc} {}

void Light::setLocation(const std::string& loc)
{
    location = loc;
}

void Light::on() const
{
    std::cout << "The light is on." << std::endl;
}

void Light::off() const
{
    std::cout << "The light is off." << std::endl;
}

// ----------

Stereo::Stereo(const std::string& loc)
    : location{loc} {}

void Stereo::setLocation(const std::string& loc)
{
    location = loc;
}

void Stereo::on() const
{
    std::cout << "The stereo is on." << std::endl;
}

void Stereo::off() const
{
    std::cout << "The stereo is off." << std::endl;
}

void Stereo::setCD() const
{
    std::cout << "The stereo is set to CD." << std::endl;
}

void Stereo::setDVD() const
{
    std::cout << "The stereo is set to DVD." << std::endl;
}

void Stereo::setRadio() const
{
    std::cout << "The stereo is set to Radio." << std::endl;
}

void Stereo::setVolume(int vol) const
{
    std::cout << "The stereo volume is set to " << vol << "." << std::endl;
}

// ----------

TV::TV(const std::string& loc)
    : location{loc} {}

void TV::setLocation(const std::string& loc)
{
    location = loc;
}

void TV::on() const
{
    std::cout << "The TV is on." << std::endl;
}

void TV::off() const
{
    std::cout << "The TV is off." << std::endl;
}

// ----------

void GarageDoor::up() const
{
    std::cout << "Garage door is now open." << std::endl;
}

void GarageDoor::down() const
{
    std::cout << "Garage door is now closed." << std::endl;
}

void GarageDoor::stop() const
{
    std::cout << "Garage door movement is stopped." << std::endl;
}

void GarageDoor::lightOn() const
{
    std::cout << "Garage light is on." << std::endl;
}

void GarageDoor::lightOff() const
{
    std::cout << "Garage light is off." << std::endl;
}

// ----------

CeilingFan::CeilingFan(const std::string& loc)
    : location{loc}, currSpeed{CeilingFan::FanSpeed::off} {}

void CeilingFan::setLocation(const std::string& loc)
{
    location = loc;
}

void CeilingFan::setSpeed(FanSpeed fSpeed)
{
    currSpeed = fSpeed;
}

std::ostream& operator<<(std::ostream& os, const CeilingFan::FanSpeed& fSpeed)
{
    switch(fSpeed) {
        case CeilingFan::FanSpeed::off :
            os << "off";
            break;
        case CeilingFan::FanSpeed::low :
            os << "low";
            break;
        case CeilingFan::FanSpeed::medium :
            os << "medium";
            break;
        case CeilingFan::FanSpeed::high :
            os << "high";
            break;
        default:
            os << "unkown state";
    }
    
    return os;
}

void CeilingFan::high()
{
    setSpeed(CeilingFan::FanSpeed::high);
    std::cout << "Ceiling Fan is set to high." << std::endl;
}

void CeilingFan::medium()
{
    setSpeed(CeilingFan::FanSpeed::medium);
    std::cout << "Ceiling Fan is set to medium." << std::endl;
} 

void CeilingFan::low()
{
    setSpeed(CeilingFan::FanSpeed::low);
    std::cout << "Ceiling Fan is set to low." << std::endl;
}

void CeilingFan::off()
{
    setSpeed(CeilingFan::FanSpeed::off);
    std::cout << "Ceiling Fan is now off." << std::endl;
}


} // end of namespace RemoteControl
