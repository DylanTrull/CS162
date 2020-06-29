//
//  Medusa.cpp
//  Project 4
//
//  Created by Dylan Trull on 11/24/19.
//
//  Medusa Class that uses the virtual functions from the Character class

#include "Medusa.hpp"

Medusa::Medusa(std::string name){ // defualt configuration of Medusa
    this->health = 8;
    this->armor = 3;
    this->type = 4;
    this->name = name;
}

int Medusa::attack(){ // Medusa has 2 6 sided die and if they add to 12 instantly kill
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    
    if(die1+die2 == 12){
        std::cout<<"Medusa rolled a 12! she uses glare and instantly kills her opponent! "<<std::endl;
        return 100; // enough to oneshot but not enough to kill vampire if he charms
    }
    else{
        return die1+die2;
    }
}
int Medusa::defend(){ //1 6 sided die
    return (rand() % 6 + 1);
}

bool Medusa::isDead(){ // checks if medusa is dead
    if(this->health < 1){
        return true;
    }
    return false;
}
void Medusa::takeDamage(int damage){ // determines if dead if not then minus health
    if(this->health - damage < 1){
        this->health = 0;
    }
    else{
        this->health -= damage;
    }
}
//getters
int Medusa::getHealth(){
    return this->health;
}
int Medusa::getArmor(){
    return this->armor;
}
int Medusa::getType(){
    return this->type;
}
std::string Medusa::getName(){
    return this->name;
}
void Medusa::recoverHealth(){
    int die = (rand() % 6 + 1);
    this->health += die;
}
