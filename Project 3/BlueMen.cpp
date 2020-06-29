//
//  BlueMen.cpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  Blue Men class that creates all the functio ns from the Character class

#include "BlueMen.hpp"

BlueMen::BlueMen(){ // defualt configuration for the Blue Men
    this->health = 12;
    this->armor = 3;
    this->type = 3;
    this->name = "Blue Men";
}

int BlueMen::attack(){ // attack with 2 10 sided die
    int die1 = (rand() % 10 + 1);
    int die2 = (rand() % 10 + 1);
    return die1 + die2;
}

int BlueMen::defend(){ // for every loss of 4 health lose one die
    int die1;
    int die2;
    int die3;
    
    if(this->health <= 12 && this->health > 8){
        die1 = (rand()% 6 + 1);
        die2 = (rand()% 6 + 1);
        die3 = (rand()% 6 + 1);
        return die1 + die2 + die3;
    }
    else if(this->health <= 8 && this->health > 4){
        die1 = (rand()% 6 + 1);
        die2 = (rand()% 6 + 1);
        return die1 + die2;
    }
    else{
        die1 = (rand()% 6 + 1);
        return die1;
    }
}

bool BlueMen::isDead(){
    if(this->health < 1){ // checks if the character is dead
        return true;
    }
    return false;
}

void BlueMen::takeDamage(int damage){
    if(this->health - damage < 1){ // checks if the user is dead
        this->health = 0;
    }
    else{
        this->health -= damage;
    }
}
// Getters
int BlueMen::getHealth(){
    return this->health;
}
int BlueMen::getArmor(){
    return this->armor;
}
int BlueMen::getType(){
    return this->type;
}
std::string BlueMen::getName(){
    return this->name;
}
