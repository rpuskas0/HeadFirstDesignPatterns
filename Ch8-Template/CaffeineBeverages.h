#ifndef CAFFEINEBEVERAGES_H
#define CAFFEINEBEVERAGES_H

#include <string>

namespace Beverages {


class CaffeineBeverage {
public:
    virtual ~CaffeineBeverage() {}
    
    virtual void prepareRecipe() const final;
    
protected:
    void boilWater() const;
    virtual void brew() const = 0;
    void pourInCup() const;
    virtual void addCondiments() const = 0;
    virtual bool customerWantsCondiments() const;    
};

// ----------

class Tea : public CaffeineBeverage {
public:
    void brew() const override;
    void addCondiments() const override;
};

// ----------

class Coffee : public CaffeineBeverage {
public:
    void brew() const override;
    void addCondiments() const override;
    bool customerWantsCondiments() const override;
    
private:
    std::string getUserInput() const;
};


} // end of namespace Beverages

#endif
