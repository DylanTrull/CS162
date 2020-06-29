//
//  HarryPotter.cpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  Harry Potter Class file that creates the needed functions for Harry potter character to work

#include "HarryPotter.hpp"
HarryPotter::HarryPotter(){ // defualt configuration of Harry Potter
    this->health = 10;
    this->armor = 0;
    this->type = 5;
    this->name = "Harry Potter";
    hogwarts = true; // Sets the passive effect that Harry Potter into effect
}
int HarryPotter::attack(){ // 2 6 sided die
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    
    return die1+die2;
}
int HarryPotter::defend(){ // 2 6 sided die
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    
    return die1+die2;
}
bool HarryPotter::isDead(){ // checks if potter is dead
    if(this->health < 1){
        return true;
    }
    return false;
}
void HarryPotter::takeDamage(int damage){
    if(this->health - damage < 1){ // if he has less then 0 health set it to 0
        this->health = 0;
    }
    else{
        this->health -= damage;
    }
    
    if(this->health == 0 && hogwarts){ // if his health reaches 0 and still has passive
        this->health = 20; //set his health to 20.
        hogwarts = false;
        std::cout<<"Harry Potter used hogwarts to bring himself back to life!"<<std::endl;
    }
}
// getters
int HarryPotter::getHealth(){
    return this->health;
}
int HarryPotter::getArmor(){
    return this->armor;
}
int HarryPotter::getType(){
    return this->type;
}
std::string HarryPotter::getName(){
    return this->name;
}
