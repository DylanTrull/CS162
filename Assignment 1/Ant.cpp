//
//  Ant.cpp
//  Project 1
//
//  DDylan Trull 10/13/2019
//
//  Ant file that keeps track of orientaton, and position, and prints the ants current location.

#include "Ant.hpp"
#include <iostream>

Ant::Ant(Board* b, int rowSize, int colSize){
    board = b;
    AntX = rowSize;
    AntY = colSize;
    AntOrientation = 1;
}

int Ant::GetAntOrientation(){
    return AntOrientation;
}

void Ant::MoveAnt(int x, int y){
    //White space
    //AntOrientation 1: UP 2: DOWN 3: LEFT 4: RIGHT

    if(board -> getColor(x,y) == ' '){
        if(AntOrientation == 1){  //from up to right
            AntOrientation = 4;
        }
        else if(AntOrientation == 2){ // from down to left turning right
            AntOrientation = 3;
        }
        else if(AntOrientation == 3){ // from left to up
            AntOrientation = 1;
        }
        else if(AntOrientation == 4){ // from right to down
            AntOrientation  = 2;
        }
    }
    //Black space
    else{
        if(AntOrientation == 1){ //from up to left
            AntOrientation = 3;
        }
        else if(AntOrientation == 2){ // from down to right
            AntOrientation = 4;
        }
        else if(AntOrientation == 3){ // from left to down
            AntOrientation = 2;
        }
        else if(AntOrientation == 4){ // from right to up
            AntOrientation  = 1;
        }
        
    }
    
    board -> ChangeColor(x, y);
    
    if(AntOrientation == 1){
        AntX = x - 1;
    }
    else if(AntOrientation == 2){
        AntX = x + 1;
    }
    else if(AntOrientation == 3){
        AntY = y - 1;
    }
    else if(AntOrientation == 4){
        AntY = y + 1;
    }
    
//    checking if ant is out of bounds and moves the ant back on the board if it is.
    if(board ->wallCheck(AntX, AntY)){

        if(AntOrientation == 1){
            AntX += 2;
            AntOrientation = 4;
        }
        else if(AntOrientation == 2){
            AntX -= 2;
            AntOrientation = 1;
        }
        else if(AntOrientation == 3){
            AntY += 2;
            AntOrientation = 4;
        }
        else if(AntOrientation == 4){
            AntY -= 2;
            AntOrientation = 3;
        }
    }
    
}

int Ant::getX(){
    return AntX;
}

int Ant::getY(){
    return AntY;
}

void Ant::Print(Board *b, Ant a){
    int antCol = a.getY();
    int antRow = a.getX();     // getting values of board and current ant value
    int rowSize = b->getRowSize();
    int colSize = b->getColSize();
    
    for(int i = 0; i<rowSize; i++){
        for(int k = 0; k<colSize; k++){
            
            
            if(i == antRow && k == antCol){
                std::cout<<'*'; // placing the ant at its current value
            }
            else{
                std::cout << b->getColor(i, k); // checking the current color of the board
            }
            
        }
        std::cout<<std::endl;
    }
}
