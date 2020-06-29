//
//  Penguin.cpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Penguin class that creates a penguin and penguin of a certain age
//

#include "Penguin.hpp"

Penguin::Penguin() : Animal(){
    cost = 1000;
    numBabies = 5;
    payoff = cost * .1;
    type = 2;
}
Penguin::Penguin(int a): Animal(){
    cost = 1000;
    numBabies = 5;
    payoff = cost * .1;
    type = 2;
    age = 0;
}
