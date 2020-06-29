//
//  Ant.hpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//
// Ant Header file that creates the required objects for the ant class

#ifndef Ant_hpp
#define Ant_hpp

#include <iostream>
#include"Ant.hpp"
#include"Board.hpp"
#include"InputValidation.hpp"

class Ant{
private:
    Board* board;
    int AntX; // current x value of ant
    int AntY; // current y value of ant
    int AntOrientation = 1;
    
public:
    Ant(Board* b,int rowSize, int colSize);
    void Print(Board* b, Ant A);
    int getX();
    int getY();
    void MoveAnt(int x, int y);
    int GetAntOrientation();
    
    
};

#endif /* Ant_hpp */
