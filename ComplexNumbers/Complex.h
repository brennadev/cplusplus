/****Complex.h******************************************************************
 
 Programmer: Brenna Olson
 Description: Perform operations on complex numbers of the form a + bi, where i
              is an imaginary number
 
 Operations:
    Function members:
        Complex(valueA, valueB): Explicit-value constructor
        getNumberA: Value of numberA
        getNumberB: Value of numberB
        setNumberA: Set value of numberA
        setNumberB: Set value of numberB
        setSign: Set value of sign
        display: Insert contents of Complex object into output stream
        read: Put user-inputted value for Complex object in input stream
 
        
    Other functions:
        << (overload): Insert contents of Complex object into output stream
        >> (overload): Insert contents of Complex object into input stream
        + (overload): Add two Complex objects
        - (overload): Subtract two Complex objects
        * (overload): Multiply two Complex objects
        / (overload): Divide two Complex objects
        == (overload): Compare two Complex objects for equality
        abs: Get absolute value of a Complex object
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Complex {
public:
    
    //**************************************************************************
    // Function: Complex (explicit-value constructor)
    //
    // Purpose: Initialize numberA and numberB to user-specified values
    //
    // PreCondition: None
    //
    // PostCondition: numberA and numberB contains user-specified values;
    //                sign's value initialized based on numberB's value, and
    //                imaginary's value initialized to 'i'
    //**************************************************************************
    
    Complex(double valueA = 1, double valueB = 0);
    
    
    //**************************************************************************
    // Function: getNumberA
    //
    // Purpose: Get value of numberA
    //
    // PreCondition: None
    //
    // PostCondition: Value of numberA as a double returned
    //**************************************************************************
    
    double getNumberA() const {return numberA;}
    
    
    //**************************************************************************
    // Function: getNumberB
    //
    // Purpose: Get value of numberB
    //
    // PreCondition: None
    //
    // PostCondition: Value of numberB as a double returned
    //**************************************************************************
    
    double getNumberB() const {return numberB;}
    
    
    //**************************************************************************
    // Function: setNumberA
    //
    // Purpose: Set value of numberA
    //
    // PreCondition: number must be a valid double value
    //
    // PostCondition: Value in number parameter assigned to numberA
    //**************************************************************************
    
    void setNumberA(double number) {numberA = number;}
    
    
    //**************************************************************************
    // Function: setNumberB
    //
    // Purpose: Set value of numberB
    //
    // PreCondition: number must be a valid double value
    //
    // PostCondition: Value in number parameter assigned to numberB
    //**************************************************************************
    
    void setNumberB(double number) {numberB = number;}
    
    
    //**************************************************************************
    // Function: setSign
    //
    // Purpose: Set value of sign
    //
    // PreCondition: newSign must be a char value of '+' or '-'
    //
    // PostCondition: Value in newSign parameter assigned to sign
    //**************************************************************************
    
    void setSign(char newSign) {sign = newSign;}
    
    
    //**************************************************************************
    // Function: display
    //
    // Purpose: Insert contents of Complex object into output stream
    //
    // PreCondition: None
    //
    // PostCondition: Contents of Complex object in output stream
    //**************************************************************************
    
    void display(ostream &out) const;
    
    
    //**************************************************************************
    // Function: read
    //
    // Purpose: Put user-inputted value for Complex object in input stream
    //
    // PreCondition: None
    //
    // PostCondition: Contents of Complex object in input stream
    //**************************************************************************
    
    void read(istream &in);
    
  
    
private:
    double numberA,     // part without i
        numberB;     // part with i
    char sign;       // + or - for input
};


//******************************************************************************
// Function: << (overload)
//
// Purpose: Insert contents of Complex object into output stream
//
// PreCondition: None
//
// PostCondition: Contents of Complex object in output stream
//******************************************************************************

ostream &operator<<(ostream &out, const Complex &number);


//******************************************************************************
// Function: >> (overload)
//
// Purpose: Insert contents of Complex object into input stream
//
// PreCondition: None
//
// PostCondition: Contents of Complex object in input stream
//******************************************************************************


istream &operator>>(istream &in, Complex &number);


//******************************************************************************
// Function: + (overload)
//
// Purpose: Add two Complex objects
//
// PreCondition: None
//
// PostCondition: Sum of Complex objects returned
//******************************************************************************

Complex &operator+(const Complex &complex1, const Complex &complex2);


//******************************************************************************
// Function: - (overload)
//
// Purpose: Subtract two Complex objects
//
// PreCondition: None
//
// PostCondition: Difference of Complex objects returned
//******************************************************************************

Complex &operator-(const Complex &complex1, const Complex &complex2);


//******************************************************************************
// Function: * (overload)
//
// Purpose: Multiply two Complex objects
//
// PreCondition: None
//
// PostCondition: Product of Complex objects returned
//******************************************************************************

Complex &operator*(const Complex &complex1, const Complex &complex2);


//******************************************************************************
// Function: / (overload)
//
// Purpose: Divide two Complex objects
//
// PreCondition: None
//
// PostCondition: Quotient of Complex objects returned
//******************************************************************************

Complex &operator/(const Complex &complex1, const Complex &complex2);

//******************************************************************************
// Function: == (overload)
//
// Purpose: Compare two Complex objects for equality
//
// PreCondition: None
//
// PostCondition: true returned if ==; otherwise, false returned
//******************************************************************************

bool operator==(const Complex &complex1, const Complex &complex2);

//******************************************************************************
// Function: abs
//
// Purpose: Get the absolute value of a Complex object
//
// PreCondition: None
//
// PostCondition: Absolute value of Complex object as double returned
//******************************************************************************

double abs(const Complex &number);

#endif
