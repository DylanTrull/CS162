//
//  Penguin.hpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Penguin class that inherits from Animal
//
#ifndef Penguin_hpp
#define Penguin_hpp

#include <stdio.h>
#include "Animal.hpp"

class Penguin : public Animal{
public:
    Penguin();
    Penguin(int age);
};
#endif /* Penguin_hpp */
