//
//  Medusa.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
// Medusa header file that extends the Character class functions

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Character.hpp"

class Medusa : public Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
    
public:
    Medusa();
    
    virtual int attack();
    virtual int defend();
    virtual bool isDead();
    virtual void takeDamage(int);
    virtual int getArmor();
    virtual int getHealth();
    virtual int getType();
    virtual std::string getName();
};

#endif /* Medusa_hpp */
