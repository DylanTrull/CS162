//
//  InputValidation.cpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//
//  File used to check inputs and can be used universially possibly

#include "InputValidation.hpp"
#include <iostream>
#include <string>
#include <algorithm>    


int inputValidation::getInput(){
    std::string input;
    int num;
    
    do{
        getline(std::cin, input);
        input.erase(remove(input.begin(), input.end(), ' '), input.end()); // Removes spaces from the input and parses through it
        
        if (!(isRightInput(input))){ // makes sure the input is a positive int
            std::cout<< "ERROR: Please enter a positive integer." << std::endl;
        }
    }
    while (!(isRightInput(input)));
        num = atoi(input.c_str());
    
        return num;
    
}

bool inputValidation::isRightInput(std::string input){
    bool in;
    
    for(int i = 0; i < input.size(); i++){
        if(isdigit(input[i])){ // checking if the int in the string is an int.
            in = true;
        }
        else{
            return false;
        }
    }
    
    return in;
}

bool inputValidation::Range(int input, int max, int min){ // simple range function to make sure they stay in range
    if(input > max){
        return false;
    }
    else if(input < min){
        return false;
    }
    else{
        return true;
    }
}
