/*****LinkedList.cpp************************************************************
 
 Programmer: Brenna Olson
 Description: Class for singly-linked lists
 Operations:
    LinkedList methods:
        LinkedList: Create an empty LinkedList object
        size: Get size of linked list
        display: Display linked list's contents on screen
        insert: Insert item (dataValue) into linked list at specified index
 
    Node methods:
        Node() (inside Node class): Initialize Node object
    
    Other functions:
        operator<<: Insert LinkedList's contents into output stream
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

class LinkedList {
public:
    
    /* --- LinkedList constructor --------------------------------------
     Constructs an empty LinkedList object.
     
     Precondition:  None.
     Postcondition: This list's data members have been initialized
     for an empty list.
     ---------------------------------------------------------------------*/
    
    LinkedList();
    

    //**************************************************************************
    // Function: size
    //
    // Purpose: Get size of linked list
    //
    // PreCondition: None
    //
    // PostCondition: List size returned
    //**************************************************************************
    
    int size() const {
        return mySize;
    }
    
    
    //**************************************************************************
    // Function: display
    //
    // Purpose: Display linked list's contents on screen
    //
    // PreCondition: Linked list should not be empty
    //
    // PostCondition: Linked list's contents displayed on screen
    //**************************************************************************
    
    void display(ostream &out);
    
    
    //**************************************************************************
    // Function: insert
    //
    // Purpose: Insert item (dataValue) into linked list at specified index
    //
    // PreCondition: index must be >= 0 and <= size(); dataValue must be of type
    //               ElementType
    //
    // PostCondition: dataValue has been inserted into linked list at specified
    //                index
    //**************************************************************************
    
    void insert(int index, ElementType dataValue);
    
    
private:
    
    class Node {
    public:
        
        ElementType data;
        Node *next;
        
        
        /* --- The Node class constructor initializes a Node's data members.
         
         Precondition:  None
         Receive:       dataValue, an ElementType value;
         Postcondition: The data and next members have been set to
         dataValue and NULL, respectively.
         -------------------------------------------------------------------*/
        
        Node(ElementType dataValue) {
            data = dataValue;
            next = NULL;
        }
        
    }; //end Node class
    
    typedef Node * NodePointer;
    
    NodePointer first;
    int mySize;
    
}; // end LinkedList class


//******************************************************************************
// Function: operator<<
//
// Purpose: Insert LinkedList's contents into output stream
//
// PreCondition: size() > 0
//
// PostCondition: list's contents inserted into output stream
//******************************************************************************

ostream &operator<<(ostream &out, LinkedList &list);

#endif
