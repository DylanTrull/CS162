//
//  Game.hpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
//  header file for game class that acts as a test table for the characters

#ifndef Game_hpp
#define Game_hpp

#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

class Game{
private:
    Character *player1;
    Character *player2;
    
public:
    Game();
    ~Game();
    
    void menu();
    void chooseCharacter(int input);
    void startCombat();
};

#endif /* Game_hpp */
