//
//  HarryPotter.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  Harry Potter Header file that extends the Character class

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Character.hpp"

class HarryPotter : public Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
    bool hogwarts; // Harry potter passive that gives +20 health
    
public:
    HarryPotter();
    
    virtual int attack();
    virtual int defend();
    virtual bool isDead();
    virtual void takeDamage(int);
    virtual int getArmor();
    virtual int getHealth();
    virtual int getType();
    virtual std::string getName();
};

#endif /* HarryPotter_hpp */
