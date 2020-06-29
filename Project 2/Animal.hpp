//
//  Animal.hpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//
// Animal Header class

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
class Animal{
protected:
    int age;
    int cost;
    int numBabies;
    int foodCost;
    int payoff;
    int type;
    
public:
    Animal();
    Animal(int age);
    int getType();
    void ageADay();
    int getAge();
    int getCost();
    int getFoodCost();
    int getPayoff();
    int getNumBabies();
};
#endif /* Animal_hpp */
