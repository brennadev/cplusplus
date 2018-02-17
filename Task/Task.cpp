/***Task.cpp**********************************************************************
 Programmer: Brenna Olson
 Description: Sort a file of Task objects by type and then jobId
 Operations:
 Function members:
 Task (constructor): Initialize Task object that only needs CPU
 Task (constructor): Initialize Task object that needs CPU and disk space
 Task (constructor): Initialize Task object that needs CPU and I/O
 devices
 getJobId: Get Task object's job id
 getType: Get Task object's type
 display: Put contents of Task object into output stream
 read: Put contents of Task object into input stream
 
 Other functions:
 operator<<: Put contents of Task object into output stream
 operator>>: Put contents of Task object into input stream
 operator<: Determine if task1's jobId is < task2's jobId
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#include "Task.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Task::display(ostream &out) const {
    
    out << ' ' << jobId;
        
    
    if (type == 2) {
        out <<  "   "
            << setw(6) << spaceAmount << "   "
            << setw(10) << drive;
    }
    
    else if (type == 3) {
        out << "   "
        << setw(8) << deviceDesignator << "   "
        << setw(14) << printerName;
    }
}


void Task::read(istream &in) {
    // each line of input will have an integer 1, 2, or 3 before it, indicating
    // the type of task
    in >> type >> jobId;
    
    if (type == 2)
        in >> spaceAmount >> drive;
    else if (type == 3)
        in >> deviceDesignator >> printerName;
}


ostream &operator<<(ostream &out, const Task &c) {
    c.display(out);
    return out;
}


istream &operator>>(istream &in, Task &c) {
    c.read(in);
    return in;
}


bool operator<(const Task &task1, const Task &task2) {
    return (task1.getJobId() < task2.getJobId());
}
