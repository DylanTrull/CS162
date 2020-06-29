//
//  Animal.cpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//
// Animal parent class that defaults needed variables
#include "Animal.hpp"


Animal::Animal(){ // default constructor for adult animals
    numBabies = 1;
    age = 1;
    foodCost = 10;
    payoff = 0;
    cost = 0;
    type = 4; // Defualt Animal class
}
Animal::Animal(int a){ // Parent class for settting
    age = a;
}

int Animal::getType(){ //Parent class function that returns the type of animal.
    return type;
}
void Animal::ageADay(){ //Parent class function that increases the age + 1
    age++;
}
int Animal::getAge(){ //Parent class function to return age of animal
    return age;
}

int Animal::getCost(){ //Parent class function to return cost
    return cost;
}

int Animal::getPayoff(){ // Parent class function to return payoff
    return payoff;
}

int Animal::getFoodCost(){ // Parent class function that returns the foodCost of the Animal
    return foodCost;
}

int Animal::getNumBabies(){ // Parent class function that returns the number of babies the animal can have
    return numBabies;
}
