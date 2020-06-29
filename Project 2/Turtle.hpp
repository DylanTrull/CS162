//
//  Turtle.hpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  simple turtle header class that inherits from Animal so it doesn't require many functions
//

#ifndef Turtle_hpp
#define Turtle_hpp

#include <stdio.h>
#include "Animal.hpp"

class Turtle : public Animal{
public:
    Turtle(); // default 1 year old
    Turtle(int age); // set age of new animal
};
#endif /* Turtle_hpp */
