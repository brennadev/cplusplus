/*****LinkedList.cpp************************************************************
 
 Programmer: Brenna Olson
 Description: Class for singly-linked lists
 Operations:
    LinkedList methods:
        LinkedList: Create an empty LinkedList object
        display: Display linked list's contents on screen
        insert: Insert item (dataValue) into linked list at specified index
 
    Other functions:
        operator<<: Insert LinkedList's contents into output stream
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList() {
    first = NULL;
    mySize = 0;
}


void LinkedList::display(ostream &out) {
    LinkedList::NodePointer cur = first;
    
    for (int i = 0; i < mySize; i++) {
        cout << cur->data << endl;
        cur = cur->next;
    }
}


void LinkedList::insert(int index, ElementType dataValue) {
    // only modify list if index is valid
    if (index <= mySize && index >= 0) {
        
        NodePointer nPtr = new(nothrow) Node(dataValue);
        
        // insert at beginning of list
        if (index == 0) {
            nPtr->next = first;
            first = nPtr;
        }
        // insert elsewhere in list
        else {
            NodePointer predPtr = first;
            // iterate through list until reaching index - 1
            for (int i = 1; i < index; i++)
                predPtr = predPtr->next;
            
            // connect node into list
            nPtr->next = predPtr->next;
            predPtr->next = nPtr;
        }
        
        mySize++;
    }
    else
        cout << "Invalid index entered - no changes made to list" << endl;
}


ostream &operator<<(ostream &out, LinkedList &list) {
    list.display(out);
    return out;
}
