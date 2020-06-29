//
//  Game.cpp
//  Project 3
//
//  Dylan Trull 11/10/19.
//
// Game class that runs the combat simulator with the neeeded characters.

#include "Game.hpp"

//prototypes for input validation
bool isRightInput(std::string input);
int getInput();


Game::Game(){
    player1 = NULL; // sets the players to null
    player2 = NULL;
}
Game::~Game(){}

void Game::menu(){
    std::srand(std::time(NULL)); // random seed
    
    int input;
    
    std::cout << "1. Play Combat Game" << std::endl;
    std::cout << "2. Quit" << std::endl;
    input = getInput();
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    if(input == 2){
        std::cout<<"Quiting..."<<std::endl;
        std::exit(0);
    }
    int i = 1;
    while (i <= 2){
        
        std::cout << "Character list: " << std::endl;
        std::cout << "Please choose a character player #" << i << std::endl;
        std::cout << "1. Vampire" << std::endl;
        std::cout << "2. Barbarian" << std::endl;
        std::cout << "3. Blue Men" << std::endl;
        std::cout << "4. Medusa" << std::endl;
        std::cout << "5. Harry Potter" << std::endl;
        input = getInput();
        while(input < 1 || input > 5){
            std::cout<<"Please enter an integer between 1 and 5" << std::endl;
            input = getInput();
        }
        chooseCharacter(input);
        
        i++;
    }
    
    startCombat();
    
    std::cout<<"-----The combat has ended-----"<<std::endl;
    delete player1; // at the end of the game reset the characters the players picked
    delete player2;
    player1 = NULL;
    player2 = NULL;
    
    menu(); // loop the menu until the player quits.
}

void Game::chooseCharacter(int input){
    if(input == 1){
        if(player1 == NULL){ // checks if player1 is taken
            std::cout<<"Player 1 has chosen Vampire. "<<std::endl;
            player1 = new Vampire();
        }
        else{ // if player 1 is taken set player 2 to the value.
            std::cout<<"Player 2 has chosen Vampire. "<<std::endl;
            player2 = new Vampire();
        }
    }
    else if(input == 2){
        if(player1 == NULL){
            std::cout<<"Player 1 has chosen Barbarian. "<<std::endl;
            player1 = new Barbarian();
        }
        else{
            std::cout<<"Player 2 has chosen Barbarian. "<<std::endl;
            player2 = new Barbarian();
        }
    }
    else if(input == 3){
        if(player1 == NULL){
            std::cout<<"Player 1 has chosen Blue Men. "<<std::endl;
            player1 = new BlueMen();
        }
        else{
            std::cout<<"Player 2 has chosen Blue Men. "<<std::endl;
            player2 = new BlueMen();
        }
    }
    else if(input == 4){
        if(player1 == NULL){
            std::cout<<"Player 1 has chosen Medusa. "<<std::endl;
            player1 = new Medusa();
        }
        else{
            std::cout<<"Player 2 has chosen Medusa. "<<std::endl;
            player2 = new Medusa();
        }
    }
    else if(input == 5){
        if(player1 == NULL){
            std::cout<<"Player 1 has chosen Harry Potter. "<<std::endl;
            player1 = new HarryPotter();
        }
        else{
            std::cout<<"Player 2 has chosen Harry Potter. "<<std::endl;
            player2 = new HarryPotter();
        }
    }
}

void Game::startCombat(){
    int round = 1;
    int attackRoll;
    int defendRoll;
    int totalDamage;
    
    while(true){// its a fight to the death
        std::cout <<"----------Round " << round <<" : FIGHT----------"<<std::endl;
        std::cout<<std::endl;
        //player 1 attacks first
        std::cout<<"-----Player 1's turn-----"<<std::endl;
        attackRoll = player1->attack();
        defendRoll = player2->defend();
        totalDamage = (attackRoll- defendRoll - player2->getArmor());
        
        if(totalDamage < 0){
            totalDamage = 0; // cant have negative damage so set to 0
        }
        
        std::cout<<"Attacker: " <<player1->getName() <<std::endl;
        std::cout<<"Defender: "<<player2->getName() << " Armor: " <<player2->getArmor() << " Health: "<<player2->getHealth() <<std::endl;
        
        std::cout<<"Attacker Rolled "<< attackRoll<<std::endl;
        std::cout<<"Defender Rolled " << defendRoll <<std::endl;
        
        std::cout << "Attacker does " << totalDamage<< " damage." << "(Attacker Roll: " << attackRoll << "- Defender Roll: " << defendRoll << " - Defender Armor: " << player2->getArmor() << std::endl;
        
        player2->takeDamage(totalDamage);
        std::cout<<"Player 2 has " << player2->getHealth() <<" Health remaining"<<std::endl;
        
        if(player2->isDead()){
            std::cout<<"Player 2 has died!\nPlayer 1 is Victorious!"<<std::endl;
            break; // ends when a player dies
        }
        //player 2 attacks now
        std::cout<<std::endl;
        std::cout<<"-----Player 2's turn-----"<<std::endl;
        attackRoll = player2->attack();
        defendRoll = player1->defend();
        totalDamage = (attackRoll - defendRoll - player1->getArmor());
        
        if(totalDamage < 0){
            totalDamage = 0; // Cant do negative damage so set it to 0.
        }
        
        std::cout<<"Attacker: " <<player2->getName() <<std::endl;
        std::cout<<"Defender: "<<player1->getName() << " Armor: " <<player1->getArmor() << " Health: "<<player1->getHealth() <<std::endl;
        
        std::cout<<"Attacker Rolled "<< attackRoll<<std::endl;
        std::cout<<"Defender Rolled " << defendRoll <<std::endl;
        
        std::cout << "Attacker does " << totalDamage<< " damage." << "(Attacker Roll: " << attackRoll << " - Defender Roll: " << defendRoll << " - Defender Armor: " << player1->getArmor() << std::endl;
        
        player1->takeDamage(totalDamage);
        std::cout<<"Player 1 has " << player1->getHealth() <<" Health remaining"<<std::endl;
        
        if(player1->isDead()){
            std::cout<<"Player 1 has died!\nPlayer 2 is Victorious!"<<std::endl;
            break; // ends the game once one character had died
        }
        
        round++; // keeps track of the rounds
        
    }
}
