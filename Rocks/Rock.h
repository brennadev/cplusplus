/***Rock.h**********************************************************************
 Programmer: Brenna Olson
 Description: Create and perform operations on various types of rocks
Operations:
 
    Function members:
        Rock(): Default constructor
        Rock(RockName): Explicit-value constructor
        display: Puts myName in output stream
        read: Puts user-inputted value for myName in input stream
        kind: Obtain the kind of a Rock - igneous, metamorphic, or sedimentary -
              from myName
        texture: Obtain the texture of a Rock - coarse, intermediate, or fine -
                 from myName
        name: Get value of Rock's name
        nextOne: Find the successor of a Rock value
        ++ (overload): Find the successor of a Rock value
 
    Other functions:
        displayRockName: Insert contents of current RockName into output stream
        << (overload) for type Rock: Insert contents of current Rock's myName
                                     into output stream
        << (overload) for type RockName: Insert contents of current RockName
                                         value into output stream
        >> (overload): Insert contents of current Rock's myName
                       into input stream
        < (overload): Determine if Rock object rock1 < Rock object rock2
        == (overload): Determine if Rock object rock1 == Rock object rock2
        stringToUpper: Convert string to all uppercase letters
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#ifndef ROCK_H
#define ROCK_H

#include <iostream>
#include <string>
using namespace std;

enum RockName {BASALT, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE,
                   OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW};
class Rock {
public:
    
    //**************************************************************************
    // Function: Rock (default constructor)
    //
    // Purpose: Initialize Rock's name to ROCK_OVERFLOW
    //
    // PreCondition: None
    //
    // PostCondition: Rock's name will contain ROCK_OVERFLOW
    //**************************************************************************
    
    Rock();
    
    
    //**************************************************************************
    // Function: Rock (explicit-value constructor)
    //
    // Purpose: Initialize name to value in object declaration
    //
    // PreCondition: None
    //
    // PostCondition: name will contain value in object's declaration
    //**************************************************************************
    
    Rock(RockName name);
    
    
    //**************************************************************************
    // Function: display
    //
    // Purpose: Puts myName in output stream
    //
    // PreCondition: None
    //
    // PostCondition: myName added to output stream
    //**************************************************************************
    
    void display(ostream &out) const;
    
    
    //**************************************************************************
    // Function: read
    //
    // Purpose: Puts user-inputted value for myName in input stream
    //
    // PreCondition: None
    //
    // PostCondition: myName added to input stream
    //**************************************************************************
    
    void read(istream &in);
    
    
    //**************************************************************************
    // Function: kind
    //
    // Purpose: Obtain the kind of a Rock - igneous, metamorphic, or sedimentary
    //          - from myName
    //
    // PreCondition: None
    //
    // PostCondition: string value of rock kind returned
    //**************************************************************************
    
    string kind();
    
    
    //**************************************************************************
    // Function: texture
    //
    // Purpose: Obtain the texture of a Rock - coarse, intermediate, or fine -
    //          from myName
    //
    // PreCondition: None
    //
    // PostCondition: string value of rock texture returned
    //**************************************************************************
    
    string texture();
    
    
    //**************************************************************************
    // Function: name
    //
    // Purpose: Get value of Rock's name
    //
    // PreCondition: None
    //
    // PostCondition: RockName value of Rock's name returned
    //**************************************************************************
    
    RockName name() const;
    
    
    //**************************************************************************
    // Function: nextOne
    //
    // Purpose: Find the successor of a Rock value
    //
    // PreCondition: None
    //
    // PostCondition: The successor of myName has been returned (the successor
    //                of SHALE is ROCK_OVERFLOW, and ROCK_OVERFLOW is its own
    //                successor)
    //**************************************************************************
    
    RockName nextOne();
    
    
    //**************************************************************************
    // Function: ++ (overload)
    //
    // Purpose: Find the successor of a Rock value
    //
    // PreCondition: None
    //
    // PostCondition: The successor of myName has been returned (the successor
    //                of SHALE is ROCK_OVERFLOW, and ROCK_OVERFLOW is its own
    //                successor)
    //**************************************************************************
    
    int operator++();
    
    int operator++(int);
    
private:
    RockName myName;
};


//******************************************************************************
// Function: displayRockName
//
// Purpose: Insert contents of current RockName into output stream
//
// PreCondition: rockVal is a valid RockName value
//
// PostCondition: String of current RockName has been inserted into output
//                stream
//******************************************************************************

void displayRockName(ostream &out, RockName rockVal);


//******************************************************************************
// Function: << (overload) for type Rock
//
// Purpose: Insert contents of current Rock's myName into output stream
//
// PreCondition: rockVal is a valid Rock value
//
// PostCondition: String of current Rock's myName has been inserted into output
//                stream
//******************************************************************************

ostream &operator<<(ostream &out, const Rock &rockVal);


//******************************************************************************
// Function: << (overload) for type RockName
//
// Purpose: Insert contents of current RockName value into output stream
//
// PreCondition: rockVal is a valid RockName value
//
// PostCondition: String of current RockName value has been inserted into output
//                stream
//******************************************************************************

ostream &operator<<(ostream &out, const RockName &rockVal);


//******************************************************************************
// Function: >> (overload) for type Rock
//
// Purpose: Insert contents of current Rock's myName into input stream
//
// PreCondition: rockVal is a valid Rock value
//
// PostCondition: String of current Rock's myName has been inserted into input
//                stream
//******************************************************************************

istream &operator>>(istream &in, Rock &rockVal);


//******************************************************************************
// Function: < (overload)
//
// Purpose: Determine if Rock object rock1 < Rock object rock2
//
// PreCondition: rock1 and rock2 are valid Rock values
//
// PostCondition: true returned if <; otherwise, false returned
//******************************************************************************

bool operator<(const Rock &rock1, const Rock &rock2);


//******************************************************************************
// Function: == (overload)
//
// Purpose: Determine if Rock object rock1 == Rock object rock2
//
// PreCondition: rock1 and rock2 are valid Rock values
//
// PostCondition: true returned if ==; otherwise, false returned
//******************************************************************************

bool operator==(const Rock &rock1, const Rock &rock2);


//******************************************************************************
// Function: stringToUpper
//
// Purpose: Convert string to all uppercase letters
//
// PreCondition: myString is initialized
//
// PostCondition: myString contains all uppercase version of original string
//******************************************************************************

void stringToUpper(string &myString);

#endif
