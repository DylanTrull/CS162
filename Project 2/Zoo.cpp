//
//  Zoo.cpp
//  Project 2
//
//  Dylan Trull  10/27/19.
//  Zoo class file that creates the animal objects and uses them in the functions below
//

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool isRightInput(std::string input);
int getInput();

Zoo::Zoo(){
    tigers = new Animal *[10];
    penguins = new Animal *[10];
    turtles = new Animal *[10];
    numTigerArr = 10; // type 1
    numPenguinArr = 10; // type 2
    numTurtleArr = 10; // type 3
    tigerBonusMoney = 0;
    bank = 100000;  // default money bank
    setArrNull(tigers, numTigerArr);
    setArrNull(penguins, numPenguinArr); // sets all the arrays to null
    setArrNull(turtles, numTurtleArr);
    
}

void Zoo::sortAnimals(Animal *animal){ // Sorts the animals into the right arrays
    if(animal->getType() == 1){ //checks for which type of animal they are
        if(arrFull(tigers, numTigerArr)){// checks for if the array is full
            remakeArr(tigers, numTigerArr); //  remakes the array with double the size.
        }
        for(int i = 0; i < numTigerArr; i++){
            if(tigers[i] == NULL){ // checks to see if there is an open spot
                tigers[i] = animal; //Sets the current open slot to the animal.
                break; // The animal is added to the array so no need to keep searching.
            }
        }
    }
    
    else if(animal->getType() == 2){
        if(arrFull(penguins, numPenguinArr)){
            remakeArr(penguins, numPenguinArr);
        }
        for(int i = 0; i< numPenguinArr; i++){ // see above explanation
            if(penguins[i] == NULL){
                penguins[i] = animal;
                break;
            }
        }
    }
    
    else if (animal->getType() == 3){
        if(arrFull(turtles, numTurtleArr)){
            remakeArr(turtles, numTurtleArr);
        }
        for(int i = 0; i< numTurtleArr; i++){ // see above explanation
            if(turtles[i] == NULL){
                turtles[i] = animal;
                break;
            }
        }
    }
}
void Zoo::printAnimals(){ //Prints the current animals
    
    int numTigers = 0;
    int numPenguins = 0;
    int numTurtles = 0;
    
    for(int i = 0; i < numTigerArr; i++){
        if(tigers[i] != NULL){ //looks for spaces without a NULL value.
            numTigers++;
        }
    }
    for(int i = 0; i < numPenguinArr; i++){
        if(penguins[i] != NULL){
            numPenguins++;
        }
    }
    for(int i = 0; i < numTurtleArr; i++){
        if(turtles[i] != NULL){
            numTurtles++;
        }
    }
    std::cout<<"The animals in the zoo are:"<<std::endl;
    std::cout<<"Tigers: "<< numTigers << std::endl;
    std::cout<<"Penguins: "<< numPenguins <<std::endl;
    std::cout<<"Turtles : "<< numTurtles << std::endl;
}
bool Zoo::arrFull(Animal **a, int arrSize){ // checks to see if the array is full
    for(int i = 0; i < arrSize; i++){
        if(a[i] == NULL){
            return false; // if current index is NUll array isnt full
        }
    }
    return true; // array is full
}

void Zoo::remakeArr(Animal **&a, int &arrSize){ // remakes the array into double the size and saves the size
    Animal **arr = new Animal *[arrSize * 2]; // creates array double of size
    setArrNull(arr, arrSize*2); // sets all the spaces of the new array to NULL.
    
    for(int i = 0; i < arrSize; i++){
        arr[i] = a[i];
    }
    delete [] a; // Deletes old array.
    
    a = arr; // sets the pointer value to the new arr
    
    arrSize = arrSize * 2;
}
void Zoo::deleteArrs(){ // deletes each animal array
    for(int i = 0; i<numTigerArr; i++){
        delete tigers[i]; // deletes each tiger
    }
    delete [] tigers; // deletes the tiger array
    
    for(int i = 0; i<numPenguinArr; i++){
        delete penguins[i]; // deletes each penguin
    }
    delete [] penguins;// deletes the penguin array
    
    for(int i = 0; i < numTurtleArr;i++){
        delete turtles[i]; // deletes each turtle
    }
    delete [] turtles; // delete the turtle array
}
void Zoo::setArrNull(Animal **a, int size){ // sets array values tto NULL
    for(int i = 0; i < size; i++){
        a[i] = NULL; // goes through array and sets each value to NULL
    }
}
void Zoo::purchaseBabyAnimals(){//The starting game when you are able to purchase baby animals
    int input;
    std::cout<<"To start the game you must atleast buy 1 of each animal " << std::endl;
    std::cout<<"Tigers are $10,000.    BALANCE:$" << getBank()<<std::endl;
    std::cout<<"How many do you want to buy? \n1 \n2"<<std::endl;
    
    input = getInput(); // uses input validaiton class to check for int
    
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    if(input == 1){
        payBill(10000);
        std::cout<<"You bought a Tiger for $10,000.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Tiger()); // sorts a new tiger into the array
    }
    else if(input == 2){
        payBill(20000);
        std::cout<<"You bought two Tigers for $20,000.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Tiger());
        sortAnimals(new Tiger());
    }
    std::cout<<std::endl;
    std::cout<<"Penguins are $1,000.    BALANCE:$" << getBank()<<std::endl;
    std::cout<<"How many do you want to buy? \n1 \n2"<<std::endl;
    
    input = 0;
    input = getInput(); // input validation class to chek for int
    
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    if(input == 1){
        payBill(1000);
        std::cout<<"You bought a Penguin for $1,000.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Penguin());
    }
    else if(input == 2){
        payBill(2000);
        std::cout<<"You bought two Penguins for $2,000.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Penguin());
        sortAnimals(new Penguin());
    }
    std::cout<<std::endl;
    std::cout<<"Turtles are $100.    BALANCE:$" << getBank()<<std::endl;
    std::cout<<"How many do you want to buy? \n1 \n2"<<std::endl;
    
    input = 0;
    input = getInput();
    
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    if(input == 1){
        payBill(100);
        std::cout<<"You bought a Turtle for $100.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Turtle());
    }
    else if(input == 2){
        payBill(200);
        std::cout<<"You bought two Turtles for $200.    BALANCE:$" <<getBank()<< " remaining"<<std::endl;
        sortAnimals(new Turtle());
        sortAnimals(new Turtle());
    }
}
void Zoo::purchaseAdultAnimal(){ // end of the day when you are allowed to purchase
    int input;
    
    std::cout<<"Would you like to purchase an adult Animal?" <<std::endl;
    std::cout<<"1. Yes \n2. No" << std::endl;
    input = getInput();
    
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    if(input == 2){
        std::cout<<std::endl;
    }
    else if(input == 1){ // if the user decides to purchase an animal
        std::cout<<"Please pick which animal          BALANCE:$"<<getBank()<< std::endl;
        std::cout<<"1. Tiger $10,000\n2. Penguin $1,000\n3. Turtle $100"<<std::endl;
        
        input = 0;
        input = getInput();
        
        while(input < 1 || input > 3){
            std::cout<<"Please enter an integer between 1 and 3" << std::endl;
            input = getInput();
        }
        
        if(input == 1){ // purchases a tiger
            std::cout<<"You purchased a Tiger for $10,000.    BALANCE:$"<<getBank()<<" remaining"<<std::endl;
            sortAnimals(new Tiger(3));
        }
        else if(input == 2){ // purchases a penguin
            std::cout<<"You purchased a Penguin for $1,000.    BALANCE:$"<<getBank()<<" remaining"<<std::endl;
            sortAnimals(new Penguin(3));
        }
        else if(input == 3){ //  purchases a turtle
            std::cout<<"You purchased a Turtle for $100.    BALANCE:$"<<getBank()<<" remaining"<<std::endl;
            sortAnimals(new Turtle(3));
        }
    }
}
void Zoo::payBill(int bill){ // changes the bank balance lower
    bank = bank - bill;
}
void Zoo::getMoney(int pay){ // changes the bank balance higher
    bank = bank + pay;
}
int Zoo::tigerCost(){ // finds out the cost of the tiger food
    int totalCost = 0;
    for(int i = 0; i < numTigerArr; i++){
        if(tigers[i] != NULL){ // looks at all non NULL objects of the array
            totalCost += tigers[i]->getFoodCost();
        }
    }
    return totalCost;
}
int Zoo::penguinCost(){ //finds the cost of the penguin food
    int totalCost = 0;
    for(int i = 0; i < numPenguinArr; i++){
        if(penguins[i] != NULL){
            totalCost += penguins[i]->getFoodCost();
        }
    }
    return totalCost;
}
int Zoo::turtleCost(){ // finds the cost of the turtle food
    int totalCost = 0;
    for(int i = 0; i < numTurtleArr; i++){
        if(turtles[i] != NULL){
            totalCost += turtles[i]->getFoodCost();
        }
    }
    return totalCost;
}
int Zoo::tigerPay(){// finds out the payout that the tigers produce
    int totalPay = 0;
    for(int i = 0; i < numTigerArr; i++){
        if(tigers[i] != NULL){ // looks at all non NULL objects
            totalPay += tigers[i]->getPayoff();
        }
    }
    return totalPay;
}
int Zoo::penguinPay(){ // finds out the payout that the penguins produce
    int totalPay = 0;
    for(int i = 0; i < numPenguinArr; i++){
        if(penguins[i] != NULL){
            totalPay += penguins[i]->getPayoff();
        }
    }
    return totalPay;
}
int Zoo::turtlePay(){// finds out the payout that the turtle produce
    int totalPay = 0;
    for(int i = 0; i < numTurtleArr; i++){
        if(turtles[i] != NULL){
           totalPay += turtles[i]->getPayoff();
        }
    }
    return totalPay;
}
int Zoo::getFeedingCost(){ // figures out the feeding cost of all 3 animals
    int totalCosts = 0;
    totalCosts = tigerCost() + penguinCost() +  turtleCost();
    
    return totalCosts;
}
int Zoo::getBank(){ // returns the bank ammount
    return bank;
}
int Zoo::getPayoff(){ // figures out the total payoff for all 3 animals
    int totalPayoff = 0;
    
    totalPayoff = tigerPay() + penguinPay() + turtlePay();
    
    return totalPayoff;
}

void Zoo::randomEvent(){ // creates a random event
    int ran = (rand() % 4 + 1); // creates a random number between 1 and 4
    
    if(ran == 1){
        std::cout<<"A random animal got sick! "<< std::endl;
        sickAnimal();
    }
    else if(ran == 2){
        std::cout<<"The Tigers have a boom in attendence! "<<std::endl;
        tigerAttendance();  
    }
    else if(ran == 3){
        std::cout<<"A baby animal was born! " <<std::endl;
        babyBorn();
    }
    else{
        std::cout<<"No random event today! "<<std::endl;
    }
}
void Zoo::sickAnimal(){
    int ran = (rand() % 3 + 1); // creates a random number between 1 and 3
    
    if(ran == 1){
        if(tigers[0] == NULL){
            std::cout<<"There was a tiger sickness but it doesn't look like you have any "<<std::endl;
        }
        else{ // if there are some tigers
            tigerDeath();
        }
    }
    else if(ran == 2){
        if(penguins[0] == NULL){
            std::cout<<"There was a Penguin sickness but it doesn't look like you have any "<<std::endl;
        }
        else{ // if there are penguins
            penguinDeath();
        }
    }
    else{
        if(turtles[0] == NULL){
            std::cout<<"There was a Turtle sickness but it doesn't look like you have any " <<std::endl;
        }
        else{ // if there are turtles
            turtleDeath();
        }
    }
}
void Zoo::tigerDeath(){ // removes the last tiger from the array
    int lastTiger;
    for(int i = 0; i<numTigerArr; i++){
        if(tigers[i] == NULL){
            lastTiger = i-1;
        }
    }
    delete tigers[lastTiger];
    tigers[lastTiger] = NULL;
    std::cout<<"Oh no one of your Tigers died! "<<std::endl;
}
void Zoo::penguinDeath(){ // removes a penguin from the end of the array
    int lastPenguin;
    for(int i = 0; i<numPenguinArr; i++){
        if(penguins[i] == NULL&&penguins[i-1] != NULL){
            lastPenguin = i-1;
            std::cout<<"Oh no one of your Penguins died! "<<std::endl;
        }
    }
    delete penguins[lastPenguin];
    penguins[lastPenguin] = NULL;
    
}
void Zoo::turtleDeath(){ // removes a turtle from the end of the array
    int lastTurtle;
    for(int i = 0; i<numTurtleArr; i++){
        if(turtles[i] == NULL&&turtles[i-1] != NULL){ // requires atleast 1
            lastTurtle = i-1;
            std::cout<<"Oh no one of your Turtles died! "<<std::endl;
        }
    }
    delete turtles[lastTurtle];
    turtles[lastTurtle] = NULL;
}
void Zoo::tigerAttendance(){ //each tiger gets $250-$500
    int totalTigers = 0;
    int bonusMoney = 0;
    
    for(int i = 0; i < numTigerArr; i++){
        if(tigers[i] != NULL){
            totalTigers++;
        }
    }
    if(totalTigers>0 && tigers[0] != NULL){
        int ran = (rand() % 500 + 250); // picks a random number between 250-500
        
        bonusMoney = totalTigers * ran;
        std::cout<<"Your " <<totalTigers<< " tigers made you an extra: $"<< bonusMoney << std::endl;
        getMoney(bonusMoney);
        tigerBonusMoney = bonusMoney;
    }
    else{
        std::cout<<"Sorry doesn't look like you have any tigers! "<<std::endl;
    }
}

void Zoo::babyBorn(){
    int ran = (rand() % 3 + 1);//picks a random number between 1 and 3
    bool bornBaby = false;
    if(ran == 1){ // 1 = tiger
        for(int i = 0; i < numTigerArr; i++){
            if(tigers[i] != NULL && tigers[i]->getAge() >= 3){
                std::cout<<"A baby tiger was born!"<<std::endl;
                sortAnimals(new Tiger(0)); // creates 1 baby
                bornBaby = true;
                break;
            }
            
        }
        if(!bornBaby){
            std::cout<<"There are no tigers able to make babies "<<std::endl;
        }
    }
    else if(ran == 2){ // 2 = penguin
        for(int i = 0; i < numPenguinArr; i++){
            if(penguins[i] != NULL && penguins[i]->getAge() >= 3){
                std::cout <<"5 Baby penguins were born!"<<std::endl;
                for(int k = 0; k<5; k++){ // creates 5 babies
                    sortAnimals(new Penguin(0));
                }
                bornBaby = true;
                break;
            }
        }
        if(!bornBaby){
            std::cout<<"There are no penguins able to make babies"<<std::endl;
        }
    }
    else if(ran == 3){ // 3 = turtle
        for(int i = 0; i < numTurtleArr; i++){
            if(turtles[i] != NULL && turtles[i]->getAge() >= 3){
                std::cout<<"10 Baby turtles were born! "<<std::endl;
                for(int k = 0; k < 10; k++){ // creates 10 babies
                    sortAnimals(new Turtle(0));
                }
            bornBaby = true;
            break;
            }
        }
        if(!bornBaby){
            std::cout<<"There are no turtles able to make babies" << std::endl;
        }
    }
}

void Zoo::ageAnimals(){ // ages the 3 animals
    ageTigers();
    ageTurtles();
    agePenguins();
    
    std::cout<<"All animals have been aged by 1 day"<<std::endl;
}
void Zoo::ageTigers(){ // ages the tiger
    for(int i = 0; i <numTigerArr; i++){
        if(tigers[i] != NULL){
            tigers[i]->ageADay();
        }
    }
}
void Zoo::agePenguins(){ // ages the penguins
    for(int i = 0; i < numPenguinArr; i++){
        if(penguins[i] != NULL){
            penguins[i]->ageADay();
        }
    }
}
void Zoo::ageTurtles(){// ages the turtles
    for(int i = 0; i < numTurtleArr; i++){
        if(turtles[i] != NULL){
            turtles[i]->ageADay();
        }
    }
}

void Zoo::zooStart(){ // loops the game
    std::srand(std::time(NULL)); // random seed for random
    int input;
    std::cout<<"1. Play Zoo Tycoon Simulator"<<std::endl;
    std::cout<<"2. Quit"<<std::endl;
    
    input = getInput();
    while(input < 1 || input > 2){
        std::cout<<"Please enter an integer between 1 and 2" << std::endl;
        input = getInput();
    }
    
    if(input == 2){
        std::cout<<"Quiting"<<std::endl;
        std::exit(0);
    }
    bool gameRunning = true;
    purchaseBabyAnimals(); // starts thee game by purchaseing the baby anmals
    
    int day = 1;
    int dayFoodCost = 0; // Food costs for the day
    int dayProfit = 0; // profit for the day
    
    while(gameRunning == true){
        std::cout<<std::endl;
        std::cout<<"------------------DAY "<<day<<"------------------"<<std::endl;
        
        dayProfit = 0;
        tigerBonusMoney = 0;
        
        printAnimals(); // prints all the animals at the zoo every day
        
        dayFoodCost = getFeedingCost(); // gets the feeding cost of all 3 animals
        std::cout<<"The cost to feed your animals today is: $"<<dayFoodCost<<std::endl;
        std::cout<<"BALANCE: $"<<getBank()<<std::endl;
        payBill(dayFoodCost); // pays the cost of the food
        
        std::cout<<"--------Daily Random Event--------"<<std::endl;
        randomEvent(); // random event happens
        
        std::cout<< "--------Day "<<day<<" Summary--------"<<std::endl;
        
        std::cout<<"feeding costs: $" <<dayFoodCost<<std::endl;
        std::cout<<"Animal payoff: $"<< getPayoff()<<std::endl;
        if(tigerBonusMoney > 0){ // if there was a bonus from random event put it in the days profits
            dayProfit = ((getPayoff() - getFeedingCost()) + tigerBonusMoney);
            std::cout<< "Today's attendence bonus: $"<<tigerBonusMoney<<std::endl;
            std::cout<<"Today's total profit: $" <<dayProfit<<std::endl;
        }
        else{ // no bonus from tigers
            dayProfit = (getPayoff() - getFeedingCost());
            std::cout<<"Today's total profit: $" <<dayProfit<<std::endl;
        }
        getMoney(dayProfit); // puts the money in the bank
        std::cout<<"BALANCE: $"<<getBank()<<std::endl;
        
        purchaseAdultAnimal(); // allows tto purchase 1 adult animal at end of the day
        
        std::cout<<"Would you like to advance to day "<<(day+1)<<"?"<<std::endl;
        std::cout<<"1. Yes"<<std::endl;
        std::cout<<"2. No"<<std::endl;
        
        input = 0;
        input = getInput();
        while(input < 1 || input > 2){
            std::cout<<"Please enter an integer between 1 and 2" << std::endl;
            input = getInput();
        }
        
        if(input == 2){
            gameRunning = false;
            break;
        }
        else{
            gameRunning = true;
        }
        ageAnimals(); // ages the animals at the end of the day
        day++; // adds one to the day
    }
    deleteArrs(); // delete the animal arrays and clear the memory
}
