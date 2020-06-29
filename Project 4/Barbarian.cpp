//
//  Barbarian.cpp
//  Project 4
//
//  Created by Dylan Trull on 11/24/19.
//
//  Barbarian class that creates the barbarian functions to use the barbarian

#include "Barbarian.hpp"

Barbarian::Barbarian(std::string name){ // basic barbartian configuration
    this->health = 12;
    this->armor = 0;
    this->type = 2;
    this->name = name;
}
int Barbarian::attack(){ // attacks with 2 6 sided die
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    
    return die1 + die2;
}
int Barbarian::defend(){ // defends with 2 6 sided die
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    
    return die1 + die2;
}

bool Barbarian::isDead(){ // checks if the character has no health
    if(this->health < 1){
        return true;
    }
    return false;
}
void Barbarian::takeDamage(int damage){ // adds the dmg to the health
    if(this->health - damage < 1){
        this->health = 0;
    }
    else{
        this->health -= damage;
    }
}
//Getters
int Barbarian::getArmor(){
    return this->armor;
}
int Barbarian::getHealth(){
    return this->health;
}
int Barbarian::getType(){
    return this->type;
}
std::string Barbarian::getName(){
    return this->name;
}
void Barbarian::recoverHealth(){
    this->armor += 1; // giveing +1 armor to give more to barbarian kit
    this->health += 2; // gains only 2 health in return so not completely vulnerable
}
