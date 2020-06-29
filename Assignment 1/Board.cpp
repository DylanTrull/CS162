//
//  Board.cpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//  
// Creates the "Board" that the ant sits on top of

#include "Board.hpp"
#include <iostream>
#include <string>

Board::Board(char** b, int RowSize, int ColSize){
    board = b;
    Row = RowSize;
    Col = ColSize;
}

int Board::getRowSize(){ // gives row size
    return Row;
}

int Board::getColSize(){ // gives column size
    return Col;
}
bool Board::wallCheck(int row, int col){ // safeguard for out of bound ant moving
    if(row < 0){
        return true;
    }
    if (row > Row - 1){
        return true;
    }
    if (col < 0){
        return true;
    }
    if (col > Col - 1){
        return true;
    }
    return false;
}

char Board::getColor(int row, int col){ // reveals the current tile the ant is on
    char t = board[row][col];
    
    if(t != ' ' && t != '#' ){
        return ' ';
    }
    return t;
}

void Board::ChangeColor(int row, int col){ // Changes the color of the tile the ant is on.
    char color = getColor(row, col);
    
    
    //changes board from white to black
    if(color == ' '){
        board[row][col] = '#';
    }
    //changes board from black to white
    else if( color == '#'){
        board[row][col] = ' ';
    }
}

