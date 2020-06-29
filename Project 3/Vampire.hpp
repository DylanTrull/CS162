//
//  Vampire.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  Vampire header file that pulls all neeeded resources from Character

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Character.hpp"

class Vampire : public Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
public:
    Vampire();
    virtual int attack();
    virtual int defend();
    virtual bool isDead();
    virtual void takeDamage(int);
    virtual int getArmor();
    virtual int getHealth();
    virtual int getType();
    virtual std::string getName();
};


#endif /* Vampire_hpp */
