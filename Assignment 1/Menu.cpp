//
//  Menu.cpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//  
// Menu header class that creates a universal menu that can be used in any program.

#include "Menu.hpp"

int Menu::menu(){
    int input;
    
    std::cout << "Type 1: Start Langton’s Ant simulation " << std::endl;
    std::cout << "Type 2: Quit " << std::endl;
    
    input = i.getInput();
    
    while(input <= 0|| input > 2){
        std::cout<<"Please enter an integer between 1 and 2. " << std::endl;
        input = i.getInput();
    }
    return input;
}
