//
//  Barbarian.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
// Barbarian header file that extends the character class

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Character.hpp"

class Barbarian : public Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
public:
    Barbarian();
    
    virtual int attack();
    virtual int defend();
    virtual bool isDead();
    virtual void takeDamage(int);
    virtual int getArmor();
    virtual int getHealth();
    virtual int getType();
    virtual std::string getName();
};

#endif /* Barbarian_hpp */
