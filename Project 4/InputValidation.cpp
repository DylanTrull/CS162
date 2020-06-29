//
//  InputValidation.cpp
//  Project 4
//
//  Created by Dylan Trull on 11/24/19.
//
// Universal InputValidation class
//
#include <iostream>
#include <string>
#include <algorithm>    

bool isRightInput(std::string input){
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
// https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c Used from here
int getInput(){
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
