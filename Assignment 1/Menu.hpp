//
//  Menu.hpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//  
// Menu header that integrates the input validation

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include "Ant.hpp"
#include "Board.hpp"
#include "InputValidation.hpp"

class Menu{
private:
    inputValidation i;
public:
    int menu();
};

#endif /* Menu_hpp */
