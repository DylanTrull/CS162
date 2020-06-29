//
//  main.cpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//
// Main file that asks the user all the required fields and creates the necesary classes

#include <iostream>
#include "Menu.hpp"
#include "Ant.hpp"
#include "Board.hpp"
#include "InputValidation.hpp"

int main(){
    Menu m;
    int row;
    int col;
    int step;
    int rowSize;
    int colSize;
    
    
    int input = m.menu();
    
    while(input == 1){
        inputValidation i;
        
        std::cout<< "How many rows would you like for the board? (Must be greater then or equal to 1): "<< std::endl;
        
        rowSize = i.getInput();
        
        while(!(rowSize >= 2)){
            std::cout<<"Please enter an integer greater then 1 " << std::endl;
            rowSize = i.getInput();
        }
        std::cout<< "How many colmuns would you like for the board? (Must be greater then or equal to 1): "<< std::endl;
        
        colSize = i.getInput();
        
        while(!(colSize >= 2)){
            std::cout<<"Please enter an integer greater then 1 " << std::endl;
            colSize = i.getInput();
        }
        std::cout<< "How many steps should the ant take? (Must be greater then 0) " << std::endl;
        
        step = i.getInput();
        
        while(!(step > 0)){
            std::cout<< "Please enter an integer greater then 0"<<std::endl;
            step = i.getInput();
        }
        
        std::cout<< "Enter where the ant's starting row should be on the board between 0 and "<< rowSize-1<<std::endl;
        
        row = i.getInput();
        
        while(!(i.Range(row, rowSize-1, 0))){
            std::cout<<"Please type an integer between 0 and "<< rowSize-1 << std::endl;
            row = i.getInput();
        }
        std::cout<< "Enter where the ant's starting column should be on the board between 0 and "<< colSize-1<<std::endl;
        
        col = i.getInput();
        
        while(!(i.Range(col, colSize-1, 0))){
            std::cout<<"Please type an integer between 0 and "<< colSize-1 << std::endl;
            col = i.getInput();
        }
        char** arr = new char*[rowSize];
        for(int i = 0; i<rowSize; i++){
            arr[i] = new char[colSize];
        }
        
        
        Board* board = new Board(arr, rowSize, colSize);
        
        
        Ant Ant(board, row, col);
        
//        board->BoardCreate(rowSize, colSize, row, col);
        int stepCounter = 0;
        while(stepCounter<step){
            stepCounter += 1;
            
            int aRow = Ant.getX();
            int aCol = Ant.getY();
            
            Ant.MoveAnt(aRow, aCol);
            Ant.Print(board, Ant);
            
            int antRow = Ant.getX();
            int antCol = Ant.getY();
            
            std::cout<< "This is step " << stepCounter << std::endl;
            std::cout<< "The ants location is " << antRow << ","<< antCol << std::endl;
            std::cout<< "Please press enter to have the ant take a step. ";
            std::cin.get();
            
            
        }
        for(int row = 0; row < rowSize; row++){
            delete [] arr[row];
        }
        delete [] arr;
        
        input = m.menu();
    }
    if(input == 2){
        return 0;
    }
}
