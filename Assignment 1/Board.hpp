//
//  Board.hpp
//  Project 1
//
//  Dylan Trull 10/13/2019
// 
// Board header file that is used to create the required objects for board class.

#ifndef Board_hpp
#define Board_hpp

#include <iostream>

class Board{
private:
    char** board;
    int Row;
    int Col;
public:
    Board(char** Board, int row, int col);
    int getRowSize();
    int getColSize();
    bool wallCheck(int row, int col);
    char getColor(int row, int col);
    void ChangeColor(int row, int col);
    
};


#endif /* Board_hpp */
