//
//  Tiger.cpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Tiger class that sets the default values for the tiger animal
//

#include "Tiger.hpp"


Tiger::Tiger() : Animal(){
    cost = 10000;
    foodCost = 50;
    payoff = cost * .2;
    type = 1;
}

Tiger::Tiger(int a) : Animal(){
    cost = 10000;
    foodCost = 50;
    payoff = cost * .2;
    type = 1;
    age = 0;
}
