/***Rock.cpp********************************************************************
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

#include "Rock.h"
#include <iostream>
#include <string>
using namespace std;

Rock::Rock() {
    //cout << "rock constructor" << endl;
    myName = ROCK_OVERFLOW;
}

Rock::Rock(RockName name) {
    //cout << "rock constructor" << endl;
    myName = name;
}

void Rock::display(ostream &out) const {
    switch (myName) {
        case BASALT:
            out << "BASALT";
            break;
            
        case DOLOMITE:
            out << "DOLOMITE";
            break;
            
        case GRANITE:
            out << "GRANITE";
            break;
            
        case GYPSUM:
            out << "GYPSUM";
            break;
            
        case LIMESTONE:
            out << "LIMESTONE";
            break;
            
        case MARBLE:
            out << "MARBLE";
            break;
            
        case OBSIDIAN:
            out << "OBSIDIAN";
            break;
            
        case QUARTZITE:
            out << "QUARTZITE";
            break;
            
        case SANDSTONE:
            out << "SANDSTONE";
            break;
            
        case SHALE:
            out << "SHALE";
            break;
            
        default:
            out << "Invalid input";
            break;
    }

}



void Rock::read(istream &in) {
    
    string rockEntered;
    in >> rockEntered;
    
    stringToUpper(rockEntered);
    
    if (rockEntered == "BASALT")
        myName = BASALT;
    
    else if (rockEntered == "DOLOMITE")
        myName = DOLOMITE;
    
    else if (rockEntered == "GRANITE")
        myName = GRANITE;
    
    else if (rockEntered == "GYPSUM")
        myName = GYPSUM;
    
    else if (rockEntered == "LIMESTONE")
        myName = LIMESTONE;
    
    else if (rockEntered == "MARBLE")
        myName = MARBLE;
    
    else if (rockEntered == "OBSIDIAN")
        myName = OBSIDIAN;
    
    else if (rockEntered == "QUARTZITE")
        myName = QUARTZITE;
    
    else if (rockEntered == "SANDSTONE")
        myName = SANDSTONE;
    
    else if (rockEntered == "SHALE")
        myName = SHALE;
    
    else
        myName = ROCK_OVERFLOW;
}

string Rock::kind() {
    switch (myName) {
        case BASALT:
        case GRANITE:
        case OBSIDIAN:
            return "igneous";
            
        case MARBLE:
        case QUARTZITE:
            return "metamorphic";
            
        case DOLOMITE:
        case LIMESTONE:
        case GYPSUM:
        case SANDSTONE:
        case SHALE:
            return "sedimentary";
        default:
            return "invalid input";
    }
}

string Rock::texture() {
    switch (myName) {
        case DOLOMITE:
        case GRANITE:
        case GYPSUM:
        case LIMESTONE:
        case SANDSTONE:
            return "coarse";

        case BASALT:
        case QUARTZITE:
            return "intermediate";
            
        case OBSIDIAN:
        case MARBLE:
        case SHALE:
            return "fine";
            
        default:
            return "invalid input";
    }
}

RockName Rock::name() const {
    return myName;
}

RockName Rock::nextOne() {
    switch (myName) {
        case BASALT:
            return DOLOMITE;
            
        case DOLOMITE:
            return GRANITE;
            
        case GRANITE:
            return GYPSUM;
            
        case GYPSUM:
            return LIMESTONE;
            
        case LIMESTONE:
            return MARBLE;
            
        case MARBLE:
            return OBSIDIAN;
            
        case OBSIDIAN:
            return QUARTZITE;
            
        case QUARTZITE:
            return SANDSTONE;
            
        case SANDSTONE:
            return SHALE;
            
        case SHALE:
            return ROCK_OVERFLOW;
            
        default:
            cout << "Outside range of Rock values" << endl;
            return ROCK_OVERFLOW;
    }

}

int Rock::operator++() {
    myName = nextOne();
    return myName;
}

int Rock::operator++(int) {
    myName = nextOne();
    return myName;
}

void displayRockName(ostream &out, RockName rockVal) {
    switch (rockVal) {
        case BASALT:
            out << "BASALT";
            break;
            
        case DOLOMITE:
            out << "DOLOMITE";
            break;
            
        case GRANITE:
            out << "GRANITE";
            break;
            
        case GYPSUM:
            out << "GYPSUM";
            break;
            
        case LIMESTONE:
            out << "LIMESTONE";
            break;
            
        case MARBLE:
            out << "MARBLE";
            break;
            
        case OBSIDIAN:
            out << "OBSIDIAN";
            break;
            
        case QUARTZITE:
            out << "QUARTZITE";
            break;
            
        case SANDSTONE:
            out << "SANDSTONE";
            break;
            
        case SHALE:
            out << "SHALE";
            break;
            
        default:
            out << "Invalid input";
            break;
    }
}

ostream &operator<<(ostream &out, const Rock &rockVal) {
    rockVal.display(out);
    return out;
}

ostream &operator<<(ostream &out, const RockName &rockVal) {
    displayRockName(out, rockVal);
    return out;
}

istream &operator>>(istream &in, Rock &rockVal) {
    rockVal.read(in);
    return in;
}

bool operator<(const Rock &rock1, const Rock &rock2) {
    if (rock1.name() < rock2.name())
        return true;
    else
        return false;
}

bool operator==(const Rock &rock1, const Rock &rock2) {
    if (rock1.name() == rock2.name())
        return true;
    else
        return false;
}

void stringToUpper(string &myString) {
    for (int i = 0; i < myString.length(); i++)
        myString.at(i) = toupper(myString.at(i));
}
