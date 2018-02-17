/*--- rocktester.cpp ----------------------------------------------------
 
 Programmer: Brenna Olson
 Description: A program for testing type Rock.
 ----------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Rock.h"
using namespace std;

void incrementRockCount(int rockCount[], Rock rockVal);
void displayBarGraph(int rockCount[]);

int main() {
    Rock currentRock;
    int count[10] = {0};
    
    ifstream infile;
    infile.open("Rockfile.txt");
    
    while (infile >> currentRock)
        incrementRockCount(count, currentRock);
    
    displayBarGraph(count);
    
    
  cout << "\n=============================================\n"
          "    PART 0:  Testing placement of enumeration"
          "\n=============================================\n";
  cout << GRANITE << endl;


  cout << "\n=======================================\n"
          "    PART 2:  Testing the constructor(s)"
          "\n=======================================\n";
  Rock sample,
       rockVal(GRANITE);



  cout << "\n===========================================\n"
          "    PART 3:  Testing function member display()"
          "\n===========================================\n";
  cout << "Value of\n"
       << "  sample is....";
  sample.display(cout);
  cout << endl;
  cout << "  rockVal is...";
  rockVal.display(cout);
  cout << endl;


  cout << "\n========================================\n"
          "    PART 4:  Testing the output operator"
          "\n========================================\n";
  cout << "Value of\n"
       << "  sample is...." << sample << endl
       << "  rockVal is..." << rockVal << endl;


  cout << "\n=========================================\n"
           "     PART 5:  Testing the input operator"
           "\n=========================================\n";

  cout << "Enter two rock names: ";
  cin >> sample >> rockVal;
  cout << "First rock is...." << sample << endl
       << "Second rock is..." << rockVal << endl;


  cout << "\n=============================================\n"
          "     PART 6:  Testing the rock-kind operator"
          "\n=============================================\n";

  char response;
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Kind of " << sample << " is " << sample.kind() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');


  cout << "\n================================================\n"
          "     PART 7:  Testing the rock-texture operator"
          "\n================================================\n";
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Texture of " << sample << " is " << sample.texture() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');

    cout << "\nPart 8:\n";
    
    do {
        cout << "Enter a rock name: ";
        cin >> sample;
        
        cout << "Name of sample is " << sample.name() << endl;
        
        cout << "More rocks (Y or N)? ";
        cin >> response;
    } while (response == 'Y' || response == 'y');


  cout << "\n=====================================================\n"
          "     PART 9:  Testing == and < with two Rock objects"
          "\n=====================================================\n";

  Rock rock1(GRANITE),
       rock2(MARBLE),
       rock3(MARBLE);

  cout << "rock1 = " << rock1 << "  rock2 = " << rock2
       << "  rock3 = " << rock3 << endl;
  cout << boolalpha;                                                            
  cout << "rock1 < rock2? " << (rock1 < rock2) << endl;                         
  cout << "rock1 == rock2? " << (rock1 == rock2) << endl;
  cout << "rock2 < rock3? " << (rock2 < rock3) << endl;                        
  cout << "rock2 == rock3? " << (rock2 == rock3) << endl;


  cout << "\n============================================================\n"
          "     PART 10:  Testing == and < with a Rock and a RockName"
          "\n============================================================\n";

  cout << "rock1 = " << rock1 << endl;
  cout << "rock1 < MARBLE? " << (rock1 < MARBLE ? "Yes" : "No")  << endl;
  cout << "rock1 == GRANITE? " << (rock1 == GRANITE ? "Yes" : "No")  << endl;
     
}


//***************************************************************************
// Function: incrementRockCount
//
// Purpose: Increment the appropriate element of an array containing a tally
//          of Rock values
//
// PreCondition: - rockCount[] must contain the number of integer enumerators as
//                 the RockName type
//               - rockCount must be initialized
//
// PostCondition: rockCount[rockVal.name()] will be incremented by 1
//***************************************************************************

void incrementRockCount(int rockCount[], Rock rockVal) {
    rockCount[rockVal.name()]++;
}


//***************************************************************************
// Function: displayBarGraph
//
// Purpose: Display tally of Rock values in an array as a bar graph
//
// PreCondition: rockCount must be initialized and contain the number of
//               enumerators of the Rock type
//
// PostCondition: Bar graph of Rock values tally displayed on screen
//***************************************************************************

void displayBarGraph(int rockCount[]) {
    
    cout << "Postfix operator:\n\n";
    cout << "Appearance of Each Rock Type" << endl;
    cout << "----------------------------" << endl;
    
    for (Rock i = BASALT; i < ROCK_OVERFLOW; i++) {
        cout << setw(9) << i << " :";
        for (int j = 0; j < rockCount[i.name()]; j++) {
            cout << 'X';
        }
        
        cout << " (" << rockCount[i.name()] << ')' << endl;
    }
    
    
    cout << "\n\n\nPrefix operator:\n\n";
    
    cout << "Appearance of Each Rock Type" << endl;
    cout << "----------------------------" << endl;
    
    for (Rock i = BASALT; i < ROCK_OVERFLOW; ++i) {
        cout << setw(9) << i << " :";
        for (int j = 0; j < rockCount[i.name()]; j++) {
            cout << 'X';
        }
        
        cout << " (" << rockCount[i.name()] << ')' << endl;
    }
}

