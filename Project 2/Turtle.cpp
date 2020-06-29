//
//  Turtle.cpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Turtle class that creates a turtle and a turtle of a certain age
//
#include "Turtle.hpp"

Turtle::Turtle() : Animal(){ // Default
    cost = 100;
    numBabies = 10;
    foodCost = 5;
    payoff = cost * .05;
    type = 3;
}
Turtle::Turtle(int a) : Animal(){
    cost = 100;
    numBabies = 10;
    foodCost = 5;
    payoff = cost * .05;
    type = 3;
    age = 0; // age gets overwritten by parent class
}

