//
//  InputValidation.hpp
//  Project 1
//
//  Dylan Trull 10/13/2019
//
// Header file for inputValidation that creates the 3 public input validiation

#ifndef InputValidation_hpp
#define InputValidation_hpp

#include <iostream>
#include <string>

class inputValidation{
public:
    int getInput();
    bool isRightInput(std::string input);
    bool Range(int input, int max, int min);
};

#endif /* InputValidation_hpp */
