//
//  Vampire.cpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
// Vampire class that creates the functions used from the character class

#include "Vampire.hpp"

Vampire::Vampire(){  // sets the defualt vlaues for the Vampire class
    this->health = 18;
    this->armor = 1;
    this->type = 1;
    this->name = "Vampire";
}

int Vampire::attack(){
    int roll = (rand() % 12 + 1); // random 1 sided die
    return roll;
}

int Vampire::defend(){
    int charm = rand() % 2;
    int roll = (rand() % 6 + 1);
    if(charm == 0){
        std::cout<<"The vampire used charm, no damage will be taken."<<std::endl;
        return 999; // if the vampire uses charm he cant be hurt
    }
    else{
        return roll;
    }
}

void Vampire::takeDamage(int damage){
    if(this->health - damage < 1){ // checks to see if the user has more then 0 health
        this->health = 0;
    }
    else{
        this->health -= damage;
    }
}

bool Vampire::isDead(){
    if(this->health < 1){ // bool to check if the character is dead
        return true;
    }
    return false;
}
//getters
int Vampire::getHealth(){
    return this->health;
}
int Vampire::getArmor(){
    return this->armor;
}
int Vampire::getType(){
    return this->type;
}
std::string Vampire::getName(){
    return this->name;
}
