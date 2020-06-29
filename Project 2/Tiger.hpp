//
//  Tiger.hpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Tiger header file that inherits from Animal class
//
#ifndef Tiger_hpp
#define Tiger_hpp

#include <stdio.h>
#include "Animal.hpp"

class Tiger : public Animal{
public:
    Tiger();
    Tiger(int age);
};
#endif /* Tiger_hpp */
