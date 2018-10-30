#ifndef CHOCOBOILER_H
#define CHOCOBOILER_H

#include <memory>
#include <mutex>

namespace Choco {

    
class ChocolateBoiler {
public:
    static std::unique_ptr<ChocolateBoiler>& getInstance();
    ChocolateBoiler(const ChocolateBoiler&) = delete;
    ChocolateBoiler& operator=(const ChocolateBoiler&) = delete;
    
    void fill();
    void drain();
    void boil();
    
    bool isEmpty() const noexcept
        {return empty;}
    
    bool isBoiled() const noexcept
        {return boiled;}

private:
    ChocolateBoiler()
        : empty(true), boiled(false) {}
    
    static std::mutex instMutex;
    static std::unique_ptr<ChocolateBoiler> uniqueInstance;
    
    bool empty;
    bool boiled;
};


} // end of namespace Choco

#endif
