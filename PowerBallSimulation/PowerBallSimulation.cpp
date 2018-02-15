// PowerBallSimulation.cpp
// Programmer: Brenna Olson
//
// Description: Simulate playing lottery game PowerBall
//
// Copyright © 2015 Brenna Olson. All rights reserved.
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TOTAL_NUMBER_SIZE = 6;
const int NUMBER_WHITE_BALLS = TOTAL_NUMBER_SIZE - 1;
const int RED_BALL_LOCATION = TOTAL_NUMBER_SIZE - 1; // There are two constants
                                                     // with the same value
                                                     // because that value
                                                     // refers to different
                                                     // things
const int WHITE_MIN_VALUE = 1;
const int WHITE_MAX_VALUE = 59;
const int RED_MIN_VALUE = 1;
const int RED_MAX_VALUE = 39;


void getWhiteBallInput(int numbers[]);
void getRedBallInput(int &playerNumber);

void validateValueInputWhiteBall(int &numberEntered);
void checkForInputRepeating(int &numberToCheck, int a[], int numberIndex);
void validateValueInputRedBall(int &numberEntered);

void generateWinningWhiteNumbers(int numbers[]);
void generateWinningRedNumber(int &winningNumber);
void checkForWinningNumberRepeating(int &numberToCheck, int a[],
                                    int numberIndex);

void compareInputtedWhiteValuesToWinning(int playerNumbers[],
                                             int winningNumbers[],
                                             bool equalNumbers[]);

void compareInputtedRedValueToWinning(int playerNumber, int winningNumber,
                                      bool equalNumbers[]);


int calculateWinnings(bool a[]);
void displayWinnings(int winningAmount, int playerNumbersWhite[],
                     int playerNumberRed, int winningNumbersWhite[],
                     int winningNumberRed);


int main() {
    
    int playerWhiteNumbers[NUMBER_WHITE_BALLS];
    int playerRedNumber;
    int winningWhiteNumbers[NUMBER_WHITE_BALLS];
    int winningRedNumber;
    
    bool numbersEqualToWinning[TOTAL_NUMBER_SIZE];

    
    getWhiteBallInput(playerWhiteNumbers);
    getRedBallInput(playerRedNumber);
    
    generateWinningWhiteNumbers(winningWhiteNumbers);
    generateWinningRedNumber(winningRedNumber);
    
    compareInputtedWhiteValuesToWinning(playerWhiteNumbers,
                                        winningWhiteNumbers,
                                        numbersEqualToWinning);
    compareInputtedRedValueToWinning(playerRedNumber, winningRedNumber,
                                     numbersEqualToWinning);

    displayWinnings(calculateWinnings(numbersEqualToWinning),
                    playerWhiteNumbers, playerRedNumber, winningWhiteNumbers,
                    winningRedNumber);
    
    return 0;
}


//***************************************************************************
// Function: getWhiteBallInput
//
// Purpose: Get player's white numbers and initialize numbers[] to those values
//
// PreCondition: numbers[] must contain NUMBER_WHITE_BALLS elements
//  (NUMBER_WHITE_BALLS must be initialized)
//
// PostCondition: Array passed in will contain values of user's input; not
//  all elements in array may be initialized
//***************************************************************************

void getWhiteBallInput(int numbers[]) {
    for (int i = 0; i < NUMBER_WHITE_BALLS; i++) {
        cout << "Enter a number between " << WHITE_MIN_VALUE << " and "
             << WHITE_MAX_VALUE << " you haven't already selected: ";
        cin >> numbers[i];
        
        validateValueInputWhiteBall(numbers[i]);
        
        if (i != 0)
            checkForInputRepeating(numbers[i], numbers, i);
    }
}


//***************************************************************************
// Function: getRedBallInput
//
// Purpose: Get player's value for PowerBall
//
// PreCondition: None
//
// PostCondition: playerNumber will be modified to contain player's
//  selected number
//***************************************************************************

void getRedBallInput(int &playerNumber) {
    cout << "\nEnter a number between 1 and 39: ";
    cin >> playerNumber;
    validateValueInputRedBall(playerNumber);
}


//***************************************************************************
// Function: validateValueInputWhiteBall
//
// Purpose: Make sure user entered a number between 1 and 59 for a given white
//  ball
//
// PreCondition: numberEntered must be initialized
//
// PostCondition: numberEntered will be modified if it isn't valid
//***************************************************************************

void validateValueInputWhiteBall(int &numberEntered) {
    while (numberEntered < WHITE_MIN_VALUE || numberEntered > WHITE_MAX_VALUE) {
        cout << "Number entered must be between " << WHITE_MIN_VALUE << " and "
             << WHITE_MAX_VALUE << ". Please re-enter: ";
        cin >> numberEntered;
    }
}


//***************************************************************************
// Function: checkForInputRepeating
//
// Purpose: Make sure user doesn't enter the same number for any two or more
//  white balls
//
// PreCondition: All parameters must be initialized
//
// PostCondition: numberToCheck will be modified if its value has
//  already been selected
//***************************************************************************

void checkForInputRepeating(int &numberToCheck, int a[], int numberIndex) {
    
    int numberRepeated;
    
    do {
        numberRepeated = false;
        
        for (int i = 0; i < numberIndex && numberRepeated == false; i++) {
            if (numberToCheck == a[i])
                numberRepeated = true;
        }
        
        if (numberRepeated) {
            cout << "You have already entered " << numberToCheck << ". Please "
            << "choose a different number: ";
            cin >> numberToCheck;
            validateValueInputWhiteBall(numberToCheck);
        }
        
    } while (numberRepeated);
}


//***************************************************************************
// Function: validateValueInputRedBall
//
// Purpose: Make sure user entered a number between 1 and 39 for the red ball
//
// PreCondition: numberEntered must be initialized
//
// PostCondition: numberEntered will be modified if it isn't valid
//***************************************************************************

void validateValueInputRedBall(int &numberEntered) {
    while (numberEntered < RED_MIN_VALUE || numberEntered > RED_MAX_VALUE) {
        cout << "Number entered must be between " << RED_MIN_VALUE << " and "
        << RED_MAX_VALUE << ". Please re-enter: ";
        cin >> numberEntered;
    }
}


//***************************************************************************
// Function: generateWinningWhiteNumbers
//
// Purpose: Select winning white ball numbers for the game
//
// PreCondition: numbers[] must contain NUMBER_WHITE_BALLS elements
//  (NUMBER_WHITE_BALLS must be initialized)
//
// PostCondition: numbers[] will contain values generated by computer
//***************************************************************************

void generateWinningWhiteNumbers(int numbers[]){
    
    srand(time(NULL));
    
    for (int i = 0; i < NUMBER_WHITE_BALLS; i++) {
        numbers[i] = WHITE_MIN_VALUE + rand() % WHITE_MAX_VALUE;
        checkForWinningNumberRepeating(numbers[i], numbers, i);
    }
}


//***************************************************************************
// Function: generateWinningRedNumber
//
// Purpose: Select winning red number for game
//
// PreCondition: None
//
// PostCondition: winningNumber will be initialized with the value of the game's
//  winning red ball number
//***************************************************************************

void generateWinningRedNumber(int &winningNumber) {
    
    srand(time(NULL));
    
    winningNumber = RED_MIN_VALUE + rand() % RED_MAX_VALUE;
}


//***************************************************************************
// Function: checkForWinningNumberRepeating
//
// Purpose: Make sure winning white ball numbers generated by computer don't
//  repeat
//
// PreCondition: All parameters must be initialized
//
// PostCondition: numberToCheck will be modified if its value has already
//  been used
//***************************************************************************

void checkForWinningNumberRepeating(int &numberToCheck, int a[],
                                    int numberIndex){
    int numberRepeated;
    
    do {
        numberRepeated = false;
        
        for (int i = 0; i < numberIndex && numberRepeated == false; i++) {
            if (numberToCheck == a[i])
                numberRepeated = true;
        }
        
        if (numberRepeated) {
            numberToCheck = WHITE_MIN_VALUE + rand() % WHITE_MAX_VALUE;
        }
        
    } while (numberRepeated);
}


//***************************************************************************
// Function: compareInputtedWhiteValuesToWinning
//
// Purpose: Determine how many of player's numbers match the winning numbers
//
// PreCondition: playerNumbers[] and winningNumbers[] must be initialized and
//  contain NUMBER_WHITE_BALLS elements (NUMBER_WHITE_BALLS must be predefined);
//  equalNumbers[] must contain TOTAL_NUMBER_SIZE elements
//
// PostCondition: equalNumbers[] will be initialized based on the values in
//  playerNumbers[] and winningNumbers[]
//***************************************************************************

void compareInputtedWhiteValuesToWinning(int playerNumbers[],
                                             int winningNumbers[],
                                             bool equalNumbers[]) {

    for (int i = 0; i < NUMBER_WHITE_BALLS; i++) { // iterate through winning
                                                   // numbers
        equalNumbers[i] = false;
        for (int j = 0; j < NUMBER_WHITE_BALLS; j++) { // iterate through
                                                       // player's numbers
            if (winningNumbers[i] == playerNumbers[j])
                equalNumbers[i] = true;
        }
    }
    
}


//***************************************************************************
// Function: compareInputtedRedValueToWinning
//
// Purpose: Determine if player's PowerBall number matches winning number
//
// PreCondition: playerNumber and winningNumber must be initialized;
//  equalNumbers[] must contain TOTAL_NUMBER_SIZE elements (TOTAL_NUMBER_SIZE
//  be predefined)
//
// PostCondition: equalNumbers[RED_BALL_LOCATION] will be modified to contain
//  whether or not the player's number matches the winning number
//***************************************************************************

void compareInputtedRedValueToWinning(int playerNumber, int winningNumber,
                                      bool equalNumbers[]) {
    equalNumbers[RED_BALL_LOCATION] = false;
    if (winningNumber == playerNumber)
        equalNumbers[RED_BALL_LOCATION] = true;
}


//***************************************************************************
// Function: calculateWinnings
//
// Purpose: Calculate amount of money player has won
//
// PreCondition: a[] must be initialized with TOTAL_NUMBER_SIZE elements
// (TOTAL_NUMBER_SIZE must be predefined)
//
// PostCondition: Amount of money player has won will be returned
//***************************************************************************

int calculateWinnings(bool a[]) {
    int amountWon = 0;
    int numberOfWinningWhiteBalls = 0; // keep track of white balls won in
                                       // order to determine winning amount
    int winningAmountsWithoutRedBall[6] = {0, 0, 0, 7, 100, 200000};
    int winningAmountsWithRedBall[6] = {3, 4, 7, 100, 10000, 10000000};
    
    
    for (int i = 0; i < NUMBER_WHITE_BALLS; i++) {
        if (a[i])
            numberOfWinningWhiteBalls++;
    }
    
    if (a[RED_BALL_LOCATION])
        amountWon = winningAmountsWithRedBall[numberOfWinningWhiteBalls];
    else
        amountWon = winningAmountsWithoutRedBall[numberOfWinningWhiteBalls];
    
    return amountWon;
}


//***************************************************************************
// Function: displayWinnings
//
// Purpose: Display amount of money player has won
//
// PreCondition: All parameters must be initialized; playerNumbersWhite[] and
//  winningNumbersWhite[] must have NUMBER_WHITE_BALLS elements
//  (NUMBER_WHITE_BALLS must be predefined)
//
// PostCondition: winningAmount will be displayed to user
//***************************************************************************

void displayWinnings(int winningAmount, int playerNumbersWhite[],
                     int playerNumberRed, int winningNumbersWhite[],
                     int winningNumberRed) {
    
    cout << "\nThe numbers you entered are: " << endl;
    for (int i = 0; i < NUMBER_WHITE_BALLS ; i++) {
        cout << playerNumbersWhite[i] << endl;
    }
    cout << endl << playerNumberRed << endl << endl;
    
    
    cout << "The winning numbers are: " << endl;
    for (int i = 0; i < NUMBER_WHITE_BALLS; i++) {
        cout << winningNumbersWhite[i] << endl;
    }
    
    cout << endl << winningNumberRed << endl;
    
    cout << "\n\nYou have won $" << winningAmount << endl << endl;
}
