 /****Complex.cpp****************************************************************
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


#include "Complex.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;


Complex::Complex(double valueA, double valueB) {
    numberA = valueA;
    numberB = valueB;
    
    if (numberB < 0)
        sign = '-';
    else
        sign = '+';
}

void Complex::display(ostream &out) const {
    if (numberA == 0 && numberB == 0) // form of 0
        out << 0;
    
    else if (numberA == 0) {          // form of bi, i, or -i
        if (abs(numberB) != 1)        // bi
            out << numberB;
        else if (numberB == -1)       // - i
            out << '-';
        
        out << 'i';             // imaginary symbol
    }
    
    else if (numberB == 0)            // form of a
        out << numberA;
    
    else if (numberB < 0) {           // form of a - bi or a - i
        out << numberA << " - ";
        
        if (numberB != -1)            // a - bi; numberB does not need to be
            out << abs(numberB);      // displayed if == -1 (a - i)
        
        out << 'i';             // imaginary symbol
        
    }
    else {                            // form of a + bi or a + i
        out << numberA << " + ";
        
        if (numberB != 1)      // numberB does not need to be displayed if == 1
            out << numberB;

        out << 'i';            // imaginary symbol
    }
}

void Complex::read(istream &in) {
    
    // set numberA and numberB to default values based on what user may not
    // actually enter (such as "1i") in order to simplify the extraction below
    numberA = 0;
    numberB = 1;
    
    // input of 'i'
    if (in.peek() == 'i')
        in.ignore();
    
    // input of "-i", "-n", or "-ni" where n is a valid double
    else if (in.peek() == '-') {
        in.ignore();           // ignore -
        
        // -n, -ni
        if (in.peek() != 'i') {

            in.unget();        // there's actually a number preceding i -
                               // put the - back
            
            in >> numberB;     // get the double before 'i'
            
            // -n
            if (in.peek() == '\n') {
                in.ignore();       // ignore \n
                numberA = numberB; // value should really go in numberA
                numberB = 0;
            } // end if
            
            // -ni
            else {
                in.ignore();   // ignore i
                in.ignore();   // ignore \n
            } // end else
        } // end if != 'i'
        
        // -i
        else {
            numberB = -1;      // since -i is really -1i
        
            in.ignore();       // ignore i
            in.ignore();       // ignore \n
        } // end else
    } // end else if
    
    // input of 0
    else if (in.peek() == '0') {
        numberB = 0;
        in.ignore();           // ignore 0
        in.ignore();           // ignore \n
    }
    
    // all other input types
    else {
        in >> numberA;         // first input must be a digit
        
        // input of 'n' where 'n' is a valid double
        if (in.peek() == '\n') {
            in.ignore();       // ignore \n
            numberB = 0;
        } // end if '\n'
        
        // input of "ni" where 'n' is a valid double
        else if (in.peek() == 'i') {
            numberB = numberA; // input should go in numberB because it can be
                               // assumed that numberA == 0 since i appeared
                               // after inserting 1 double in the input stream
            
            numberA = 0;       // follow through on assumption
            
            in.ignore();       // ignore i
            in.ignore();       // ignore \n
        } // end if 'i'
        
        // numberA and numberB both do not == 0
        else {
            
            in >> sign;
            
            // input of "n + ki" or "n - ki" where 'n' and 'k' are valid doubles
            if (in.peek() != 'i') {
                in >> numberB;
                
                if (sign == '-')
                    numberB *= -1;
            } // end if 'i'
            
            // input of "n + i" or "n - i" where 'n' is a valid double
            else
                if (sign == '-')
                    numberB = -1;
            
            in.ignore();        // ignore i
            in.ignore();        // ignore \n
        } // end else
    } // end else
    
} // end read

ostream &operator<<(ostream &out, const Complex &number) {
    number.display(out);
    return out;
}

istream &operator>>(istream &in, Complex &number) {
    number.read(in);
    return in;
}

Complex &operator+(const Complex &complex1, const Complex &complex2) {
    Complex complexFinal;
    
    // add the first part of the complex number
    complexFinal.setNumberA(complex1.getNumberA() + complex2.getNumberA());
    // add the second part of the complex number
    complexFinal.setNumberB(complex1.getNumberB() + complex2.getNumberB());
    
    // set complexFinal's sign to - if the sum of numberB is < 0
    if (complexFinal.getNumberB() < 0)
        complexFinal.setSign('-');
    
    return complexFinal;
}

Complex &operator-(const Complex &complex1, const Complex &complex2) {
    Complex complexFinal;
    
    // subtract the first part of the complex number
    complexFinal.setNumberA(complex1.getNumberA() - complex2.getNumberA());
    // subtract the second part of the complex number
    complexFinal.setNumberB(complex1.getNumberB() - complex2.getNumberB());
    
    // set complexFinal's sign to - if the difference of numberB is < 0
    if (complexFinal.getNumberB() < 0)
        complexFinal.setSign('-');
    
    return complexFinal;

}

Complex &operator*(const Complex &complex1, const Complex &complex2) {
    Complex complexFinal;
    
    // multiply the first part of the complex number
    complexFinal.setNumberA(complex1.getNumberA() * complex2.getNumberA() -
                            complex1.getNumberB() * complex2.getNumberB());
    // multiply the second part of the complex number
    complexFinal.setNumberB(complex1.getNumberB() * complex2.getNumberA() +
                            complex1.getNumberA() * complex2.getNumberB());
    
    // set complexFinal's sign to - if the final number for numberB < 0
    if (complexFinal.getNumberB() < 0)
        complexFinal.setSign('-');
    
    return complexFinal;
}

Complex &operator/(const Complex &complex1, const Complex &complex2) {
    Complex complexFinal;
    
    // divide the first part of the complex number
    complexFinal.setNumberA((complex1.getNumberA() * complex2.getNumberA() +
                             complex1.getNumberB() * complex2.getNumberB()) /
                            (complex2.getNumberA() * complex2.getNumberA() +
                             complex2.getNumberB() * complex2.getNumberB()));
    
    // divide the second part of the complex number
    complexFinal.setNumberB((complex1.getNumberB() * complex2.getNumberA() -
                             complex1.getNumberA() * complex2.getNumberB()) /
                            (complex2.getNumberA() * complex2.getNumberA() +
                             complex2.getNumberB() * complex2.getNumberB()));
    
    // set complexFinal's sign to - if the final number for numberB < 0
    if (complexFinal.getNumberB() < 0)
        complexFinal.setSign('-');
    
    return complexFinal;
}

bool operator==(const Complex &complex1, const Complex &complex2) {
    // compare numberA and numberB of operands for equality
    if (complex1.getNumberA() == complex2.getNumberA() && complex1.getNumberB()
        == complex2.getNumberB())
        return true;
    else
        return false;
}

double abs(const Complex &number) {
    return sqrt(number.getNumberA() * number.getNumberA() + number.getNumberB()
                * number.getNumberB());
}
