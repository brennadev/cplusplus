/******postfixExpression.cpp****************************************************
 Programmer: Brenna Olson
 Description: Evaluate a numeric expression in postfix format
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int evaluateExpression(Stack &operands, const string &expression);
void error();

int main() {

    Stack myOperands;
    string myExpression;
    
    // comment out later expressions to test earlier ones
    myExpression = "8 2 4 2 / * +";
    myExpression = "3 +";
    myExpression = "4 5 - 8 2 5 - + *";
    myExpression = "2 3 + +";
    
    
    cout << "Expression: " << myExpression << endl << endl;
    evaluateExpression(myOperands, myExpression);
    
    return 0;
}


//******************************************************************************
// Function: evaluateExpression
//
// Purpose: Evaluate the final value of an expression in postfix notation
//
// PreCondition: operands must be empty, expression must be initialized
//
// PostCondition: Final value of expression returned assuming correct form
//******************************************************************************

int evaluateExpression(Stack &operands, const string &expression) {
    
    for (int i = 0; i < expression.length(); i++) {
        if (!isspace(expression.at(i))) {
            cout << "Token = " << expression.at(i) << "        ";
            
            // current token is operand
            if (isnumber(expression.at(i))) {
                operands.push(static_cast<int>(expression.at(i) - '0'));
                cout << " Push " << expression.at(i) << endl;
            }
            
            // current token is operator
            else {
                int operand1,
                    operand2;
                char myOperator = expression.at(i);
                
                // make sure there are valid operands first
                if (!operands.empty()) {
                    operand1 = operands.top();
                    cout << " Pop " << operands.top() << "        ";
                    operands.pop();
                    
                    // must check twice in case stack contains 1 element
                    if (!operands.empty()) {
                        operand2 = operands.top();
                        cout << " Pop " << operands.top() << "        ";
                        operands.pop();
                    } // end inside if
                    
                    else
                        error();
                    
                    
                    // evaluate expression
                    if (myOperator == '+')
                        operands.push(operand2 + operand1);
                    else if (myOperator == '-')
                        operands.push(operand2 - operand1);
                    else if (myOperator == '*')
                        operands.push(operand2 * operand1);
                    else
                        operands.push(operand2 / operand1);
                    
                    cout << " Push " << operands.top() << endl;
                } // end outside if
                
                else
                    error();
                
            } // end operator else
        } // end !isspace if
    } // end for
    
    
    // check to make sure there is only 1 value in stack
    
    // top will get popped, so value must be stored somewhere
    int myTop = operands.top();
    cout << "Token:           ";
    // pop value in order to check if stack still has other values
    cout << " Pop " << operands.top() << "        " << endl << endl;
    operands.pop();
    
    // if stack is not empty, something went wrong
    if (!operands.empty())
        error();
    
    cout << endl << "Final value: " << myTop << endl << endl;
    
    return myTop;
}


//******************************************************************************
// Function: error
//
// Purpose: Display error message and exit program if expression is malformed
//
// PreCondition: None
//
// PostCondition: Error message displayed, program exited
//******************************************************************************

void error() {
    cerr << "\n\nMalformed expression - terminating" << endl;
    exit(1107);
}
