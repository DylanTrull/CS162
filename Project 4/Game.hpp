//
//  Game.hpp
//  Project 4
//
//  Created by Dylan Trull on 11/24/19.
//
//  header file for game class that acts as a test table for the characters

#ifndef Game_hpp
#define Game_hpp

#include "Lineup.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

class Game{
private:
    Character *player1;
    Character *player2;
    Lineup *team1;
    Lineup *team2;
    Lineup *loserQueue;
    
    int numFighters;
    int redPoints;
    int bluePoints;

public:
    Game();
    ~Game();
    
    void menu();
    void chooseFighter(Lineup *);
    void chooseCharacter(int input);
    void startCombat();
};

#endif /* Game_hpp */
