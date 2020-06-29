//
//  Character.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
// Character abstract class that is used to create all the different characters

#ifndef Character_hpp
#define Character_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

class Character{
private:
    int health;
    int armor;
    int type;
    std::string name;
    
public:
    Character();
    virtual ~Character(); //virtual deconstructor that will be availabe for all the characters
    
    virtual int attack() = 0;
    virtual int defend() = 0;
    virtual bool isDead() = 0;
    virtual void takeDamage(int) = 0; // setting them all to 0;
    virtual int getArmor() = 0;
    virtual int getHealth() = 0;
    virtual int getType() = 0;
    virtual std::string getName() = 0;
    
    
};

#endif /* Character_hpp */
