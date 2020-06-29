//
//  Zoo.hpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Header file for Zoo that creates the many needed functions that run this game.
//
#ifndef Zoo_hpp
#define Zoo_hpp

#include <stdio.h>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo{
private:
    Animal **tigers;
    Animal **penguins;
    Animal **turtles;
    int numTigerArr;
    int numPenguinArr;
    int numTurtleArr;
    int tigerBonusMoney;
    int bank;
    
public:
    Zoo();
    
    void sortAnimals(Animal *a);
    void zooStart(); // Done
    void printAnimals();
    
    void purchaseBabyAnimals();
    void purchaseAdultAnimal(); //Done
    
    int tigerCost();
    int penguinCost();
    int turtleCost(); //Done
    int tigerPay();
    int penguinPay();
    int turtlePay();
    
    int getBank();
    void payBill(int bill);
    void getMoney(int pay); //Done
    int getFeedingCost();
    int getPayoff();
    
    void randomEvent(); // Done
    
    void sickAnimal();
    void tigerDeath(); // Done
    void penguinDeath();
    void turtleDeath();
    
    void tigerAttendance(); // Done
    
    void babyBorn();
    void ageAnimals();
    void ageTigers(); //Done
    void agePenguins();
    void ageTurtles();
    
    void remakeArr(Animal **&a, int &arrSize);
    bool arrFull(Animal **a, int arrSize); // Done
    void setArrNull(Animal **a, int size);
    void deleteArrs();
};

#endif /* Zoo_hpp */
