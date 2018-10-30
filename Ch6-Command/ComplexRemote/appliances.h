#ifndef APPLIANCES_H
#define APPLIANCES_H

#include <string>
#include <cstdint>

namespace RemoteControl {

    
class Light {
public:
    Light(const std::string& loc);
    
    std::string getLocation() const noexcept {return location;}
    void setLocation(const std::string& loc);
    
    void on() const;
    void off() const;
private:
    std::string location;
};

// ----------

class Stereo {
public:
    Stereo(const std::string& loc);    

    std::string getLocation() const noexcept {return location;}
    void setLocation(const std::string& loc);
    
    void on() const;
    void off() const;
    void setCD() const;
    void setDVD() const;
    void setRadio() const;
    void setVolume(int vol) const;
    
private:
    std::string location;
};

// ----------

class TV {
public:
    TV(const std::string& loc);
    
    std::string getLocation() const noexcept {return location;}
    void setLocation(const std::string& loc);
    void on() const;
    void off() const;
    
private:
    std::string location;
};

// ----------

class GarageDoor {
public:
    void up() const;
    void down() const;
    void stop() const;
    void lightOn() const;
    void lightOff() const;
};

// ----------

class CeilingFan {
public:
    CeilingFan(const std::string& loc);
    
    enum class FanSpeed : int8_t {off, low, medium, high};
    
    std::string getLocation() const noexcept {return location;}
    void setLocation(const std::string& loc);
    
    FanSpeed getSpeed() const noexcept {return currSpeed;}
    void setSpeed(FanSpeed fSpeed);
    
    void high();
    void medium();
    void low();
    void off();

private:    
    std::string location;
    FanSpeed currSpeed;
};


} // end of namespace RemoteControl


#endif
