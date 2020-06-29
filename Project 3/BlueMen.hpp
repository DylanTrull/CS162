//
//  BlueMen.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  Blue Men header file that extends the character class

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Character.hpp"

class BlueMen : public Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
public:
    BlueMen();
    
    virtual int attack();
    virtual int defend();
    virtual bool isDead();
    virtual void takeDamage(int);
    virtual int getArmor();
    virtual int getHealth();
    virtual int getType();
    virtual std::string getName();
};

#endif /* BlueMen_hpp */
